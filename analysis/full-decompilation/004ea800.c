
undefined4 FUN_004ea800(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (-1 < param_1) {
    if (param_1 < (DAT_006f264c - DAT_006f2648) / 0x44) {
      iVar1 = FUN_004ea2ce(param_1);
      if (iVar1 != 0) {
        uVar2 = FUN_00427281(iVar1);
        return uVar2;
      }
    }
  }
  return 0;
}

