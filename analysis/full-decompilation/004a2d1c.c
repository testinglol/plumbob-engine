
int FUN_004a2d1c(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - param_1) / 0x11c;
  if (0 < iVar1) {
    do {
      param_2 = param_2 + -0x11c;
      param_3 = param_3 + -0x11c;
      FUN_004a2775(param_2);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_3;
}

