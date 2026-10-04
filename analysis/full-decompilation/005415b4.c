
int FUN_005415b4(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_2 - param_1 >> 2;
  if (0 < iVar1) {
    param_1 = param_1 - param_3;
    do {
      FUN_005414d4(param_1 + param_3);
      param_3 = param_3 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

