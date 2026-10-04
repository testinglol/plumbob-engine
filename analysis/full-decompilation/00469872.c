
int __thiscall FUN_00469872(int param_1,uint param_2)

{
  if ((-1 < (int)param_2) &&
     (param_2 < (uint)((*(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x3c)) / 0x2c))) {
    return param_2 * 0x2c + *(int *)(param_1 + 0x3c);
  }
  return 0;
}

