
int FUN_005c1b28(void)

{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005c26e9(unaff_EBP + -0x14,*(undefined4 *)(unaff_EBP + 0x10));
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 == *extraout_ECX) {
    iVar2 = FUN_004096c2();
    iVar3 = FUN_00401f73();
    if (iVar2 != iVar3) {
      do {
        FUN_005c2efd(unaff_EBP + -0x20,iVar2);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iVar3 = FUN_005c1d8b(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),
                             *(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + 0x14));
        if ((iVar3 == 0) || (iVar3 == 4)) {
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          goto LAB_005c1c6e;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        iVar2 = iVar2 + 0xc;
        iVar3 = FUN_00401f73();
      } while (iVar2 != iVar3);
    }
    if (*(char *)(unaff_EBP + 0x18) != '\0') {
      for (iVar2 = FUN_004096c2(); iVar3 = FUN_00401f73(), iVar2 != iVar3; iVar2 = iVar2 + 0xc) {
        FUN_005c2efd(unaff_EBP + -0x2c,iVar2);
        *(undefined4 *)(unaff_EBP + -4) = 1;
        iVar3 = FUN_005c1e25(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),
                             *(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + 0x14),
                             0x80000000);
        if ((iVar3 == 0) || (iVar3 == 4)) {
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          goto LAB_005c1c6e;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
      }
    }
  }
  else {
    for (iVar3 = *(int *)(iVar2 + 0x14); iVar3 != *(int *)(iVar2 + 0x18); iVar3 = iVar3 + 4) {
      iVar1 = FUN_005c1b28(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),iVar3,
                           *(undefined4 *)(unaff_EBP + 0x14),1);
      if (iVar1 == 0) {
        iVar3 = 0;
        goto LAB_005c1c6e;
      }
    }
  }
  iVar3 = 5;
LAB_005c1c6e:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar3;
}

