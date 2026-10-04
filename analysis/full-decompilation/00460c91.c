
void FUN_00460c91(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff48;
  if (uVar1 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x9c) < uVar1) {
      uVar3 = (extraout_ECX[1] - *extraout_ECX) / 0x9c;
      *(uint *)(unaff_EBP + -0x14) = uVar3;
      piVar4 = (int *)(unaff_EBP + 0xc);
      if (uVar1 <= uVar3) {
        piVar4 = (int *)(unaff_EBP + -0x14);
      }
      iVar7 = *piVar4 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x1c) = iVar7;
      if (iVar7 == 0) {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
      }
      else {
        uVar5 = FUN_00401742(iVar7 * 0x9c);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
      }
      iVar6 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar5 = FUN_004612f1(iVar6,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14),
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar5;
      uVar5 = FUN_0046138d(uVar5,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar5;
      uVar5 = FUN_004612f1(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],
                           *(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 8));
      iVar6 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 0x10) = uVar5;
      iVar2 = extraout_ECX[1];
      *(int *)(unaff_EBP + 0xc) = iVar2;
      *(int *)(unaff_EBP + 8) = iVar6;
      if (iVar6 != iVar2) {
        do {
          FUN_0045fae5();
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0x9c;
        } while (*(int *)(unaff_EBP + 8) != *(int *)(unaff_EBP + 0xc));
      }
      iVar6 = (extraout_ECX[2] - *extraout_ECX) / 0x9c;
      if (iVar6 != 0) {
        FUN_0040189d(*extraout_ECX,iVar6 * 0x9c);
      }
      iVar6 = *(int *)(unaff_EBP + -0x14);
      iVar2 = *(int *)(unaff_EBP + 0x10);
      *extraout_ECX = iVar6;
      extraout_ECX[1] = iVar2;
      extraout_ECX[2] = iVar7 * 0x9c + iVar6;
    }
    else {
      FUN_004607ee(*(undefined4 *)(unaff_EBP + 0x10));
      iVar7 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar3 = (iVar7 - *(int *)(unaff_EBP + 8)) / 0x9c;
      iVar7 = extraout_ECX[1];
      *(int *)(unaff_EBP + 0xc) = iVar7;
      if (uVar1 < uVar3) {
        iVar6 = iVar7 + uVar1 * -0x9c;
        FUN_004612f1(iVar6,iVar7,iVar7,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 0x9c;
        iVar7 = *(int *)(unaff_EBP + 8);
        FUN_00461290(iVar7,iVar6,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 8),0);
        iVar6 = uVar1 * 0x9c + iVar7;
        for (; iVar7 != iVar6; iVar7 = iVar7 + 0x9c) {
          FUN_004608ca(unaff_EBP + -0xb8);
        }
      }
      else {
        FUN_0046138d(iVar7,uVar1 - uVar3,unaff_EBP + -0xb8,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + (uVar1 - uVar3) * 0x9c;
        iVar7 = *(int *)(unaff_EBP + 8);
        FUN_004612f1(iVar7,*(undefined4 *)(unaff_EBP + 0xc),extraout_ECX[1],
                     *(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar3 * 0x9c;
        if (iVar7 != *(int *)(unaff_EBP + 0xc)) {
          do {
            FUN_004608ca(unaff_EBP + -0xb8);
            iVar7 = iVar7 + 0x9c;
          } while (iVar7 != *(int *)(unaff_EBP + 0xc));
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005db425();
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

