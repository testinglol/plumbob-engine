
void FUN_00460f1a(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int *extraout_ECX;
  undefined4 *puVar10;
  int unaff_EBP;
  int iVar11;
  
  FUN_00634c24();
  uVar2 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd8;
  if (uVar2 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0xc) < uVar2) {
      uVar3 = (extraout_ECX[1] - *extraout_ECX) / 0xc;
      *(uint *)(unaff_EBP + -0x14) = uVar3;
      piVar6 = (int *)(unaff_EBP + 0xc);
      if (uVar2 <= uVar3) {
        piVar6 = (int *)(unaff_EBP + -0x14);
      }
      iVar4 = *piVar6 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x18) = iVar4;
      if (iVar4 == 0) {
        iVar11 = 0;
      }
      else {
        iVar11 = FUN_00401742(iVar4 * 0xc);
      }
      iVar9 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar11;
      *(int *)(unaff_EBP + -0x1c) = iVar11;
      uVar7 = FUN_005f0ae8(iVar9,*(undefined4 *)(unaff_EBP + 8),iVar11,
                           *(undefined4 *)(unaff_EBP + 8));
      uVar7 = FUN_00461407(uVar7,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      uVar7 = FUN_005f0ae8(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar7,
                           *(undefined4 *)(unaff_EBP + 8));
      iVar9 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + 8) = uVar7;
      for (iVar8 = *extraout_ECX; iVar8 != iVar9; iVar8 = iVar8 + 0xc) {
      }
      iVar9 = (extraout_ECX[2] - *extraout_ECX) / 0xc;
      if (iVar9 != 0) {
        FUN_0040189d(*extraout_ECX,iVar9 * 0xc);
      }
      iVar9 = *(int *)(unaff_EBP + 8);
      *extraout_ECX = iVar11;
      extraout_ECX[1] = iVar9;
      extraout_ECX[2] = iVar11 + iVar4 * 0xc;
    }
    else {
      puVar10 = *(undefined4 **)(unaff_EBP + 0x10);
      iVar4 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -0x28) = *puVar10;
      *(undefined4 *)(unaff_EBP + -0x24) = puVar10[1];
      *(undefined4 *)(unaff_EBP + -0x20) = puVar10[2];
      puVar10 = (undefined4 *)extraout_ECX[1];
      uVar3 = (iVar4 - *(int *)(unaff_EBP + 8)) / 0xc;
      *(undefined4 **)(unaff_EBP + 0x10) = puVar10;
      *(uint *)(unaff_EBP + 0xc) = uVar3;
      if (uVar2 < uVar3) {
        iVar11 = uVar2 * 0xc;
        *(undefined4 **)(unaff_EBP + 0xc) = puVar10;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar2 * -0xc;
        *(int *)(unaff_EBP + 0x10) = iVar11;
        FUN_005f0ae8(*(undefined4 *)(unaff_EBP + 0xc),puVar10,puVar10,*(undefined4 *)(unaff_EBP + 8)
                    );
        iVar4 = *(int *)(unaff_EBP + 0xc);
        extraout_ECX[1] = extraout_ECX[1] + iVar11;
        iVar4 = (iVar4 - *(int *)(unaff_EBP + 8)) / 0xc;
        if (0 < iVar4) {
          puVar5 = *(undefined4 **)(unaff_EBP + 0xc);
          do {
            puVar10[-3] = puVar5[-3];
            puVar10[-2] = puVar5[-2];
            iVar4 = iVar4 + -1;
            puVar10[-1] = puVar5[-1];
            puVar10 = puVar10 + -3;
            puVar5 = puVar5 + -3;
          } while (iVar4 != 0);
          iVar11 = *(int *)(unaff_EBP + 0x10);
        }
        puVar5 = *(undefined4 **)(unaff_EBP + 8);
        puVar10 = (undefined4 *)(iVar11 + (int)puVar5);
        for (; puVar5 != puVar10; puVar5 = puVar5 + 3) {
          *puVar5 = *(undefined4 *)(unaff_EBP + -0x28);
          puVar5[1] = *(undefined4 *)(unaff_EBP + -0x24);
          puVar5[2] = *(undefined4 *)(unaff_EBP + -0x20);
        }
      }
      else {
        FUN_00461407(puVar10,uVar2 - uVar3,unaff_EBP + -0x28,*(undefined4 *)(unaff_EBP + 8));
        uVar7 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar2 - uVar3) * 0xc;
        FUN_005f0ae8(*(undefined4 *)(unaff_EBP + 8),puVar10,extraout_ECX[1],uVar7);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 0xc;
        puVar5 = *(undefined4 **)(unaff_EBP + 8);
        if (puVar5 != puVar10) {
          do {
            *puVar5 = *(undefined4 *)(unaff_EBP + -0x28);
            puVar1 = puVar5 + 2;
            puVar5[1] = *(undefined4 *)(unaff_EBP + -0x24);
            puVar5 = puVar5 + 3;
            puVar10 = *(undefined4 **)(unaff_EBP + 0x10);
            *puVar1 = *(undefined4 *)(unaff_EBP + -0x20);
          } while (puVar5 != puVar10);
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

