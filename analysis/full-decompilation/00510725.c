
uint __thiscall FUN_00510725(int param_1,uint param_2)

{
  if (((int)param_2 < 0) || (1 < (int)param_2)) {
    param_2 = param_2 & 0xffffff00;
  }
  else {
    param_2 = CONCAT31((int3)(param_2 * 5 >> 8),*(int *)(param_1 + 0x2c + param_2 * 0x28) != 0);
  }
  return param_2;
}

