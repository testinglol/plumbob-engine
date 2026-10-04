
int FUN_005d624f(void)

{
  int unaff_EBP;
  int iVar1;
  int iVar2;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(unaff_EBP + 0x10);
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  *(int *)(unaff_EBP + -0x14) = iVar1;
  for (; iVar2 != *(int *)(unaff_EBP + 0xc); iVar2 = iVar2 + 0xc) {
    *(int *)(unaff_EBP + 8) = iVar1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (iVar1 != 0) {
      FUN_005b86bd(iVar2);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    iVar1 = iVar1 + 0xc;
    *(int *)(unaff_EBP + -0x14) = iVar1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

