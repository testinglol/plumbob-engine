
int FUN_004139a9(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_2 - param_1) / 0x15c;
  if (0 < iVar1) {
    iVar2 = param_2 - param_3;
    param_2 = iVar1;
    do {
      param_3 = param_3 + -0x15c;
      FUN_0041376e(iVar2 + param_3);
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return param_3;
}

