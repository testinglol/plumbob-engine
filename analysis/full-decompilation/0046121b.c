
undefined4 FUN_0046121b(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (*(int *)(unaff_EBP + 8) == 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  else {
    uVar1 = FUN_00401742(*(int *)(unaff_EBP + 8) << 4);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004612c6(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
               *(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 8));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

