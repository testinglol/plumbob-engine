
int FUN_0046c97b(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0x2c;
  if (0 < iVar1) {
    param_1 = param_1 - param_3;
    do {
      FUN_0046ca0e(param_1 + param_3);
      param_3 = param_3 + 0x2c;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

