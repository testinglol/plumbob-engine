
undefined4 __thiscall FUN_005f94c1(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (0x400 < param_2) {
    param_2 = 0x400;
  }
  *(int *)(param_1 + 0x28) = param_2;
  if (*(int *)(param_1 + 0x80) != 0) {
    iVar1 = (**(code **)(*DAT_006fed70 + 0x18))();
    iVar1 = (iVar1 * param_2) / 0x400;
    if (iVar1 == 0) {
      iVar1 = -10000;
    }
    else if (iVar1 == 0x400) {
      iVar1 = 0;
    }
    else {
      iVar1 = (iVar1 * 4000) / 0x400 + -4000;
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0x80) + 0x3c))(*(int **)(param_1 + 0x80),iVar1);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 1;
}

