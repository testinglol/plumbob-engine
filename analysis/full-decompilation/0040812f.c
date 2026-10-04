
void __thiscall FUN_0040812f(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *local_8;
  
  iVar1 = param_3;
  local_8 = param_2;
  iVar3 = *(int *)(param_1 + 4) - param_3 >> 5;
  if (0 < iVar3) {
    iVar2 = param_3 - (int)param_2;
    param_3 = iVar3;
    do {
      param_3 = param_3 + -1;
      puVar4 = (undefined4 *)(iVar2 + (int)local_8);
      puVar5 = local_8;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      local_8 = local_8 + 8;
    } while (param_3 != 0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (iVar1 - (int)param_2 >> 5) * -0x20;
  return;
}

