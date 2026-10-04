
undefined4 * FUN_00430957(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = param_2 - (int)param_1 >> 2;
  iVar2 = iVar1;
  puVar3 = param_3;
  if (iVar1 < 1) {
    return param_3;
  }
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_3 + iVar1;
}

