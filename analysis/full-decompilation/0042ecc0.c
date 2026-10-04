
void FUN_0042ecc0(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0042eedc();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040189d(*extraout_ECX,0x1c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

