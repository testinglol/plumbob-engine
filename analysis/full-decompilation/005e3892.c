
void FUN_005e3892(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00673e38;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (DAT_006fe954 == extraout_ECX) {
    DAT_006fe954 = (undefined4 *)0x0;
  }
  FUN_005e38e0();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

