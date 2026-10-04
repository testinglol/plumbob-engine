
undefined4 FUN_00408877(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 0x10);
  for (; iVar2 != *(int *)(unaff_EBP + 0xc); iVar2 = iVar2 + 0x14) {
    FUN_0040872f(*(undefined4 *)(unaff_EBP + -0x14),iVar2);
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x14;
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

