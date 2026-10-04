
int FUN_005baa48(void)

{
  int iVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined1 *)(unaff_EBP + -0x10) = 0;
  *(undefined1 *)(unaff_EBP + -0xf) = 0;
  *(undefined1 *)(unaff_EBP + -0xe) = 0;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005bb113(unaff_EBP + -0x20);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  iVar1 = FUN_005bb3b6(unaff_EBP + -0x40);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar1 + 0xc;
}

