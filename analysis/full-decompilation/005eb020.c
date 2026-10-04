
undefined4 FUN_005eb020(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 0xc);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0xf8) = 3;
  }
  FUN_005eb07d(*(undefined4 *)(unaff_EBP + 8),iVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005ebbb5(unaff_EBP + -0x34);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

