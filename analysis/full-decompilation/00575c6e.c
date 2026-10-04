
int FUN_00575c6e(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  iVar2 = FUN_00401742(0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  iVar1 = iVar2 + 8;
  *(int *)(unaff_EBP + -0x18) = iVar1;
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (iVar1 != 0) {
    FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

