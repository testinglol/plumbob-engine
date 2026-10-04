
void FUN_005d1a34(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffdc;
  if (uVar1 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0xc) < uVar1) {
      uVar2 = (extraout_ECX[1] - *extraout_ECX) / 0xc;
      *(uint *)(unaff_EBP + -0x14) = uVar2;
      piVar3 = (int *)(unaff_EBP + 0xc);
      if (uVar1 <= uVar2) {
        piVar3 = (int *)(unaff_EBP + -0x14);
      }
      iVar6 = *piVar3 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x18) = iVar6;
      if (iVar6 == 0) {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
      }
      else {
        uVar4 = FUN_00401742(iVar6 * 0xc);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
      }
      iVar5 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + 0xc) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar4 = FUN_005d225a(iVar5,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14),
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
      uVar4 = FUN_005d22ce(uVar4,uVar1,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
      uVar4 = FUN_005d225a(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],
                           *(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 8));
      iVar5 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 0x10) = uVar4;
      iVar7 = extraout_ECX[1];
      *(int *)(unaff_EBP + 8) = iVar7;
      if (iVar5 != iVar7) {
        do {
          FUN_005d239c(0);
          iVar5 = iVar5 + 0xc;
        } while (iVar5 != *(int *)(unaff_EBP + 8));
      }
      iVar5 = (extraout_ECX[2] - *extraout_ECX) / 0xc;
      if (iVar5 != 0) {
        FUN_0040189d(*extraout_ECX,iVar5 * 0xc);
      }
      iVar5 = *(int *)(unaff_EBP + -0x14);
      extraout_ECX[1] = *(int *)(unaff_EBP + 0x10);
      *extraout_ECX = iVar5;
      extraout_ECX[2] = iVar5 + iVar6 * 0xc;
    }
    else {
      FUN_005d20b9(*(undefined4 *)(unaff_EBP + 0x10));
      iVar6 = extraout_ECX[1];
      iVar5 = *(int *)(unaff_EBP + 8);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + 8) = (iVar6 - iVar5) / 0xc;
      iVar6 = extraout_ECX[1];
      *(int *)(unaff_EBP + 0xc) = iVar6;
      if (uVar1 < *(uint *)(unaff_EBP + 8)) {
        *(int *)(unaff_EBP + 8) = iVar6;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + uVar1 * -0xc;
        FUN_005d225a(*(undefined4 *)(unaff_EBP + 8),iVar6,iVar6,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 0xc;
        FUN_005d2104(iVar5,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                     *(undefined4 *)(unaff_EBP + 8),0);
        iVar6 = uVar1 * 0xc + iVar5;
        for (; iVar5 != iVar6; iVar5 = iVar5 + 0xc) {
          FUN_005d2136(unaff_EBP + -0x24);
        }
      }
      else {
        iVar7 = uVar1 - *(int *)(unaff_EBP + 8);
        FUN_005d22ce(iVar6,iVar7,unaff_EBP + -0x24,*(undefined4 *)(unaff_EBP + 8));
        uVar4 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + iVar7 * 0xc;
        FUN_005d225a(iVar5,*(undefined4 *)(unaff_EBP + 0xc),extraout_ECX[1],uVar4);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 8) * 0xc;
        for (; iVar5 != *(int *)(unaff_EBP + 0xc); iVar5 = iVar5 + 0xc) {
          FUN_005d2136(unaff_EBP + -0x24);
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004d4185();
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

