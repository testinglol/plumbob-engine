
int FUN_004a378e(void)

{
  int unaff_EBP;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  *(int *)(unaff_EBP + -0x14) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (*(int *)(unaff_EBP + 0xc) != 0) {
    *(int *)(unaff_EBP + -0x18) = iVar1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (iVar1 != 0) {
      FUN_004a2744(*(undefined4 *)(unaff_EBP + 0x10));
    }
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + -1;
    iVar1 = iVar1 + 0x11c;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x14) = iVar1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar1;
}

