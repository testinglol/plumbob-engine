import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.Reference;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.LinkedHashMap;
import java.util.Map;

public class ExportSimsRenderer extends GhidraScript {
    public void run() throws Exception {
        Path output = Path.of(getScriptArgs()[0]);
        Files.createDirectories(output);
        Map<Address, Function> functions = new LinkedHashMap<>();
        StringBuilder references = new StringBuilder("marker\tstring_address\treference_address\tfunction\n");
        String[] markers = {
            "DirectDrawCreate", "DirectDrawCreateEx", "DirectDrawEnumerateA",
            "r1024x768", "Adding control panel", "Adding main window",
            "SIMS_LANGUAGE", "SIMS_GAME_EDITION", "GameData/Scenario.tds",
            "DDRAW.DLL", "ddraw.dll"
        };
        for (String marker : markers) {
            Address start = currentProgram.getMinAddress();
            byte[] pattern = (marker + "\0").getBytes(StandardCharsets.US_ASCII);
            int matches = 0;
            while (start != null && matches++ < 20 && !monitor.isCancelled()) {
                Address found = currentProgram.getMemory().findBytes(start, pattern, null, true, monitor);
                if (found == null) break;
                for (Reference reference : currentProgram.getReferenceManager().getReferencesTo(found)) {
                    Function function = currentProgram.getFunctionManager().getFunctionContaining(reference.getFromAddress());
                    references.append(marker).append('\t').append(found).append('\t').append(reference.getFromAddress())
                        .append('\t').append(function == null ? "data" : function.getName()).append('\n');
                    if (function != null) functions.put(function.getEntryPoint(), function);
                }
                start = found.next();
            }
        }
        for (int argument = 1; argument < getScriptArgs().length; argument++) {
            if (getScriptArgs()[argument].equals("all")) {
                FunctionIterator iterator = currentProgram.getFunctionManager().getFunctions(true);
                while (iterator.hasNext()) {
                    Function function = iterator.next();
                    if (!function.isExternal() && !function.isThunk()) functions.put(function.getEntryPoint(), function);
                }
                continue;
            }
            Address display = toAddr(getScriptArgs()[argument]);
            Function function = currentProgram.getFunctionManager().getFunctionContaining(display);
            if (function != null) functions.put(function.getEntryPoint(), function);
        }
        Files.writeString(output.resolve("renderer-references.tsv"), references);
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        StringBuilder index = new StringBuilder("address\tname\tstatus\n");
        int exported = 0;
        for (Function function : functions.values()) {
            monitor.checkCancelled();
            DecompileResults result = decompiler.decompileFunction(function, 30, monitor);
            if (result.decompileCompleted()) {
                String filename = function.getEntryPoint() + ".c";
                Files.writeString(output.resolve(filename), result.getDecompiledFunction().getC());
                exported++;
                index.append(function.getEntryPoint()).append('\t').append(function.getName()).append("\tdecompiled\n");
                if (exported % 250 == 0) {
                    Files.writeString(output.resolve("functions.tsv"), index);
                    println("Decompiled " + exported + " / " + functions.size() + " functions");
                }
            } else {
                index.append(function.getEntryPoint()).append('\t').append(function.getName()).append("\tnot completed: ").append(result.getErrorMessage()).append('\n');
            }
        }
        decompiler.dispose();
        Files.writeString(output.resolve("functions.tsv"), index);
        println("Decompiled " + exported + " of " + functions.size() + " renderer and startup functions to " + output);
    }
}
