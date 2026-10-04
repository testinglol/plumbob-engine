
int FUN_004b909d(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_2 - param_1 >> 3;
  if (0 < iVar1) {
    param_1 = param_1 - param_3;
    do {
      FUN_004b8d99(param_1 + param_3);
      param_3 = param_3 + 8;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

