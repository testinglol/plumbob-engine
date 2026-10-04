
int FUN_005be418(LPCSTR param_1,LPSTR param_2,int param_3)

{
  LPCSTR lpString1;
  int iVar1;
  FARPROC pFVar2;
  FARPROC pFVar3;
  undefined1 local_264 [44];
  undefined1 local_238;
  CHAR local_124 [264];
  LPWSTR local_1c;
  FARPROC local_18;
  HMODULE local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  lpString1 = (LPCSTR)FUN_006375b5(param_1,0x2e);
  local_10 = 0;
  if ((lpString1 != (LPCSTR)0x0) && (iVar1 = lstrcmpiA(lpString1,&DAT_006d25c0), iVar1 == 0)) {
    local_c = (int *)0x0;
    local_8 = (int *)0x0;
    local_238 = 0;
    local_124[0] = '\0';
    local_14 = LoadLibraryA(s_Ole32_dll_006d2830);
    if (local_14 != (HMODULE)0x0) {
      pFVar2 = GetProcAddress(local_14,s_CoInitialize_006d2820);
      local_18 = GetProcAddress(local_14,s_CoUninitialize_006d2810);
      pFVar3 = GetProcAddress(local_14,s_CoCreateInstance_006d27fc);
      if ((((pFVar2 != (FARPROC)0x0) && (local_18 != (FARPROC)0x0)) && (pFVar3 != (FARPROC)0x0)) &&
         (iVar1 = (*pFVar2)(0), -1 < iVar1)) {
        iVar1 = (*pFVar3)(&DAT_006891c8,0,1,&DAT_006891d8,&local_8);
        if (-1 < iVar1) {
          iVar1 = (**(code **)*local_8)(local_8,&DAT_006891b8,&local_c);
          if (-1 < iVar1) {
            iVar1 = lstrlenA(param_1);
            iVar1 = iVar1 + 1;
            local_1c = operator_new(iVar1 * 2);
            MultiByteToWideChar(0,1,param_1,iVar1,local_1c,iVar1);
            iVar1 = (**(code **)(*local_c + 0x14))(local_c,local_1c,0);
            if (((-1 < iVar1) && (iVar1 = (**(code **)(*local_8 + 0x4c))(local_8,0,1), -1 < iVar1))
               && (iVar1 = (**(code **)(*local_8 + 0xc))(local_8,local_124,0x105,local_264,0),
                  iVar1 == 0)) {
              local_10 = lstrlenA(local_124);
              local_10 = local_10 + 1;
              if (param_2 != (LPSTR)0x0) {
                lstrcpynA(param_2,local_124,param_3);
              }
            }
            (**(code **)(*local_c + 8))(local_c);
            local_c = (int *)0x0;
            FUN_006321f0(local_1c);
          }
          (**(code **)(*local_8 + 8))(local_8);
          local_8 = (int *)0x0;
        }
        (*local_18)();
      }
      FreeLibrary(local_14);
      if (local_10 != 0) {
        return local_10;
      }
    }
    local_10 = -1;
  }
  return local_10;
}

