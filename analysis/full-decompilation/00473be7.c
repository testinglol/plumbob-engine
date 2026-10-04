
int FUN_00473be7(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0x30;
  if (0 < iVar1) {
    param_1 = param_1 - param_3;
    do {
      FUN_00473c9c(param_1 + param_3);
      param_3 = param_3 + 0x30;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

