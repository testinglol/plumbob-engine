
int FUN_004ea9c8(int param_1)

{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < (DAT_006f264c - DAT_006f2648) / 0x44)) {
    iVar1 = FUN_004eaa44(param_1);
    if (iVar1 == 1) {
      iVar1 = FUN_004ea79e(param_1);
      return (int)*(short *)(iVar1 + 0x72);
    }
    iVar1 = FUN_004ea79e(param_1);
    return (int)*(short *)(iVar1 + 0x7e);
  }
  return 0;
}

