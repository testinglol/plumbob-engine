
int FUN_004e3e81(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 - param_1 >> 4;
  if (0 < iVar2) {
    do {
      iVar1 = param_3 + -0x10;
      FUN_005d499c(param_2 + -0x10);
      iVar2 = iVar2 + -1;
      *(undefined4 *)(param_3 + -4) = *(undefined4 *)(param_2 + -4);
      param_2 = param_2 + -0x10;
      param_3 = iVar1;
    } while (iVar2 != 0);
  }
  return param_3;
}

