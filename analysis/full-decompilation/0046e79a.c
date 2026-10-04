
undefined4 * __thiscall FUN_0046e79a(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *local_8;
  
  local_8 = param_2;
  iVar1 = (*(int *)(param_1 + 4) - param_3) / 0x48;
  if (0 < iVar1) {
    do {
      iVar1 = iVar1 + -1;
      puVar3 = (undefined4 *)((param_3 - (int)param_2) + (int)local_8);
      puVar4 = local_8;
      for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      local_8 = local_8 + 0x12;
    } while (iVar1 != 0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + ((param_3 - (int)param_2) / 0x48) * -0x48;
  return param_2;
}

