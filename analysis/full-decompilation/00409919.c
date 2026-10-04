
void FUN_00409919(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  uVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
  FUN_0040f6e0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

