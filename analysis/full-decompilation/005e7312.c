
void FUN_005e7312(void)

{
  int iVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 8) != 0) {
    iVar1 = *(int *)(unaff_EBP + 0xc);
    FUN_005b86bd(iVar1);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b86bd(iVar1 + 0xc);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

