
void FUN_004a2d52(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int *piVar5;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffecc;
  if (uVar1 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x11c) < uVar1) {
      uVar3 = (extraout_ECX[1] - *extraout_ECX) / 0x11c;
      piVar5 = (int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + -0x14) = uVar3;
      if (uVar1 <= uVar3) {
        piVar5 = (int *)(unaff_EBP + -0x14);
      }
      iVar7 = uVar3 + *piVar5;
      *(int *)(unaff_EBP + -0x14) = iVar7;
      if (iVar7 == 0) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
      }
      else {
        uVar4 = FUN_00401742(iVar7 * 0x11c);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
      }
      iVar7 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar4 = FUN_004a2c9e(iVar7,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
      uVar4 = FUN_004a3714(uVar4,uVar1,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
      iVar7 = FUN_004a2c9e(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],
                           *(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004a26fb(*extraout_ECX,extraout_ECX[1]);
      iVar6 = (extraout_ECX[2] - *extraout_ECX) / 0x11c;
      if (iVar6 != 0) {
        FUN_0040189d(*extraout_ECX,iVar6 * 0x11c);
      }
      iVar6 = *(int *)(unaff_EBP + -0x14);
      iVar2 = *(int *)(unaff_EBP + 0xc);
      *extraout_ECX = iVar2;
      extraout_ECX[1] = iVar7;
      extraout_ECX[2] = iVar6 * 0x11c + iVar2;
    }
    else {
      FUN_004a2108(*(undefined4 *)(unaff_EBP + 0x10));
      iVar7 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar3 = (iVar7 - *(int *)(unaff_EBP + 8)) / 0x11c;
      iVar7 = extraout_ECX[1];
      *(int *)(unaff_EBP + 0xc) = iVar7;
      if (uVar1 < uVar3) {
        iVar6 = iVar7 + uVar1 * -0x11c;
        FUN_004a2c9e(iVar6,iVar7,iVar7,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 0x11c;
        iVar7 = *(int *)(unaff_EBP + 8);
        FUN_004a2914(iVar7,iVar6,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 8),0);
        iVar6 = uVar1 * 0x11c + iVar7;
        for (; iVar7 != iVar6; iVar7 = iVar7 + 0x11c) {
          FUN_004a2139(unaff_EBP + -0x134);
        }
      }
      else {
        FUN_004a3714(iVar7,uVar1 - uVar3,unaff_EBP + -0x134,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + (uVar1 - uVar3) * 0x11c;
        iVar7 = *(int *)(unaff_EBP + 8);
        FUN_004a2c9e(iVar7,*(undefined4 *)(unaff_EBP + 0xc),extraout_ECX[1],
                     *(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar3 * 0x11c;
        if (iVar7 != *(int *)(unaff_EBP + 0xc)) {
          do {
            FUN_004a2139(unaff_EBP + -0x134);
            iVar7 = iVar7 + 0x11c;
          } while (iVar7 != *(int *)(unaff_EBP + 0xc));
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004a216a();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

