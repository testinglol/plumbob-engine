
undefined4 * FUN_00531f81(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x3a] = uVar1;
  extraout_ECX[0x44] = 0;
  *extraout_ECX = &PTR_FUN_0066e510;
  *(undefined1 *)(extraout_ECX + 0x45) = 1;
  return extraout_ECX;
}

