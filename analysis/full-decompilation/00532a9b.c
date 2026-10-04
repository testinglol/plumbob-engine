
undefined4 * FUN_00532a9b(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = uVar1;
  uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
  *extraout_ECX = &PTR_FUN_0066e6b0;
  extraout_ECX[0x41] = uVar1;
  return extraout_ECX;
}

