
undefined4 __thiscall FUN_005928fd(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x140);
  }
  else {
    if (param_2 < 1) {
      return 0;
    }
    if (param_2 < 3) {
      iVar1 = *(int *)(param_1 + 0x144);
    }
    else {
      if (param_2 != 3) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 0x148);
    }
  }
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00596429(param_3);
  return 1;
}

