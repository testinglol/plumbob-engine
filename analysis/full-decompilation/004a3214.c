
int FUN_004a3214(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  iVar2 = *(int *)(unaff_EBP + 0x10);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  for (; iVar1 != *(int *)(unaff_EBP + 0xc); iVar1 = iVar1 + 0x11c) {
    *(int *)(unaff_EBP + 8) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (iVar2 != 0) {
      FUN_004a2744(iVar1);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    iVar2 = iVar2 + 0x11c;
    *(int *)(unaff_EBP + -0x14) = iVar2;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar2;
}

