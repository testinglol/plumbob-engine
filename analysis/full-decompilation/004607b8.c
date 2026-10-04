
int FUN_004607b8(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0x44;
  if (0 < iVar1) {
    param_1 = param_1 - param_3;
    do {
      FUN_0041edc1(param_1 + param_3);
      param_3 = param_3 + 0x44;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

