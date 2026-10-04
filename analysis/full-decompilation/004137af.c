
void FUN_004137af(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *extraout_ECX;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffe88;
  if (uVar1 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x15c) < uVar1) {
      uVar2 = (extraout_ECX[1] - *extraout_ECX) / 0x15c;
      *(uint *)(unaff_EBP + -0x14) = uVar2;
      piVar3 = (int *)(unaff_EBP + 0xc);
      if (uVar1 <= uVar2) {
        piVar3 = (int *)(unaff_EBP + -0x14);
      }
      iVar7 = *piVar3 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x18) = iVar7;
      if (iVar7 == 0) {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
      }
      else {
        uVar4 = FUN_00401742(iVar7 * 0x15c);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
      }
      iVar6 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
      uVar4 = FUN_00413a4a(iVar6,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar4 = FUN_00413aac(uVar4,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar4 = FUN_00413a4a(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar4,
                           *(undefined4 *)(unaff_EBP + 8));
      iVar6 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + 8) = uVar4;
      for (iVar5 = *extraout_ECX; iVar5 != iVar6; iVar5 = iVar5 + 0x15c) {
      }
      iVar6 = (extraout_ECX[2] - *extraout_ECX) / 0x15c;
      if (iVar6 != 0) {
        FUN_0040189d(*extraout_ECX,iVar6 * 0x15c);
      }
      iVar6 = *(int *)(unaff_EBP + -0x14);
      iVar5 = *(int *)(unaff_EBP + 8);
      *extraout_ECX = iVar6;
      extraout_ECX[1] = iVar5;
      extraout_ECX[2] = iVar7 * 0x15c + iVar6;
    }
    else {
      FUN_00413743(*(undefined4 *)(unaff_EBP + 0x10));
      uVar2 = (extraout_ECX[1] - *(int *)(unaff_EBP + 8)) / 0x15c;
      iVar7 = extraout_ECX[1];
      *(int *)(unaff_EBP + 0xc) = iVar7;
      if (uVar1 < uVar2) {
        iVar6 = iVar7 + uVar1 * -0x15c;
        FUN_00413a4a(iVar6,iVar7,iVar7,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 0x15c;
        iVar7 = *(int *)(unaff_EBP + 8);
        FUN_00413a14(iVar7,iVar6,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 8),0);
        iVar6 = uVar1 * 0x15c + iVar7;
        for (; iVar7 != iVar6; iVar7 = iVar7 + 0x15c) {
          FUN_0041376e(unaff_EBP + -0x178);
        }
      }
      else {
        FUN_00413aac(iVar7,uVar1 - uVar2,unaff_EBP + -0x178,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + (uVar1 - uVar2) * 0x15c;
        iVar7 = *(int *)(unaff_EBP + 8);
        FUN_00413a4a(iVar7,*(undefined4 *)(unaff_EBP + 0xc),extraout_ECX[1],
                     *(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar2 * 0x15c;
        if (iVar7 != *(int *)(unaff_EBP + 0xc)) {
          do {
            FUN_0041376e(unaff_EBP + -0x178);
            iVar7 = iVar7 + 0x15c;
          } while (iVar7 != *(int *)(unaff_EBP + 0xc));
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

