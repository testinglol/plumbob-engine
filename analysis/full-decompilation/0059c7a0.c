
void FUN_0059c7a0(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  if (uVar1 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x18) < uVar1) {
      uVar2 = (extraout_ECX[1] - *extraout_ECX) / 0x18;
      *(uint *)(unaff_EBP + -0x14) = uVar2;
      piVar3 = (int *)(unaff_EBP + 0xc);
      if (uVar1 <= uVar2) {
        piVar3 = (int *)(unaff_EBP + -0x14);
      }
      iVar6 = *piVar3 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x14) = iVar6;
      if (iVar6 == 0) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
      }
      else {
        uVar4 = FUN_0041e684(iVar6 * 0x240);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
      }
      iVar7 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar4 = FUN_0059d626(iVar7,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar4 = FUN_0059d671(uVar4,uVar1,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar4 = FUN_0059d626(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar4,
                           *(undefined4 *)(unaff_EBP + 8));
      iVar7 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + 8) = uVar4;
      for (iVar5 = *extraout_ECX; iVar5 != iVar7; iVar5 = iVar5 + 0x18) {
      }
      if ((extraout_ECX[2] - *extraout_ECX) / 0x18 != 0) {
        FUN_0041d9a9(*extraout_ECX);
      }
      iVar7 = *(int *)(unaff_EBP + 0xc);
      extraout_ECX[1] = *(int *)(unaff_EBP + 8);
      *extraout_ECX = iVar7;
      extraout_ECX[2] = iVar7 + iVar6 * 0x18;
    }
    else {
      iVar6 = *(int *)(unaff_EBP + 0x10);
      FUN_00462be8(iVar6);
      FUN_00462be8(iVar6 + 0xc);
      iVar6 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar7 = extraout_ECX[1];
      uVar2 = (iVar6 - *(int *)(unaff_EBP + 8)) / 0x18;
      *(uint *)(unaff_EBP + 0xc) = uVar2;
      if (uVar1 < uVar2) {
        *(int *)(unaff_EBP + 0xc) = iVar7;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar1 * -0x18;
        FUN_0059d626(*(undefined4 *)(unaff_EBP + 0xc),iVar7,iVar7,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 0x18;
        iVar6 = *(int *)(unaff_EBP + 8);
        FUN_0059d57e(iVar6,*(undefined4 *)(unaff_EBP + 0xc),iVar7,*(undefined4 *)(unaff_EBP + 8),0);
        iVar7 = uVar1 * 0x18 + iVar6;
        for (; iVar6 != iVar7; iVar6 = iVar6 + 0x18) {
          FUN_00462be8(unaff_EBP + -0x30);
          FUN_00462be8(unaff_EBP + -0x24);
        }
      }
      else {
        FUN_0059d671(iVar7,uVar1 - uVar2,unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + 8));
        uVar4 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar1 - uVar2) * 0x18;
        FUN_0059d626(*(undefined4 *)(unaff_EBP + 8),iVar7,extraout_ECX[1],uVar4);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 0x18;
        FUN_0059d4e3(*(undefined4 *)(unaff_EBP + 8),iVar7,unaff_EBP + -0x30);
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

