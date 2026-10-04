
void FUN_0041882b(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff98;
  if (uVar1 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x50) < uVar1) {
      uVar2 = (extraout_ECX[1] - *extraout_ECX) / 0x50;
      *(uint *)(unaff_EBP + -0x14) = uVar2;
      piVar3 = (int *)(unaff_EBP + 0xc);
      if (uVar1 <= uVar2) {
        piVar3 = (int *)(unaff_EBP + -0x14);
      }
      iVar7 = *piVar3 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x14) = iVar7;
      if (iVar7 == 0) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
      }
      else {
        uVar4 = FUN_00401742(iVar7 * 0x50);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
      }
      iVar6 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar4 = FUN_00418ab9(iVar6,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar4 = FUN_00418b20(uVar4,uVar1,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar4 = FUN_00418ab9(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar4,
                           *(undefined4 *)(unaff_EBP + 8));
      iVar6 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 8) = uVar4;
      for (iVar5 = *extraout_ECX; iVar5 != iVar6; iVar5 = iVar5 + 0x50) {
      }
      iVar6 = (extraout_ECX[2] - *extraout_ECX) / 0x50;
      if (iVar6 != 0) {
        FUN_0040189d(*extraout_ECX,iVar6 * 0x50);
      }
      iVar6 = *(int *)(unaff_EBP + 0xc);
      extraout_ECX[1] = *(int *)(unaff_EBP + 8);
      *extraout_ECX = iVar6;
      extraout_ECX[2] = iVar7 * 0x50 + iVar6;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x68) = **(undefined4 **)(unaff_EBP + 0x10);
      FUN_004030b4(*(undefined4 **)(unaff_EBP + 0x10) + 1);
      iVar7 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0;
      puVar9 = (undefined4 *)extraout_ECX[1];
      uVar2 = (iVar7 - *(int *)(unaff_EBP + 8)) / 0x50;
      *(uint *)(unaff_EBP + 0xc) = uVar2;
      if (uVar1 < uVar2) {
        *(undefined4 **)(unaff_EBP + 0xc) = puVar9;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar1 * -0x50;
        FUN_00418ab9(*(undefined4 *)(unaff_EBP + 0xc),puVar9,puVar9,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 0x50;
        puVar8 = *(undefined4 **)(unaff_EBP + 8);
        FUN_00418a68(puVar8,*(undefined4 *)(unaff_EBP + 0xc),puVar9,*(undefined4 *)(unaff_EBP + 8),0
                    );
        puVar9 = puVar8 + uVar1 * 0x14;
        for (; puVar8 != puVar9; puVar8 = puVar8 + 0x14) {
          *puVar8 = *(undefined4 *)(unaff_EBP + -0x68);
          FUN_0046f8e4(unaff_EBP + -100);
        }
      }
      else {
        FUN_00418b20(puVar9,uVar1 - uVar2,unaff_EBP + -0x68,*(undefined4 *)(unaff_EBP + 8));
        uVar4 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar1 - uVar2) * 0x50;
        FUN_00418ab9(*(undefined4 *)(unaff_EBP + 8),puVar9,extraout_ECX[1],uVar4);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 0x50;
        for (puVar8 = *(undefined4 **)(unaff_EBP + 8); puVar8 != puVar9; puVar8 = puVar8 + 0x14) {
          *puVar8 = *(undefined4 *)(unaff_EBP + -0x68);
          FUN_0046f8e4(unaff_EBP + -100);
        }
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

