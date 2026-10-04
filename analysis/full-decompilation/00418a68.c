
undefined4 * FUN_00418a68(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = ((int)param_2 - param_1) / 0x50;
  if (0 < iVar1) {
    puVar2 = param_2 + 1;
    puVar3 = param_2;
    param_2 = (undefined4 *)iVar1;
    do {
      puVar3 = puVar3 + -0x14;
      puVar2 = puVar2 + -0x14;
      param_3 = param_3 + -0x14;
      *param_3 = *puVar3;
      FUN_0046f8e4(puVar2);
      param_2 = (undefined4 *)((int)param_2 + -1);
    } while (param_2 != (undefined4 *)0x0);
  }
  return param_3;
}

