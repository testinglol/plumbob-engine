
int FUN_005d2104(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0xc;
  if (0 < iVar1) {
    do {
      param_2 = param_2 + -0xc;
      param_3 = param_3 + -0xc;
      FUN_005d2136(param_2);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

