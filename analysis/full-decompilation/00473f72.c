
int FUN_00473f72(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0x30;
  if (0 < iVar1) {
    do {
      param_2 = param_2 + -0x30;
      param_3 = param_3 + -0x30;
      FUN_00473c9c(param_2);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

