
void FUN_004d5a47(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00669190;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_004d5b91();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d9122();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004d5e80();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *extraout_ECX = &PTR_FUN_00668ff0;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

