
int FUN_0054195a(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_2 - param_1 >> 2;
  if (0 < iVar1) {
    do {
      param_2 = param_2 + -4;
      param_3 = param_3 + -4;
      FUN_005412f4(param_2);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

