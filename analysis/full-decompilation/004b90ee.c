
int FUN_004b90ee(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_2 - param_1 >> 3;
  if (0 < iVar1) {
    do {
      param_2 = param_2 + -8;
      param_3 = param_3 + -8;
      FUN_004b8d99(param_2);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

