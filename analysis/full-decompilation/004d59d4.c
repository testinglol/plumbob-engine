
undefined4 * FUN_004d59d4(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004d5583();
  extraout_ECX[0x3c] = 100;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d909f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00669190;
  return extraout_ECX;
}

