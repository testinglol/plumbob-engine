
undefined4 * FUN_0057fc94(void)

{
  undefined1 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0057c1e0(0xa3cd96b7);
  *extraout_ECX = &PTR_FUN_00671bdc;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 0xc));
  uVar1 = *(undefined1 *)(unaff_EBP + 0x10);
  extraout_ECX[0x32] = 0;
  extraout_ECX[0x34] = 0;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_00671b2c;
  FUN_005805fa(0x2c,uVar1);
  FUN_005805fa(0x26,*(undefined1 *)(unaff_EBP + 0x14));
  FUN_005805fa(0x2b,*(undefined1 *)(unaff_EBP + 0x18));
  FUN_005805fa(0x1a,*(undefined1 *)(unaff_EBP + 0x1c));
  FUN_005805fa(0x1b,*(undefined1 *)(unaff_EBP + 0x20));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

