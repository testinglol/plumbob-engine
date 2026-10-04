
undefined4 * FUN_00418779(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0x50;
  if (0 < iVar1) {
    param_1 = param_1 - (int)param_3;
    do {
      *param_3 = *(undefined4 *)(param_1 + (int)param_3);
      FUN_0046f8e4(param_1 + 4 + (int)param_3);
      param_3 = param_3 + 0x14;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

