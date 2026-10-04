
undefined4 * FUN_00521882(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0050904a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x36] = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x3b] = 0;
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
  extraout_ECX[0x4b] = 0;
  extraout_ECX[0x4c] = 0;
  *extraout_ECX = &PTR_FUN_0066c990;
  extraout_ECX[0x35] = &PTR_LAB_0066c980;
  return extraout_ECX;
}

