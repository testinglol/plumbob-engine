
undefined4 FUN_00430654(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00666cf4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = FUN_00464f5b(unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + 0xc),
                       *(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00465055();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

