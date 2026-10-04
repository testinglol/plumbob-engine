
void FUN_0041b085(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *extraout_ECX;
  int *piVar5;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff8c;
  if (uVar1 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x5c) < uVar1) {
      uVar2 = (extraout_ECX[1] - *extraout_ECX) / 0x5c;
      piVar5 = (int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + -0x14) = uVar2;
      if (uVar1 <= uVar2) {
        piVar5 = (int *)(unaff_EBP + -0x14);
      }
      iVar7 = uVar2 + *piVar5;
      *(int *)(unaff_EBP + 0xc) = iVar7;
      if (iVar7 == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_00401742(iVar7 * 0x5c);
      }
      iVar6 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar7;
      *(int *)(unaff_EBP + -0x18) = iVar7;
      uVar3 = FUN_0041b618(iVar6,*(undefined4 *)(unaff_EBP + 8),iVar7,*(undefined4 *)(unaff_EBP + 8)
                          );
      uVar3 = FUN_0041b73d(uVar3,uVar1,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar3 = FUN_0041b618(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar3,
                           *(undefined4 *)(unaff_EBP + 8));
      iVar6 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + 8) = uVar3;
      for (iVar4 = *extraout_ECX; iVar4 != iVar6; iVar4 = iVar4 + 0x5c) {
      }
      iVar6 = (extraout_ECX[2] - *extraout_ECX) / 0x5c;
      if (iVar6 != 0) {
        FUN_0040189d(*extraout_ECX,iVar6 * 0x5c);
      }
      iVar6 = *(int *)(unaff_EBP + 8);
      *extraout_ECX = iVar7;
      extraout_ECX[1] = iVar6;
      extraout_ECX[2] = *(int *)(unaff_EBP + 0xc) * 0x5c + iVar7;
    }
    else {
      FUN_0041ae1b(*(undefined4 *)(unaff_EBP + 0x10));
      uVar2 = (extraout_ECX[1] - *(int *)(unaff_EBP + 8)) / 0x5c;
      iVar7 = extraout_ECX[1];
      *(int *)(unaff_EBP + 0xc) = iVar7;
      if (uVar1 < uVar2) {
        iVar6 = iVar7 + uVar1 * -0x5c;
        FUN_0041b618(iVar6,iVar7,iVar7,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 0x5c;
        iVar7 = *(int *)(unaff_EBP + 8);
        FUN_0041b584(iVar7,iVar6,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 8),0);
        iVar6 = uVar1 * 0x5c + iVar7;
        for (; iVar7 != iVar6; iVar7 = iVar7 + 0x5c) {
          FUN_0041ae54(unaff_EBP + -0x74);
        }
      }
      else {
        FUN_0041b73d(iVar7,uVar1 - uVar2,unaff_EBP + -0x74,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + (uVar1 - uVar2) * 0x5c;
        iVar7 = *(int *)(unaff_EBP + 8);
        FUN_0041b618(iVar7,*(undefined4 *)(unaff_EBP + 0xc),extraout_ECX[1],
                     *(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar2 * 0x5c;
        if (iVar7 != *(int *)(unaff_EBP + 0xc)) {
          do {
            FUN_0041ae54(unaff_EBP + -0x74);
            iVar7 = iVar7 + 0x5c;
          } while (iVar7 != *(int *)(unaff_EBP + 0xc));
        }
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

