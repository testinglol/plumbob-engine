
undefined4 * __thiscall FUN_0041fb0c(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = (*(int *)(param_1 + 4) - param_3) / 0xc;
  if (0 < iVar3) {
    puVar4 = param_2;
    do {
      puVar1 = (undefined4 *)((param_3 - (int)param_2) + (int)puVar4);
      *puVar4 = *puVar1;
      puVar2 = puVar4 + 2;
      puVar4[1] = puVar1[1];
      puVar4 = puVar4 + 3;
      iVar3 = iVar3 + -1;
      *puVar2 = puVar1[2];
    } while (iVar3 != 0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + ((param_3 - (int)param_2) / 0xc) * -0xc;
  return param_2;
}

