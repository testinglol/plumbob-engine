
void FUN_004065f0(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00666594;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00635f6d(extraout_ECX + 3,0x14,8,&LAB_004065e8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004659d4();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

