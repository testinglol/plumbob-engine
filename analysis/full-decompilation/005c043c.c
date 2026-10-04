
undefined4 FUN_005c043c(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 0xc);
  uVar1 = iVar2 * 2 + 4;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(uint *)(unaff_EBP + -0x14) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar5 = unaff_EBP + -0x420;
  if (0x400 < uVar1) {
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
    FUN_005bd7b3(uVar1,unaff_EBP + -0xd);
    iVar5 = *(int *)(unaff_EBP + -0x20);
  }
  iVar4 = FUN_005bfeb2(*(undefined4 *)(unaff_EBP + 8),iVar2,*(undefined4 *)(unaff_EBP + 0x10),iVar5,
                       unaff_EBP + -0x14,0x10);
  puVar3 = *(undefined4 **)(unaff_EBP + 0x18);
  if (iVar4 == iVar2) {
    iVar5 = FUN_005bfeb2(iVar5,*(undefined4 *)(unaff_EBP + -0x14),0x10,
                         *(undefined4 *)(unaff_EBP + 0x14),puVar3,*(undefined4 *)(unaff_EBP + 0x1c))
    ;
    if (iVar5 == *(int *)(unaff_EBP + -0x14)) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar5 = *(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x20);
      if (iVar5 != 0) {
        FUN_0040189d(*(undefined4 *)(unaff_EBP + -0x20),iVar5);
      }
      uVar6 = *(undefined4 *)(unaff_EBP + 0xc);
      goto LAB_005c04f5;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar5 = *(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x20);
  *puVar3 = 0;
  if (iVar5 != 0) {
    FUN_0040189d(*(undefined4 *)(unaff_EBP + -0x20),iVar5);
  }
  uVar6 = 0;
LAB_005c04f5:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar6;
}

