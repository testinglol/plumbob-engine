
undefined4 * __thiscall FUN_0042ed71(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = iVar1 - (int)param_3 >> 2;
  puVar3 = param_3;
  puVar4 = param_2;
  if (0 < iVar2) {
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  *(int *)(param_1 + 4) = iVar1 + ((int)param_3 - (int)param_2 >> 2) * -4;
  return param_2;
}

