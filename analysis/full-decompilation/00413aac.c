
int FUN_00413aac(void)

{
  int unaff_EBP;
  int iVar1;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (*(int *)(unaff_EBP + 0xc) != 0) {
    *(int *)(unaff_EBP + -0x14) = iVar1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (iVar1 != 0) {
      FUN_00413743(*(undefined4 *)(unaff_EBP + 0x10));
    }
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + -1;
    iVar1 = iVar1 + 0x15c;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + 8) = iVar1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

