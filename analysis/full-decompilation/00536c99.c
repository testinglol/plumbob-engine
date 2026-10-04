
undefined4 * FUN_00536c99(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0050904a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d48d9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x37] = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x3b] = 0;
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x4d] = 0;
  extraout_ECX[0x4e] = 0;
  *extraout_ECX = &PTR_FUN_0066ed40;
  extraout_ECX[0x35] = &PTR_LAB_0066ed30;
  return extraout_ECX;
}

