
int __thiscall FUN_005f565b(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xd8) - *(int *)(param_1 + 0xd4) >> 2)) {
    param_1 = *(int *)(*(int *)(param_1 + 0xd4) + param_2 * 4);
  }
  return param_1 + 0x4c;
}

