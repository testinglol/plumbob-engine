
undefined4 __thiscall FUN_005e8a16(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 == *(int *)(param_1 + 0xe4)) && (DAT_006fea20 != (int *)0x0)) {
    return 0;
  }
  *(int *)(param_1 + 0xe4) = param_2;
  if (param_2 == 0) {
    iVar1 = *DAT_006fea20;
  }
  else {
    iVar1 = *DAT_006fea20;
    if (param_2 == 1) {
      uVar2 = *(undefined4 *)(param_1 + 0xf8);
      goto LAB_005e8a5f;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0xf4);
LAB_005e8a5f:
  (**(code **)(iVar1 + 0x20))(uVar2);
  return 1;
}

