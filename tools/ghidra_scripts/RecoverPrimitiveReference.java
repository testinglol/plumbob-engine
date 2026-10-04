import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.nio.file.Files;
import java.nio.file.Path;

public class RecoverPrimitiveReference extends GhidraScript {
    public void run() throws Exception {
        Path output = Path.of(getScriptArgs()[0]);
        Files.createDirectories(output);
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try {
            for (int index = 1; index < getScriptArgs().length; index++) {
                Address address = toAddr(getScriptArgs()[index]);
                Function function = getFunctionAt(address);
                if (function == null) {
                    if (getFunctionContaining(address) != null) throw new IllegalStateException("Reference is inside an existing function: " + address);
                    disassemble(address);
                    function = createFunction(address, "FUN_" + address);
                }
                if (function == null) throw new IllegalStateException("Cannot recover function: " + address);
                var result = decompiler.decompileFunction(function, 30, monitor);
                if (!result.decompileCompleted()) throw new IllegalStateException(result.getErrorMessage());
                Files.writeString(output.resolve(address + ".c"), result.getDecompiledFunction().getC());
                println("Recovered primitive reference " + address);
            }
        } finally { decompiler.dispose(); }
    }
}
