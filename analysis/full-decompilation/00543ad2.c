
undefined4 * FUN_00543ad2(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0047343b(0,0);
  extraout_ECX[0x43] = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_0066f780;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x3f] = 6;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  *(undefined1 *)(extraout_ECX + 0x48) = 0;
  extraout_ECX[0x3b] = 0;
  extraout_ECX[0x3e] = 0;
  *(undefined1 *)(extraout_ECX + 0x35) = 0;
  return extraout_ECX;
}

