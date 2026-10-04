
void FUN_004084db(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  if (uVar1 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x14) < uVar1) {
      uVar3 = (extraout_ECX[1] - *extraout_ECX) / 0x14;
      *(uint *)(unaff_EBP + -0x14) = uVar3;
      piVar4 = (int *)(unaff_EBP + 0xc);
      if (uVar1 <= uVar3) {
        piVar4 = (int *)(unaff_EBP + -0x14);
      }
      iVar6 = *piVar4 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x18) = iVar6;
      if (iVar6 == 0) {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
      }
      else {
        uVar5 = FUN_00401742(iVar6 * 0x14);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
      }
      iVar7 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + 0xc) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar5 = FUN_00408877(iVar7,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14),
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + 0xc) = uVar5;
      uVar5 = FUN_00408904(uVar5,uVar1,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + 0xc) = uVar5;
      uVar5 = FUN_00408877(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],
                           *(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 8));
      iVar7 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 0x10) = uVar5;
      iVar2 = extraout_ECX[1];
      *(int *)(unaff_EBP + 8) = iVar2;
      if (iVar7 != iVar2) {
        do {
          FUN_00407ad0();
          iVar7 = iVar7 + 0x14;
        } while (iVar7 != *(int *)(unaff_EBP + 8));
      }
      iVar7 = (extraout_ECX[2] - *extraout_ECX) / 0x14;
      if (iVar7 != 0) {
        FUN_0040189d(*extraout_ECX,iVar7 * 0x14);
      }
      iVar7 = *(int *)(unaff_EBP + -0x14);
      extraout_ECX[1] = *(int *)(unaff_EBP + 0x10);
      *extraout_ECX = iVar7;
      extraout_ECX[2] = iVar7 + iVar6 * 0x14;
    }
    else {
      iVar6 = *(int *)(unaff_EBP + 0x10);
      FUN_004080cf(iVar6);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar6 + 0xc);
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar6 + 0x10);
      iVar6 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar7 = extraout_ECX[1];
      uVar3 = (iVar6 - *(int *)(unaff_EBP + 8)) / 0x14;
      *(uint *)(unaff_EBP + 0xc) = uVar3;
      if (uVar1 < uVar3) {
        *(int *)(unaff_EBP + 0xc) = iVar7;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar1 * -0x14;
        FUN_00408877(*(undefined4 *)(unaff_EBP + 0xc),iVar7,iVar7,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 0x14;
        iVar6 = *(int *)(unaff_EBP + 8);
        FUN_00408831(iVar6,*(undefined4 *)(unaff_EBP + 0xc),iVar7,*(undefined4 *)(unaff_EBP + 8),0);
        iVar7 = uVar1 * 0x14 + iVar6;
        for (; iVar6 != iVar7; iVar6 = iVar6 + 0x14) {
          FUN_0040870e(unaff_EBP + -0x2c);
        }
      }
      else {
        FUN_00408904(iVar7,uVar1 - uVar3,unaff_EBP + -0x2c,*(undefined4 *)(unaff_EBP + 8));
        uVar5 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar1 - uVar3) * 0x14;
        FUN_00408877(*(undefined4 *)(unaff_EBP + 8),iVar7,extraout_ECX[1],uVar5);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 0x14;
        for (iVar6 = *(int *)(unaff_EBP + 8); iVar6 != iVar7; iVar6 = iVar6 + 0x14) {
          FUN_0040870e(unaff_EBP + -0x2c);
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00407c07();
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

