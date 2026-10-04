
int FUN_005be084(LPCSTR param_1,LPSTR param_2,int param_3)

{
  LPCSTR lpString1;
  int iVar1;
  HRESULT HVar2;
  undefined1 local_25c [44];
  undefined1 local_230;
  CHAR local_11c [264];
  undefined1 *local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  lpString1 = (LPCSTR)FUN_006375b5();
  local_c = 0;
  if ((lpString1 != (LPCSTR)0x0) && (iVar1 = lstrcmpiA(lpString1,&DAT_006d25c0), iVar1 == 0)) {
    local_10 = (int *)0x0;
    local_8 = (int *)0x0;
    local_230 = 0;
    local_11c[0] = '\0';
    HVar2 = CoCreateInstance((IID *)&DAT_006891c8,(LPUNKNOWN)0x0,1,(IID *)&DAT_006891d8,&local_8);
    if (-1 < HVar2) {
      iVar1 = (**(code **)*local_8)();
      if (-1 < iVar1) {
        iVar1 = lstrlenA(param_1);
        FUN_00636080();
        local_14 = &stack0xfffffd8c;
        MultiByteToWideChar(0,1,param_1,iVar1 + 1,(LPWSTR)&stack0xfffffd8c,iVar1 + 1);
        iVar1 = (**(code **)(*local_10 + 0x14))(local_10,local_14,0);
        if (((-1 < iVar1) && (iVar1 = (**(code **)(*local_8 + 0x4c))(local_8,0,1), -1 < iVar1)) &&
           (iVar1 = (**(code **)(*local_8 + 0xc))(local_8,local_11c,0x105,local_25c,0), iVar1 == 0))
        {
          local_c = lstrlenA(local_11c);
          local_c = local_c + 1;
          if (param_2 != (LPSTR)0x0) {
            lstrcpynA(param_2,local_11c,param_3);
          }
        }
        (**(code **)(*local_10 + 8))(local_10);
        local_10 = (int *)0x0;
      }
      (**(code **)(*local_8 + 8))(local_8);
      if (local_c != 0) {
        return local_c;
      }
    }
    local_c = -1;
  }
  return local_c;
}

