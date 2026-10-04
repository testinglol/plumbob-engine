
undefined4 * FUN_005b86cf(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00401a3c(*(int *)(unaff_EBP + 8),*(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

