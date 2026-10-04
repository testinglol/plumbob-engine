
void FUN_004b578c(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_004b57f1();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00635f6d(extraout_ECX + 0xc,0xc,3,FUN_005481b6);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00635f6d(extraout_ECX + 3,0xc,3,FUN_005481b6);
  uVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

