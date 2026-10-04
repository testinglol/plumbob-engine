
int FUN_00413705(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_2 - param_1) / 0x15c;
  if (0 < iVar1) {
    iVar2 = param_1 - param_3;
    param_1 = iVar1;
    do {
      FUN_0041376e(iVar2 + param_3);
      param_3 = param_3 + 0x15c;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return param_3;
}

