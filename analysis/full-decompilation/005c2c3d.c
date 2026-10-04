
int FUN_005c2c3d(void)

{
  int iVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  iVar1 = FUN_00401742(0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar1;
  FUN_005c2d7e(iVar1 + 0x10,*(undefined4 *)(unaff_EBP + 8));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar1;
}

