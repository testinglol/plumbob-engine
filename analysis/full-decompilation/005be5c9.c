
undefined1 FUN_005be5c9(int *param_1)

{
  int iVar1;
  FARPROC pFVar2;
  FARPROC pFVar3;
  undefined1 local_474 [44];
  undefined2 local_448;
  undefined2 local_224 [262];
  FARPROC local_18;
  HMODULE local_14;
  int *local_10;
  int *local_c;
  undefined1 local_5;
  
  iVar1 = FUN_005bfc9c(0x2e,DAT_00672b94);
  local_5 = 0;
  if (iVar1 != DAT_00672b94) {
    iVar1 = FUN_0064a65e(*param_1 + iVar1 * 2,u__lnk_006d283c);
    if (iVar1 == 0) {
      local_10 = (int *)0x0;
      local_c = (int *)0x0;
      local_448 = 0;
      local_224[0] = 0;
      local_14 = LoadLibraryA(s_Ole32_dll_006d2830);
      if (local_14 != (HMODULE)0x0) {
        pFVar2 = GetProcAddress(local_14,s_CoInitialize_006d2820);
        local_18 = GetProcAddress(local_14,s_CoUninitialize_006d2810);
        pFVar3 = GetProcAddress(local_14,s_CoCreateInstance_006d27fc);
        if (((pFVar2 != (FARPROC)0x0) && (local_18 != (FARPROC)0x0)) && (pFVar3 != (FARPROC)0x0)) {
          iVar1 = (*pFVar2)(0);
          if (-1 < iVar1) {
            iVar1 = (*pFVar3)(&DAT_006891c8,0,1,&DAT_006891e8,&local_c);
            if (-1 < iVar1) {
              iVar1 = (**(code **)*local_c)(local_c,&DAT_006891b8,&local_10);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_10 + 0x14))(local_10,*param_1,0);
                if (-1 < iVar1) {
                  iVar1 = (**(code **)(*local_c + 0x4c))(local_c,0,1);
                  if (-1 < iVar1) {
                    iVar1 = (**(code **)(*local_c + 0xc))(local_c,local_224,0x105,local_474,0);
                    if (iVar1 == 0) {
                      iVar1 = FUN_005bfb0f(local_224);
                      FUN_005bfc36(local_224,local_224 + iVar1);
                      local_5 = 1;
                    }
                  }
                }
                (**(code **)(*local_10 + 8))(local_10);
                local_10 = (int *)0x0;
              }
              (**(code **)(*local_c + 8))(local_c);
              local_c = (int *)0x0;
            }
            (*local_18)();
          }
        }
        FreeLibrary(local_14);
      }
    }
  }
  return local_5;
}

