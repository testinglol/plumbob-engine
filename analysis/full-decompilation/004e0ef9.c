
undefined4 FUN_004e0ef9(void)

{
  HMODULE hModule;
  HANDLE pvVar1;
  int iVar2;
  DWORD DVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  hModule = LoadLibraryA(s_IMAGEHLP_DLL_006c97a0);
  if (hModule == (HMODULE)0x0) {
    pcVar5 = s_Could_not_load_IMAGEHLP_DLL_006c9780;
  }
  else {
    DAT_006f233c = GetProcAddress(hModule,s_SymInitialize_006c9770);
    if (DAT_006f233c == (FARPROC)0x0) {
      pcVar5 = s_Could_not_loadproc__SymInitializ_006c974c;
    }
    else {
      DAT_006f2340 = GetProcAddress(hModule,s_SymCleanup_006c9740);
      if (DAT_006f2340 == (FARPROC)0x0) {
        pcVar5 = s_Could_not_loadproc__SymCleanup_006c971c;
      }
      else {
        DAT_006f2344 = GetProcAddress(hModule,s_StackWalk_006c9710);
        if (DAT_006f2344 == (FARPROC)0x0) {
          pcVar5 = s_Could_not_loadproc__StackWalk_006c96f0;
        }
        else {
          DAT_006f2348 = GetProcAddress(hModule,s_SymFunctionTableAccess_006c96d8);
          if (DAT_006f2348 == (FARPROC)0x0) {
            pcVar5 = s_Could_not_loadproc__SymFunctionT_006c96a8;
          }
          else {
            DAT_006f234c = GetProcAddress(hModule,s_SymGetModuleBase_006c9694);
            if (DAT_006f234c == (FARPROC)0x0) {
              pcVar5 = s_Could_not_loadproc__SymGetModule_006c966c;
            }
            else {
              DAT_006f2350 = GetProcAddress(hModule,s_SymGetSymFromAddr_006c9658);
              if (DAT_006f2350 == (FARPROC)0x0) {
                pcVar5 = s_Could_not_loadproc__SymGetSymFro_006c9630;
              }
              else {
                DAT_006f2354 = GetProcAddress(hModule,s_SymLoadModule_006c9620);
                uVar6 = 0;
                uVar4 = 0;
                pvVar1 = GetCurrentProcess();
                iVar2 = (*DAT_006f233c)(pvVar1,uVar4,uVar6);
                if (iVar2 != 0) {
                  DVar3 = GetCurrentProcessId();
                  pvVar1 = GetCurrentProcess();
                  FUN_004e0ffc(pvVar1,DVar3);
                  return 1;
                }
                pcVar5 = s__SymInitialize_failed__006c9604;
              }
            }
          }
        }
      }
    }
  }
  FUN_004e0eba(pcVar5);
  return 0;
}

