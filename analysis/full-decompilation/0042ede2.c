
undefined4 * __thiscall FUN_0042ede2(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  uVar3 = iVar1 - (int)param_3 >> 3;
  if (0 < (int)uVar3) {
    puVar4 = param_3;
    puVar5 = param_2;
    for (iVar2 = (uVar3 & 0x1fffffff) << 1; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  *(int *)(param_1 + 4) = iVar1 + ((int)param_3 - (int)param_2 >> 3) * -8;
  return param_2;
}

