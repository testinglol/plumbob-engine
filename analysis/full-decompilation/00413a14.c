
int FUN_00413a14(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0x15c;
  if (0 < iVar1) {
    do {
      param_2 = param_2 + -0x15c;
      param_3 = param_3 + -0x15c;
      FUN_0041376e(param_2);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

