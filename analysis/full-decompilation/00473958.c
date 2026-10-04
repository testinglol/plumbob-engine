
int __thiscall FUN_00473958(int param_1,uint param_2)

{
  if ((-1 < (int)param_2) &&
     (param_2 < (uint)((*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8)) / 0x30))) {
    return param_2 * 0x30 + *(int *)(param_1 + 8);
  }
  return 0;
}

