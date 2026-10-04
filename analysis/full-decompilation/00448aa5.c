
undefined4 * __thiscall FUN_00448aa5(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *local_2c;
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  
  local_1c = param_2;
  local_18 = param_3;
  for (local_14 = *(int *)(param_1 + 4) - (int)param_3 >> 2; 0 < local_14; local_14 = local_14 + -1)
  {
    *local_1c = *local_18;
    local_18 = local_18 + 1;
    local_1c = local_1c + 1;
  }
  for (local_2c = local_1c; local_2c != *(undefined4 **)(param_1 + 4); local_2c = local_2c + 1) {
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + ((int)param_3 - (int)param_2 >> 2) * -4;
  return param_2;
}

