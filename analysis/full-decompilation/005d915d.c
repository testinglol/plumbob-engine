
undefined4 __fastcall FUN_005d915d(undefined4 param_1)

{
  DWORD DVar1;
  HMODULE hModule;
  
  DVar1 = GetVersion();
  if (((DVar1 < 0x80000000) || (4 < (byte)DVar1)) || ((char)(DVar1 >> 8) != '\0')) {
    hModule = LoadLibraryA(s_Kernel32_dll_006d2b5c);
    if (hModule != (HMODULE)0x0) {
      DAT_006fe8e0 = GetProcAddress(hModule,s_TryEnterCriticalSection_006d727c);
      if (DAT_006fe8e0 == (FARPROC)0x0) {
        FreeLibrary(hModule);
      }
    }
  }
  return param_1;
}

