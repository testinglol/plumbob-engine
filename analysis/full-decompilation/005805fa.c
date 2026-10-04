
undefined4 __thiscall FUN_005805fa(int param_1,int param_2,undefined4 param_3)

{
  for (; (param_2 < *(int *)(param_1 + 8) ||
         (*(int *)(param_1 + 4) + -1 + *(int *)(param_1 + 8) < param_2));
      param_1 = *(int *)(param_1 + 0x10)) {
  }
  param_2 = param_2 - *(int *)(param_1 + 8);
  *(undefined4 *)(*(int *)(param_1 + 0xc) + param_2 * 4) = param_3;
  return CONCAT31((int3)((uint)param_2 >> 8),1);
}

