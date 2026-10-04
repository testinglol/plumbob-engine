
void FUN_005e5e16(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00674344;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004054b4();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004054b4();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

