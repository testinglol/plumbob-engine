
int FUN_0064844a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_00703d84 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_00703d84 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_00703d84 != (FARPROC)0x0) {
        DAT_00703d88 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_00703d8c = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_00648499;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_00648499:
    if (DAT_00703d88 != (FARPROC)0x0) {
      iVar1 = (*DAT_00703d88)();
      if ((iVar1 != 0) && (DAT_00703d8c != (FARPROC)0x0)) {
        iVar1 = (*DAT_00703d8c)(iVar1);
      }
    }
    iVar1 = (*DAT_00703d84)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}

