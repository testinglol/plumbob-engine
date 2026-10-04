
undefined1 * FUN_0047d87e(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = (param_2 - param_1) / 3;
  if (0 < iVar1) {
    puVar2 = (undefined1 *)(param_1 + 2);
    param_1 = (int)param_3 - param_1;
    do {
      *param_3 = puVar2[-2];
      param_3[1] = puVar2[-1];
      puVar2[param_1] = *puVar2;
      param_3 = param_3 + 3;
      puVar2 = puVar2 + 3;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

