
FARPROC FUN_009d8dc0(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = LoadLibraryA("vulkan-1.dll");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"vkGetInstanceProcAddr");
    return pFVar1;
  }
  return (FARPROC)0x0;
}

