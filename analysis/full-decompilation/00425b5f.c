
uint __thiscall FUN_00425b5f(int param_1,uint param_2)

{
  if ((uint)(int)(short)param_2 < (uint)(*(int *)(param_1 + 0x14c) - *(int *)(param_1 + 0x148) >> 2)
     ) {
    do {
      param_2 = param_2 + 1;
      if (*(int *)(*(int *)(param_1 + 0x148) + -4 + (short)param_2 * 4) != 0) {
        return param_2;
      }
    } while ((uint)(int)(short)param_2 <
             (uint)(*(int *)(param_1 + 0x14c) - *(int *)(param_1 + 0x148) >> 2));
  }
  return param_2 & 0xffff0000;
}

