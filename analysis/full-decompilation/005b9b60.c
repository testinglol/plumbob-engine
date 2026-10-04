
bool FUN_005b9b60(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b870f(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b9589(unaff_EBP + -0x20);
  FUN_005a509f(unaff_EBP + -0x14,unaff_EBP + -0x20);
  iVar1 = *(int *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1 != 0;
}

