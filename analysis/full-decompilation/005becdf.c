
DWORD __thiscall FUN_005becdf(int *param_1,int param_2,int param_3)

{
  DWORD DVar1;
  DWORD DVar2;
  
  if ((char)param_1[6] == '\0') {
    DVar1 = 0xffffffff;
  }
  else {
    if (param_3 == 0) {
      DVar1 = 0;
    }
    else if (param_3 == 1) {
      DVar1 = 1;
      if (param_1[0x13] != param_1[0x12]) {
        DVar1 = 0;
        param_2 = param_2 + param_1[0x12];
      }
    }
    else {
      if (param_3 != 2) {
        DVar1 = (**(code **)(*param_1 + 0x18))();
        return DVar1;
      }
      DVar1 = 2;
    }
    FUN_005bf04f();
    DVar1 = SetFilePointer((HANDLE)param_1[7],param_2,(PLONG)0x0,DVar1);
    if (DVar1 == 0xffffffff) {
      DVar2 = SetFilePointer((HANDLE)param_1[7],0,(PLONG)0x0,1);
      param_1[0x13] = DVar2;
      param_1[0x12] = DVar2;
      FUN_005bfa81();
    }
    else {
      param_1[0x13] = DVar1;
      param_1[0x12] = DVar1;
    }
  }
  return DVar1;
}

