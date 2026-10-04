
int FUN_00489f0a(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0x3c;
  if (0 < iVar1) {
    param_2 = param_2 - param_3;
    do {
      param_3 = param_3 + -0x3c;
      FUN_00488534(param_2 + param_3);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

