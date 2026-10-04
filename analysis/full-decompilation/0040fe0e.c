
int FUN_0040fe0e(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_2 - param_1) / 0x98;
  if (0 < iVar1) {
    iVar2 = param_2 - param_3;
    param_2 = iVar1;
    do {
      param_3 = param_3 + -0x98;
      FUN_00473077(iVar2 + param_3);
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return param_3;
}

