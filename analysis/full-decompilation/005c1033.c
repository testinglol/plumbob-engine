
int FUN_005c1033(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046ea4d();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c1719();
  *(undefined4 *)(extraout_ECX + 0x10) = 0;
  *(undefined4 *)(extraout_ECX + 0x14) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x18) = 0;
  return extraout_ECX;
}

