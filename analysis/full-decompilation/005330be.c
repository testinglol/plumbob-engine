
undefined4 * FUN_005330be(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005340f2();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  *extraout_ECX = &PTR_FUN_0066e850;
  extraout_ECX[0x50] = 0x43fa0000;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x52] = 0;
  extraout_ECX[0x38] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x145) = 0;
  extraout_ECX[0x53] = 0;
  return extraout_ECX;
}

