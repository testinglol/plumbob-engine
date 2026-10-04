
undefined4 FUN_005b9b0c(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  FUN_005bad81(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = FUN_005bf9ac(unaff_EBP + -0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
  FUN_00401729();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

