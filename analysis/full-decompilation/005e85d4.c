
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005e85d4(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_00674414;
  FUN_005d4bbf(s_Your_Tip_Here_006d7770);
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  _DAT_006fea24 = _DAT_006fea24 + 1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x3a] = 0;
  *(undefined1 *)(extraout_ECX + 0x3b) = 1;
  return extraout_ECX;
}

