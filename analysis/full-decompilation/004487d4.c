
undefined4 * __thiscall FUN_004487d4(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *local_2c;
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  
  local_1c = param_2;
  local_18 = param_3;
  for (local_14 = (*(int *)(param_1 + 4) - (int)param_3) / 0x3c; 0 < local_14;
      local_14 = local_14 + -1) {
    puVar2 = local_18;
    puVar3 = local_1c;
    for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    local_18 = local_18 + 0xf;
    local_1c = local_1c + 0xf;
  }
  for (local_2c = local_1c; local_2c != *(undefined4 **)(param_1 + 4); local_2c = local_2c + 0xf) {
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (((int)param_3 - (int)param_2) / 0x3c) * -0x3c;
  return param_2;
}

