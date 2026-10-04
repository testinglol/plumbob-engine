
undefined4 __thiscall FUN_005fc7a3(int *param_1,int param_2)

{
  int iVar1;
  
  if ((char)param_1[0x5f] != '\0') {
    param_1[0x5e] = param_2;
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
    iVar1 = (**(code **)(*(int *)param_1[99] + 0x1c))((int *)param_1[99],iVar1);
    if (-1 < iVar1) {
      return 1;
    }
    (**(code **)(*param_1 + 0xc))();
  }
  return 0;
}

