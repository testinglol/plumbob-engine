
undefined4 __thiscall FUN_00418f0b(int *param_1,uint param_2)

{
  if ((0 < (int)param_2) && (param_2 <= (uint)((param_1[1] - *param_1) / 0x14))) {
    return *(undefined4 *)(*param_1 + -8 + param_2 * 0x14);
  }
  return 0;
}

