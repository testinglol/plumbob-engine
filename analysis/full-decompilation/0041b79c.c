
undefined4 FUN_0041b79c(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  while (*(int *)(unaff_EBP + 0xc) != 0) {
    FUN_0041b4cf(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0x10));
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + -1;
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x14;
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

