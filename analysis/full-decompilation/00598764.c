
int FUN_00598764(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar1 = FUN_005b870f(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00575bc0(unaff_EBP + -0x14,uVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  if ((*(int *)(unaff_EBP + -0x14) == 0) ||
     (iVar2 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0x10), iVar2 == -1)) {
    uVar1 = FUN_005b870f(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005b86bd(uVar1);
    *(int *)(unaff_EBP + -0x3c) = DAT_006d1bc0;
    iVar2 = DAT_006f6d40 + 1;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_0059d340(iVar2);
    FUN_0059d2af(unaff_EBP + -0x38,unaff_EBP + -0x48);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    iVar2 = DAT_006d1bc0;
    DAT_006d1bc0 = DAT_006d1bc0 + 1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar2;
}

