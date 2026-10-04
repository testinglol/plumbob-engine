
void FUN_00405851(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int *piVar5;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffc24;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x3c0) < *(uint *)(unaff_EBP + 0xc)) {
      uVar3 = (extraout_ECX[1] - *extraout_ECX) / 0x3c0;
      piVar5 = (int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + -0x14) = uVar3;
      if (*(uint *)(unaff_EBP + 0xc) <= uVar3) {
        piVar5 = (int *)(unaff_EBP + -0x14);
      }
      iVar7 = *piVar5 + uVar3;
      *(int *)(unaff_EBP + -0x1c) = iVar7;
      if (iVar7 == 0) {
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
      }
      else {
        uVar4 = FUN_00401742(iVar7 * 0x3c0);
        *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
      }
      iVar6 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar4 = FUN_00406120(iVar6,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                           *(undefined4 *)(unaff_EBP + 0xc));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
      uVar4 = FUN_00406190(uVar4,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 0xc));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
      uVar4 = FUN_00406120(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],
                           *(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar6 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
      FUN_00405f70(*extraout_ECX,iVar6);
      iVar6 = (extraout_ECX[2] - *extraout_ECX) / 0x3c0;
      if (iVar6 != 0) {
        FUN_0040189d(*extraout_ECX,iVar6 * 0x3c0);
      }
      iVar6 = *(int *)(unaff_EBP + -0x18);
      iVar1 = *(int *)(unaff_EBP + 0xc);
      *extraout_ECX = iVar6;
      extraout_ECX[1] = iVar1;
      extraout_ECX[2] = iVar7 * 0x3c0 + iVar6;
    }
    else {
      FUN_00405dcd(*(undefined4 *)(unaff_EBP + 0x10));
      iVar7 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar2 = (iVar7 - *(int *)(unaff_EBP + 8)) / 0x3c0;
      uVar3 = *(uint *)(unaff_EBP + 0xc);
      iVar7 = extraout_ECX[1];
      *(int *)(unaff_EBP + 0x10) = iVar7;
      if (uVar3 < uVar2) {
        iVar6 = iVar7 + uVar3 * -0x3c0;
        FUN_00406120(iVar6,iVar7,iVar7,*(undefined4 *)(unaff_EBP + 0xc));
        extraout_ECX[1] = extraout_ECX[1] + uVar3 * 0x3c0;
        iVar7 = *(int *)(unaff_EBP + 8);
        FUN_00406076(iVar7,iVar6,*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0xc),
                     0);
        iVar6 = uVar3 * 0x3c0 + iVar7;
        for (; iVar7 != iVar6; iVar7 = iVar7 + 0x3c0) {
          FUN_00405f8c(unaff_EBP + -0x3dc);
        }
      }
      else {
        FUN_00406190(iVar7,uVar3 - uVar2,unaff_EBP + -0x3dc,*(undefined4 *)(unaff_EBP + 0xc));
        extraout_ECX[1] = extraout_ECX[1] + (uVar3 - uVar2) * 0x3c0;
        iVar7 = *(int *)(unaff_EBP + 8);
        FUN_00406120(iVar7,*(undefined4 *)(unaff_EBP + 0x10),extraout_ECX[1],
                     *(undefined4 *)(unaff_EBP + 0xc));
        extraout_ECX[1] = extraout_ECX[1] + uVar2 * 0x3c0;
        if (iVar7 != *(int *)(unaff_EBP + 0x10)) {
          do {
            FUN_00405f8c(unaff_EBP + -0x3dc);
            iVar7 = iVar7 + 0x3c0;
          } while (iVar7 != *(int *)(unaff_EBP + 0x10));
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

