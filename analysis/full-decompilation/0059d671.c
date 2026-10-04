
int FUN_0059d671(void)

{
  int unaff_EBP;
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffff0;
  while (*(int *)(unaff_EBP + 0xc) != 0) {
    FUN_0059d6bc(iVar1,*(undefined4 *)(unaff_EBP + 0x10));
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + -1;
    iVar1 = iVar1 + 0x18;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar1;
}

