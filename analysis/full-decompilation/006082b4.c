
void FUN_006082b4(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00608311();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040189d(*extraout_ECX,0x20);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

