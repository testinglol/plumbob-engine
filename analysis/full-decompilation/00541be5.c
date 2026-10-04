
int FUN_00541be5(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_2 - param_1 >> 2;
  if (0 < iVar1) {
    param_2 = param_2 - param_3;
    do {
      param_3 = param_3 + -4;
      FUN_005412f4(param_2 + param_3);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

