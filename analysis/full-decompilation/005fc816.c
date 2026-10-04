
undefined4 __thiscall FUN_005fc816(int *param_1,int param_2)

{
  int iVar1;
  
  if ((char)param_1[0x5f] != '\0') {
    if (param_2 < 0) {
      param_2 = 0;
    }
    else if (0x400 < param_2) {
      param_2 = 0x400;
    }
    param_1[0x5d] = param_2;
    iVar1 = (**(code **)(*(int *)param_1[99] + 0x24))
                      ((int *)param_1[99],(param_2 * 20000) / 0x400 + -10000);
    if (-1 < iVar1) {
      return 1;
    }
    (**(code **)(*param_1 + 0xc))();
  }
  return 0;
}

