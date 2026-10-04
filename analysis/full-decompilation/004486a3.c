
undefined4 * __thiscall FUN_004486a3(int param_1,undefined4 *param_2)

{
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  
  if (param_2 + 1 != *(undefined4 **)(param_1 + 4)) {
    local_1c = param_2;
    local_18 = param_2 + 1;
    for (local_14 = *(int *)(param_1 + 4) - (int)local_18 >> 2; 0 < local_14;
        local_14 = local_14 + -1) {
      *local_1c = *local_18;
      local_18 = local_18 + 1;
      local_1c = local_1c + 1;
    }
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -4;
  return param_2;
}

