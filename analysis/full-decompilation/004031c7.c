
undefined2 * FUN_004031c7(undefined2 *param_1,int param_2,undefined2 *param_3)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = param_2 - (int)param_1 >> 1;
  if (0 < iVar3) {
    do {
      uVar2 = *param_1;
      puVar1 = param_3 + 1;
      param_1 = param_1 + 1;
      iVar3 = iVar3 + -1;
      *param_3 = uVar2;
      param_3 = puVar1;
    } while (iVar3 != 0);
  }
  return param_3;
}

