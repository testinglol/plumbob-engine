
int FUN_00604729(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0x1c;
  if (0 < iVar1) {
    param_2 = param_2 - param_3;
    do {
      param_3 = param_3 + -0x1c;
      FUN_006046fe(param_2 + param_3);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

