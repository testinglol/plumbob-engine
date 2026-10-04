
int FUN_0058753e(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_2 - param_1) / 0x110;
  if (0 < iVar1) {
    iVar2 = param_1 - param_3;
    param_1 = iVar1;
    do {
      FUN_0046f8e4(iVar2 + param_3);
      param_3 = param_3 + 0x110;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return param_3;
}

