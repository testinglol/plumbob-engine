
int FUN_00430a6e(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  iVar2 = FUN_00401742(0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  iVar1 = iVar2 + 0x10;
  *(int *)(unaff_EBP + -0x18) = iVar1;
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (iVar1 != 0) {
    FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar2;
}

