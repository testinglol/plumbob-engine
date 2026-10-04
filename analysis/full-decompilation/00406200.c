
undefined4 * FUN_00406200(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_2 - (int)param_1 >> 2;
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

