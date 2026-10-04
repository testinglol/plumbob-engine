
undefined4 FUN_0049b967(void)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005c36c0(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0049b9bd();
  FUN_005c36c0(unaff_EBP + -0x54);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c4890();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

