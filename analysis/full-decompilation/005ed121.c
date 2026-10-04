
undefined4 __thiscall FUN_005ed121(int *param_1,byte param_2,int param_3,byte param_4)

{
  char cVar1;
  HANDLE pvVar2;
  undefined4 uVar3;
  DWORD dwDesiredAccess;
  DWORD dwShareMode;
  DWORD dwCreationDisposition;
  
  cVar1 = (**(code **)(*param_1 + 4))();
  if (cVar1 == '\0') {
    dwDesiredAccess = 0;
    if ((param_2 & 1) != 0) {
      dwDesiredAccess = 0x80000000;
    }
    dwCreationDisposition = 2;
    if ((param_2 & 2) != 0) {
      dwDesiredAccess = dwDesiredAccess | 0x40000000;
    }
    dwShareMode = (DWORD)((param_4 & 1) != 0);
    if ((param_4 & 2) != 0) {
      dwShareMode = dwShareMode | 2;
    }
    if (param_3 == 0) {
      dwCreationDisposition = 1;
LAB_005ed183:
      pvVar2 = CreateFileA((LPCSTR)param_1[1],dwDesiredAccess,dwShareMode,(LPSECURITY_ATTRIBUTES)0x0
                           ,dwCreationDisposition,0,(HANDLE)0x0);
      param_1[5] = (int)pvVar2;
      if (pvVar2 != (HANDLE)0xffffffff) {
        *(undefined1 *)(param_1 + 4) = 1;
        goto LAB_005ed19f;
      }
    }
    else {
      if (param_3 == 1) goto LAB_005ed183;
      if (param_3 == 2) {
        dwCreationDisposition = 3;
        goto LAB_005ed183;
      }
      if (param_3 == 3) {
        dwCreationDisposition = 4;
        goto LAB_005ed183;
      }
      if (param_3 == 4) {
        dwCreationDisposition = 5;
        goto LAB_005ed183;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_005ed19f:
    uVar3 = 1;
  }
  return uVar3;
}

