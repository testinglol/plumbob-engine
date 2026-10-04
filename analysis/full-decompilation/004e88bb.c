
int FUN_004e88bb(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005c1719();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0xc) = 0;
  FUN_005b8680();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

