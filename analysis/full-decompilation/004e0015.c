
char FUN_004e0015(void)

{
  if ((DAT_006f222c == '\0') &&
     ((DAT_006f221c != (HMODULE)0x0 ||
      (DAT_006f221c = LoadLibraryA(s_PSAPI_DLL_006c8df4), DAT_006f221c != (HMODULE)0x0)))) {
    DAT_006f2220 = GetProcAddress(DAT_006f221c,s_QueryWorkingSet_006c8de4);
    DAT_006f2224 = GetProcAddress(DAT_006f221c,s_GetMappedFileNameA_006c8dd0);
    DAT_006f2228 = GetProcAddress(DAT_006f221c,s_GetProcessMemoryInfo_006c8db8);
    if ((DAT_006f221c != (HMODULE)0x0) &&
       (((DAT_006f2220 != (FARPROC)0x0 && (DAT_006f2224 != (FARPROC)0x0)) &&
        (DAT_006f2228 != (FARPROC)0x0)))) {
      DAT_006f222c = '\x01';
    }
  }
  return DAT_006f222c;
}

