
int FUN_005c2c96(void)

{
  int unaff_EBP;
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(unaff_EBP + 0x10);
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  *(int *)(unaff_EBP + -0x14) = iVar1;
  for (; iVar2 != *(int *)(unaff_EBP + 0xc); iVar2 = iVar2 + 4) {
    *(int *)(unaff_EBP + 8) = iVar1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (iVar1 != 0) {
      FUN_005c178a(iVar2);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    iVar1 = iVar1 + 4;
    *(int *)(unaff_EBP + -0x14) = iVar1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar1;
}

