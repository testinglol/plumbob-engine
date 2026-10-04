
undefined4 * FUN_00524f8d(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_0066cec4;
  *(undefined1 *)(extraout_ECX + 0x39) = 1;
  extraout_ECX[0x36] = 0;
  *(undefined1 *)((int)extraout_ECX + 0xe5) = 0;
  extraout_ECX[0x3d] = 0;
  *(undefined1 *)(extraout_ECX + 0x3e) = 0;
  extraout_ECX[0x37] = 0;
  return extraout_ECX;
}

