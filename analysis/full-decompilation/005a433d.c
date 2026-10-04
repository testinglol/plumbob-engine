
void FUN_005a433d(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *extraout_ECX = 0;
  FUN_006321f0(extraout_ECX[0x89]);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX + 0x90;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005a5484();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005481b6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

