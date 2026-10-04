
void FUN_004082fc(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int *extraout_ECX;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int unaff_EBP;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  if (uVar1 != 0) {
    iVar9 = extraout_ECX[1];
    if ((uint)(extraout_ECX[2] - iVar9 >> 5) < uVar1) {
      uVar2 = iVar9 - *extraout_ECX >> 5;
      *(uint *)(unaff_EBP + -0x14) = uVar2;
      piVar5 = (int *)(unaff_EBP + 0xc);
      if (uVar1 <= uVar2) {
        piVar5 = (int *)(unaff_EBP + -0x14);
      }
      iVar9 = *piVar5 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x18) = iVar9;
      if (iVar9 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_00401742(iVar9 * 0x20);
      }
      iVar8 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar3;
      *(int *)(unaff_EBP + -0x1c) = iVar3;
      uVar6 = FUN_005d222e(iVar8,*(undefined4 *)(unaff_EBP + 8),iVar3,*(undefined4 *)(unaff_EBP + 8)
                          );
      uVar6 = FUN_004088de(uVar6,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar6 = FUN_005d222e(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar6,
                           *(undefined4 *)(unaff_EBP + 8));
      iVar8 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 8) = uVar6;
      for (iVar7 = *extraout_ECX; iVar7 != iVar8; iVar7 = iVar7 + 0x20) {
      }
      iVar8 = extraout_ECX[2] - *extraout_ECX >> 5;
      if (iVar8 != 0) {
        FUN_0040189d(*extraout_ECX,iVar8 << 5);
      }
      iVar8 = *(int *)(unaff_EBP + 8);
      *extraout_ECX = iVar3;
      extraout_ECX[1] = iVar8;
      extraout_ECX[2] = iVar9 * 0x20 + iVar3;
    }
    else {
      iVar3 = *(int *)(unaff_EBP + 8);
      puVar4 = *(undefined4 **)(unaff_EBP + 0x10);
      puVar10 = (undefined4 *)(unaff_EBP + -0x3c);
      for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar10 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar10 = puVar10 + 1;
      }
      puVar4 = (undefined4 *)extraout_ECX[1];
      uVar2 = iVar9 - iVar3 >> 5;
      *(undefined4 **)(unaff_EBP + 0xc) = puVar4;
      if (uVar1 < uVar2) {
        *(undefined4 **)(unaff_EBP + 0xc) = puVar4;
        iVar9 = uVar1 * 0x20;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar1 * -0x20;
        *(int *)(unaff_EBP + 0x10) = iVar9;
        FUN_005d222e(*(undefined4 *)(unaff_EBP + 0xc),puVar4,puVar4,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + iVar9;
        puVar10 = *(undefined4 **)(unaff_EBP + 0xc);
        iVar3 = (int)puVar10 - *(int *)(unaff_EBP + 8) >> 5;
        if (0 < iVar3) {
          do {
            puVar4 = puVar4 + -8;
            puVar10 = puVar10 + -8;
            iVar3 = iVar3 + -1;
            puVar11 = puVar10;
            puVar12 = puVar4;
            for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar12 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar12 = puVar12 + 1;
            }
          } while (iVar3 != 0);
          iVar9 = *(int *)(unaff_EBP + 0x10);
        }
        puVar10 = *(undefined4 **)(unaff_EBP + 8);
        puVar4 = (undefined4 *)(iVar9 + (int)puVar10);
        for (; puVar10 != puVar4; puVar10 = puVar10 + 8) {
          puVar11 = (undefined4 *)(unaff_EBP + -0x3c);
          puVar12 = puVar10;
          for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
          }
        }
      }
      else {
        FUN_004088de(*(undefined4 *)(unaff_EBP + 0xc),uVar1 - uVar2,unaff_EBP + -0x3c,
                     *(undefined4 *)(unaff_EBP + 8));
        uVar6 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar1 - uVar2) * 0x20;
        puVar4 = *(undefined4 **)(unaff_EBP + 8);
        FUN_005d222e(puVar4,*(undefined4 *)(unaff_EBP + 0xc),extraout_ECX[1],uVar6);
        extraout_ECX[1] = extraout_ECX[1] + uVar2 * 0x20;
        if (puVar4 != *(undefined4 **)(unaff_EBP + 0xc)) {
          do {
            puVar12 = puVar4 + 8;
            puVar10 = *(undefined4 **)(unaff_EBP + 0xc);
            puVar11 = (undefined4 *)(unaff_EBP + -0x3c);
            for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar4 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar4 = puVar4 + 1;
            }
            puVar4 = puVar12;
          } while (puVar12 != puVar10);
        }
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

