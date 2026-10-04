
void FUN_0046e7f4(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *extraout_ECX;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int unaff_EBP;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  
  FUN_00634c24();
  iVar11 = 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff9c;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x48) < *(uint *)(unaff_EBP + 0xc)) {
      uVar3 = (extraout_ECX[1] - *extraout_ECX) / 0x48;
      piVar4 = (int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + -0x14) = uVar3;
      if (*(uint *)(unaff_EBP + 0xc) <= uVar3) {
        piVar4 = (int *)(unaff_EBP + -0x14);
      }
      iVar8 = *piVar4 + uVar3;
      *(int *)(unaff_EBP + -0x18) = iVar8;
      if (iVar8 != 0) {
        iVar11 = FUN_00401742(iVar8 * 0x48);
      }
      iVar7 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar11;
      *(int *)(unaff_EBP + -0x1c) = iVar11;
      uVar5 = FUN_0046e9fb(iVar7,*(undefined4 *)(unaff_EBP + 8),iVar11,
                           *(undefined4 *)(unaff_EBP + 8));
      uVar5 = FUN_0046ea27(uVar5,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar5 = FUN_0046e9fb(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar5,
                           *(undefined4 *)(unaff_EBP + 8));
      iVar7 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 8) = uVar5;
      for (iVar6 = *extraout_ECX; iVar6 != iVar7; iVar6 = iVar6 + 0x48) {
      }
      iVar7 = (extraout_ECX[2] - *extraout_ECX) / 0x48;
      if (iVar7 != 0) {
        FUN_0040189d(*extraout_ECX,iVar7 * 0x48);
      }
      iVar7 = *(int *)(unaff_EBP + 8);
      *extraout_ECX = iVar11;
      extraout_ECX[1] = iVar7;
      extraout_ECX[2] = iVar11 + iVar8 * 0x48;
    }
    else {
      iVar11 = extraout_ECX[1];
      iVar8 = *(int *)(unaff_EBP + 8);
      puVar9 = *(undefined4 **)(unaff_EBP + 0x10);
      puVar2 = (undefined4 *)(unaff_EBP + -100);
      for (iVar7 = 0x12; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar2 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar2 = puVar2 + 1;
      }
      uVar3 = *(uint *)(unaff_EBP + 0xc);
      puVar9 = (undefined4 *)extraout_ECX[1];
      uVar1 = (iVar11 - iVar8) / 0x48;
      *(undefined4 **)(unaff_EBP + -0x14) = puVar9;
      *(uint *)(unaff_EBP + 0x10) = uVar1;
      if (uVar3 < uVar1) {
        iVar7 = uVar3 * 0x48;
        *(undefined4 **)(unaff_EBP + 0xc) = puVar9;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar3 * -0x48;
        *(int *)(unaff_EBP + 0x10) = iVar7;
        FUN_0046e9fb(*(undefined4 *)(unaff_EBP + 0xc),puVar9,puVar9,*(undefined4 *)(unaff_EBP + 8));
        iVar11 = *(int *)(unaff_EBP + 0xc);
        iVar8 = *(int *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + iVar7;
        iVar11 = (iVar11 - iVar8) / 0x48;
        if (0 < iVar11) {
          puVar2 = *(undefined4 **)(unaff_EBP + 0xc);
          do {
            puVar9 = puVar9 + -0x12;
            puVar2 = puVar2 + -0x12;
            iVar11 = iVar11 + -1;
            puVar10 = puVar2;
            puVar12 = puVar9;
            for (iVar8 = 0x12; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar12 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar12 = puVar12 + 1;
            }
          } while (iVar11 != 0);
          iVar7 = *(int *)(unaff_EBP + 0x10);
        }
        puVar2 = *(undefined4 **)(unaff_EBP + 8);
        puVar9 = (undefined4 *)(iVar7 + (int)puVar2);
        for (; puVar2 != puVar9; puVar2 = puVar2 + 0x12) {
          puVar10 = (undefined4 *)(unaff_EBP + -100);
          puVar12 = puVar2;
          for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar12 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar12 = puVar12 + 1;
          }
        }
      }
      else {
        FUN_0046ea27(puVar9,uVar3 - uVar1,unaff_EBP + -100,*(undefined4 *)(unaff_EBP + 8));
        uVar5 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar3 - uVar1) * 0x48;
        FUN_0046e9fb(*(undefined4 *)(unaff_EBP + 8),puVar9,extraout_ECX[1],uVar5);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0x10) * 0x48;
        puVar2 = *(undefined4 **)(unaff_EBP + 8);
        if (*(undefined4 **)(unaff_EBP + 8) != puVar9) {
          do {
            puVar12 = puVar2 + 0x12;
            puVar9 = *(undefined4 **)(unaff_EBP + -0x14);
            puVar10 = (undefined4 *)(unaff_EBP + -100);
            for (iVar11 = 0x12; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar2 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar2 = puVar2 + 1;
            }
            puVar2 = puVar12;
          } while (puVar12 != puVar9);
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

