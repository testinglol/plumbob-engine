
int FUN_005ba9e5(void)

{
  int unaff_EBP;
  int iVar1;
  
  FUN_00634c24();
  FUN_005b870f(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b9589(unaff_EBP + -0x20);
  FUN_005a509f(unaff_EBP + -0x14,unaff_EBP + -0x20);
  if (*(int *)(unaff_EBP + -0x14) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(unaff_EBP + -0x14) + 0x10;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

