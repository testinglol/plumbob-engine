
undefined4 FUN_0041b677(void)

{
  int unaff_EBP;
  int iVar1;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 0x10);
  for (; iVar1 != *(int *)(unaff_EBP + 0xc); iVar1 = iVar1 + 0x14) {
    FUN_0041b4cf(*(undefined4 *)(unaff_EBP + -0x14),iVar1);
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x14;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}

