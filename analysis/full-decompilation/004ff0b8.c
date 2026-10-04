
int FUN_004ff0b8(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0xc;
  if (0 < iVar1) {
    param_1 = param_1 - param_3;
    do {
      FUN_004ff151(param_1 + param_3);
      param_3 = param_3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

