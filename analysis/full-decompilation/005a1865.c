
undefined4 * FUN_005a1865(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = *(undefined4 *)(unaff_EBP + 8);
  FUN_005c36c0(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

