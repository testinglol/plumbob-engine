
undefined4 * FUN_004972d2(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00492ad8();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0xb] = 0;
  *(undefined1 *)(extraout_ECX + 0xc) = 1;
  FUN_00461e56(0,0,0,0,1);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xf] = 0;
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x14] = uVar1;
  extraout_ECX[0x15] = 0;
  *(undefined1 *)(extraout_ECX + 0x13) = 1;
  *extraout_ECX = &PTR_FUN_0066822c;
  return extraout_ECX;
}

