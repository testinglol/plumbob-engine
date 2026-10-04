
int FUN_00413a4a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  iVar2 = *(int *)(unaff_EBP + 0x10);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffff0;
  *(int *)(unaff_EBP + 0x10) = iVar2;
  for (; iVar1 != *(int *)(unaff_EBP + 0xc); iVar1 = iVar1 + 0x15c) {
    *(int *)(unaff_EBP + 8) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (iVar2 != 0) {
      FUN_00413743(iVar1);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    iVar2 = iVar2 + 0x15c;
    *(int *)(unaff_EBP + 0x10) = iVar2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

