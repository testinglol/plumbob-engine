
int FUN_004ea79e(int param_1)

{
  int iVar1;
  
  if ((-1 < param_1) && (param_1 < (DAT_006f264c - DAT_006f2648) / 0x44)) {
    iVar1 = FUN_004e9744(param_1);
    if (iVar1 != 0) {
      return iVar1 + 0x58c;
    }
    iVar1 = FUN_004ea2ce(param_1);
    if (iVar1 != 0) {
      return iVar1 + 0x74;
    }
  }
  return 0;
}

