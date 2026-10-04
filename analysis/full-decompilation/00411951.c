
void FUN_00411951(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  iVar10 = 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff90;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x54) < *(uint *)(unaff_EBP + 0xc)) {
      uVar3 = (extraout_ECX[1] - *extraout_ECX) / 0x54;
      *(uint *)(unaff_EBP + -0x14) = uVar3;
      piVar4 = (int *)(unaff_EBP + 0xc);
      if (*(uint *)(unaff_EBP + 0xc) <= uVar3) {
        piVar4 = (int *)(unaff_EBP + -0x14);
      }
      iVar8 = *piVar4 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x18) = iVar8;
      if (iVar8 != 0) {
        iVar10 = FUN_00401742(iVar8 * 0x54);
      }
      iVar7 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar10;
      *(int *)(unaff_EBP + -0x1c) = iVar10;
      uVar5 = FUN_00411b3c(iVar7,*(undefined4 *)(unaff_EBP + 8),iVar10,
                           *(undefined4 *)(unaff_EBP + 0xc));
      uVar5 = FUN_00411b68(uVar5,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 0xc));
      uVar5 = FUN_00411b3c(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar5,
                           *(undefined4 *)(unaff_EBP + 0xc));
      iVar7 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + 0xc) = uVar5;
      for (iVar6 = *extraout_ECX; iVar6 != iVar7; iVar6 = iVar6 + 0x54) {
      }
      iVar7 = (extraout_ECX[2] - *extraout_ECX) / 0x54;
      if (iVar7 != 0) {
        FUN_0040189d(*extraout_ECX,iVar7 * 0x54);
      }
      iVar7 = *(int *)(unaff_EBP + 0xc);
      *extraout_ECX = iVar10;
      extraout_ECX[1] = iVar7;
      extraout_ECX[2] = iVar8 * 0x54 + iVar10;
    }
    else {
      iVar10 = extraout_ECX[1];
      iVar8 = *(int *)(unaff_EBP + 8);
      puVar2 = *(undefined4 **)(unaff_EBP + 0x10);
      puVar11 = (undefined4 *)(unaff_EBP + -0x70);
      for (iVar7 = 0x15; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar11 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar11 = puVar11 + 1;
      }
      uVar3 = *(uint *)(unaff_EBP + 0xc);
      uVar1 = (iVar10 - iVar8) / 0x54;
      iVar10 = extraout_ECX[1];
      *(int *)(unaff_EBP + 0x10) = iVar10;
      if (uVar3 < uVar1) {
        iVar8 = uVar3 * 0x54;
        *(int *)(unaff_EBP + 0xc) = iVar8;
        puVar11 = (undefined4 *)(iVar10 + uVar3 * -0x54);
        FUN_00411b3c(puVar11,iVar10,iVar10,*(undefined4 *)(unaff_EBP + 0xc));
        iVar10 = *(int *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + iVar8;
        puVar2 = *(undefined4 **)(unaff_EBP + 0x10);
        iVar10 = ((int)puVar11 - iVar10) / 0x54;
        if (0 < iVar10) {
          do {
            puVar2 = puVar2 + -0x15;
            puVar11 = puVar11 + -0x15;
            iVar10 = iVar10 + -1;
            puVar9 = puVar11;
            puVar12 = puVar2;
            for (iVar8 = 0x15; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar12 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar12 = puVar12 + 1;
            }
          } while (iVar10 != 0);
          iVar8 = *(int *)(unaff_EBP + 0xc);
        }
        puVar11 = *(undefined4 **)(unaff_EBP + 8);
        puVar2 = (undefined4 *)(iVar8 + (int)puVar11);
        for (; puVar11 != puVar2; puVar11 = puVar11 + 0x15) {
          puVar9 = (undefined4 *)(unaff_EBP + -0x70);
          puVar12 = puVar11;
          for (iVar10 = 0x15; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar12 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar12 = puVar12 + 1;
          }
        }
      }
      else {
        FUN_00411b68(iVar10,uVar3 - uVar1,unaff_EBP + -0x70,*(undefined4 *)(unaff_EBP + 0xc));
        extraout_ECX[1] = extraout_ECX[1] + (uVar3 - uVar1) * 0x54;
        puVar2 = *(undefined4 **)(unaff_EBP + 8);
        FUN_00411b3c(puVar2,*(undefined4 *)(unaff_EBP + 0x10),extraout_ECX[1],
                     *(undefined4 *)(unaff_EBP + 0xc));
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 0x54;
        if (puVar2 != *(undefined4 **)(unaff_EBP + 0x10)) {
          do {
            puVar12 = puVar2 + 0x15;
            puVar11 = *(undefined4 **)(unaff_EBP + 0x10);
            puVar9 = (undefined4 *)(unaff_EBP + -0x70);
            for (iVar10 = 0x15; iVar10 != 0; iVar10 = iVar10 + -1) {
              *puVar2 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar2 = puVar2 + 1;
            }
            puVar2 = puVar12;
          } while (puVar12 != puVar11);
        }
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

