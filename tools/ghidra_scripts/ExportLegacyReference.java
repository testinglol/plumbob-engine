import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.LinkedHashMap;
import java.util.Map;

public class ExportLegacyReference extends GhidraScript {
    public void run() throws Exception {
        Path output = Path.of(getScriptArgs()[0]);
        Files.createDirectories(output);
        String[] markers = {
            "vulkan-1.dll", "vkCreateInstance", "vkCreateDevice", "vkCreateSwapchainKHR",
            "vkCmdDraw", "vkCmdDrawIndexed", "VariableSans_", "%d %d scale", "THE SIMS 1 LEGACY COLLECTION",
            "The game was unable to find a suitable Vulkan device on this machine. Please update your graphic card drivers and try again. More help: https://go.ea.com/sims-legacy"
        };
        Map<Address, Function> functions = new LinkedHashMap<>();
        StringBuilder references = new StringBuilder("marker\tstring_address\treference_address\tfunction\n");
        for (String marker : markers) {
            Address cursor = currentProgram.getMinAddress();
            byte[] pattern = (marker + "\0").getBytes(StandardCharsets.US_ASCII);
            for (int count = 0; count < 20 && cursor != null; count++) {
                monitor.checkCancelled();
                Address found = currentProgram.getMemory().findBytes(cursor, pattern, null, true, monitor);
                if (found == null) break;
                for (Reference reference : currentProgram.getReferenceManager().getReferencesTo(found)) {
                    Function function = currentProgram.getFunctionManager().getFunctionContaining(reference.getFromAddress());
                    references.append(marker).append('\t').append(found).append('\t').append(reference.getFromAddress())
                        .append('\t').append(function == null ? "data" : function.getName()).append('\n');
                    if (function != null && !function.isExternal()) functions.put(function.getEntryPoint(), function);
                }
                cursor = found.next();
            }
        }
        for (int index = 1; index < getScriptArgs().length; index++) {
            String argument = getScriptArgs()[index];
            Address address = toAddr(argument.startsWith("@") ? argument.substring(1) : argument);
            if (argument.startsWith("@")) {
                for (Reference reference : currentProgram.getReferenceManager().getReferencesTo(address)) {
                    Function function = currentProgram.getFunctionManager().getFunctionContaining(reference.getFromAddress());
                    references.append(argument).append('\t').append(address).append('\t').append(reference.getFromAddress())
                        .append('\t').append(function == null ? "data" : function.getName()).append('\n');
                    if (function != null && !function.isExternal()) functions.put(function.getEntryPoint(), function);
                }
            } else {
                Function function = currentProgram.getFunctionManager().getFunctionContaining(address);
                if (function != null) functions.put(function.getEntryPoint(), function);
            }
        }
        Files.writeString(output.resolve("references.tsv"), references);
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        StringBuilder index = new StringBuilder("address\tname\tstatus\n");
        try {
            for (Function function : functions.values()) {
                monitor.checkCancelled();
                DecompileResults result = decompiler.decompileFunction(function, 30, monitor);
                if (result.decompileCompleted()) {
                    Files.writeString(output.resolve(function.getEntryPoint() + ".c"), result.getDecompiledFunction().getC());
                }
                index.append(function.getEntryPoint()).append('\t').append(function.getName()).append('\t')
                    .append(result.decompileCompleted() ? "decompiled" : result.getErrorMessage()).append('\n');
            }
        } finally {
            decompiler.dispose();
        }
        Files.writeString(output.resolve("functions.tsv"), index);
        println("Exported " + functions.size() + " Legacy renderer and font reference functions");
    }
}
