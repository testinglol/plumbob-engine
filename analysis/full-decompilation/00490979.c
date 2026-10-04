
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490979(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  bool bVar1;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00668070;
  _DAT_006e57c8 = _DAT_006e57c8 + -1;
  bVar1 = _DAT_006e57c8 == 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (bVar1) {
    if (DAT_006e57c4 != 0) {
      FUN_0049092e(3);
    }
    DAT_006e57c4 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00667bd0;
  return;
}

