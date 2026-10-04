
int FUN_004a20ca(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_2 - param_1) / 0x11c;
  if (0 < iVar1) {
    iVar2 = param_1 - param_3;
    param_1 = iVar1;
    do {
      FUN_004a2775(iVar2 + param_3);
      param_3 = param_3 + 0x11c;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return param_3;
}

