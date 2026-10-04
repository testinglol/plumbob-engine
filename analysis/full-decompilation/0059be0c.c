
void FUN_0059be0c(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  int *extraout_ECX;
  undefined4 *puVar10;
  int unaff_EBP;
  int iVar11;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar2 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd8;
  if (uVar2 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0xc) < uVar2) {
      uVar4 = (extraout_ECX[1] - *extraout_ECX) / 0xc;
      *(uint *)(unaff_EBP + -0x14) = uVar4;
      piVar7 = (int *)(unaff_EBP + 0xc);
      if (uVar2 <= uVar4) {
        piVar7 = (int *)(unaff_EBP + -0x14);
      }
      iVar5 = *piVar7 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x18) = iVar5;
      if (iVar5 == 0) {
        iVar11 = 0;
      }
      else {
        iVar11 = FUN_0041e684(iVar5 * 0x90);
      }
      iVar3 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar11;
      *(int *)(unaff_EBP + -0x1c) = iVar11;
      uVar8 = FUN_005f0ae8(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar11,
                           *(undefined4 *)(unaff_EBP + 8));
      uVar8 = FUN_00461407(uVar8,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar8 = FUN_005f0ae8(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar8,
                           *(undefined4 *)(unaff_EBP + 8));
      iVar3 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + 8) = uVar8;
      for (iVar9 = *extraout_ECX; iVar9 != iVar3; iVar9 = iVar9 + 0xc) {
      }
      if ((extraout_ECX[2] - *extraout_ECX) / 0xc != 0) {
        FUN_0041d9a9(*extraout_ECX);
      }
      iVar3 = *(int *)(unaff_EBP + 8);
      *extraout_ECX = iVar11;
      extraout_ECX[1] = iVar3;
      extraout_ECX[2] = iVar11 + iVar5 * 0xc;
    }
    else {
      puVar10 = *(undefined4 **)(unaff_EBP + 0x10);
      iVar5 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -0x28) = *puVar10;
      *(undefined4 *)(unaff_EBP + -0x24) = puVar10[1];
      *(undefined4 *)(unaff_EBP + -0x20) = puVar10[2];
      puVar10 = (undefined4 *)extraout_ECX[1];
      uVar4 = (iVar5 - *(int *)(unaff_EBP + 8)) / 0xc;
      *(undefined4 **)(unaff_EBP + 0x10) = puVar10;
      *(uint *)(unaff_EBP + 0xc) = uVar4;
      if (uVar2 < uVar4) {
        iVar11 = uVar2 * 0xc;
        *(undefined4 **)(unaff_EBP + 0xc) = puVar10;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar2 * -0xc;
        *(int *)(unaff_EBP + 0x10) = iVar11;
        FUN_005f0ae8(*(undefined4 *)(unaff_EBP + 0xc),puVar10,puVar10,*(undefined4 *)(unaff_EBP + 8)
                    );
        iVar5 = *(int *)(unaff_EBP + 0xc);
        extraout_ECX[1] = extraout_ECX[1] + iVar11;
        iVar5 = (iVar5 - *(int *)(unaff_EBP + 8)) / 0xc;
        if (0 < iVar5) {
          puVar6 = *(undefined4 **)(unaff_EBP + 0xc);
          do {
            puVar10[-3] = puVar6[-3];
            puVar10[-2] = puVar6[-2];
            iVar5 = iVar5 + -1;
            puVar10[-1] = puVar6[-1];
            puVar10 = puVar10 + -3;
            puVar6 = puVar6 + -3;
          } while (iVar5 != 0);
          iVar11 = *(int *)(unaff_EBP + 0x10);
        }
        puVar6 = *(undefined4 **)(unaff_EBP + 8);
        puVar10 = (undefined4 *)(iVar11 + (int)puVar6);
        for (; puVar6 != puVar10; puVar6 = puVar6 + 3) {
          *puVar6 = *(undefined4 *)(unaff_EBP + -0x28);
          puVar6[1] = *(undefined4 *)(unaff_EBP + -0x24);
          puVar6[2] = *(undefined4 *)(unaff_EBP + -0x20);
        }
      }
      else {
        FUN_00461407(puVar10,uVar2 - uVar4,unaff_EBP + -0x28,*(undefined4 *)(unaff_EBP + 8));
        uVar8 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar2 - uVar4) * 0xc;
        FUN_005f0ae8(*(undefined4 *)(unaff_EBP + 8),puVar10,extraout_ECX[1],uVar8);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 0xc;
        puVar6 = *(undefined4 **)(unaff_EBP + 8);
        if (puVar6 != puVar10) {
          do {
            *puVar6 = *(undefined4 *)(unaff_EBP + -0x28);
            puVar1 = puVar6 + 2;
            puVar6[1] = *(undefined4 *)(unaff_EBP + -0x24);
            puVar6 = puVar6 + 3;
            puVar10 = *(undefined4 **)(unaff_EBP + 0x10);
            *puVar1 = *(undefined4 *)(unaff_EBP + -0x20);
          } while (puVar6 != puVar10);
        }
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

