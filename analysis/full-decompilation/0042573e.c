
undefined4 __thiscall FUN_0042573e(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((int)param_2 < 1) ||
     ((uint)(*(int *)(param_1 + 0x14c) - *(int *)(param_1 + 0x148) >> 2) < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x148) + -4 + param_2 * 4);
  }
  return uVar1;
}

