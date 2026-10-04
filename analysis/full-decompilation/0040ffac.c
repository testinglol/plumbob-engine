
int FUN_0040ffac(void)

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
  for (; iVar1 != *(int *)(unaff_EBP + 0xc); iVar1 = iVar1 + 0x98) {
    *(int *)(unaff_EBP + 8) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (iVar2 != 0) {
      FUN_00472f33(iVar1);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    iVar2 = iVar2 + 0x98;
    *(int *)(unaff_EBP + 0x10) = iVar2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

