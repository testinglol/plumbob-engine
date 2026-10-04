
void FUN_004a3513(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar9;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  if (uVar1 != 0) {
    iVar6 = extraout_ECX[1];
    if ((uint)(extraout_ECX[2] - iVar6 >> 3) < uVar1) {
      uVar2 = iVar6 - *extraout_ECX >> 3;
      *(uint *)(unaff_EBP + -0x14) = uVar2;
      piVar5 = (int *)(unaff_EBP + 0xc);
      if (uVar1 <= uVar2) {
        piVar5 = (int *)(unaff_EBP + -0x14);
      }
      iVar6 = *piVar5 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + 0xc) = iVar6;
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_00401742(iVar6 * 8);
      }
      iVar3 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar6;
      *(int *)(unaff_EBP + -0x18) = iVar6;
      uVar7 = FUN_00424217(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar6,*(undefined4 *)(unaff_EBP + 8)
                          );
      uVar7 = FUN_0059d5d9(uVar7,uVar1,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      iVar8 = FUN_00424217(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar7,
                           *(undefined4 *)(unaff_EBP + 8));
      for (iVar3 = *extraout_ECX; iVar3 != extraout_ECX[1]; iVar3 = iVar3 + 8) {
      }
      iVar3 = extraout_ECX[2] - *extraout_ECX >> 3;
      if (iVar3 != 0) {
        FUN_0040189d(*extraout_ECX,iVar3 << 3);
      }
      iVar3 = *(int *)(unaff_EBP + 0xc);
      *extraout_ECX = iVar6;
      extraout_ECX[1] = iVar8;
      extraout_ECX[2] = iVar6 + iVar3 * 8;
    }
    else {
      puVar9 = (undefined4 *)extraout_ECX[1];
      uVar7 = (*(undefined4 **)(unaff_EBP + 0x10))[1];
      uVar2 = iVar6 - *(int *)(unaff_EBP + 8) >> 3;
      *(undefined4 *)(unaff_EBP + -0x1c) = **(undefined4 **)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar7;
      *(uint *)(unaff_EBP + 0xc) = uVar2;
      if (uVar1 < uVar2) {
        *(undefined4 **)(unaff_EBP + 0xc) = puVar9;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar1 * -8;
        FUN_00424217(*(undefined4 *)(unaff_EBP + 0xc),puVar9,puVar9,*(undefined4 *)(unaff_EBP + 8));
        iVar6 = *(int *)(unaff_EBP + 0xc);
        puVar4 = *(undefined4 **)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 8;
        iVar3 = iVar6 - (int)puVar4 >> 3;
        if (0 < iVar3) {
          do {
            iVar3 = iVar3 + -1;
            puVar9[-2] = *(undefined4 *)(iVar6 + -8);
            puVar9[-1] = *(undefined4 *)(iVar6 + -4);
            iVar6 = iVar6 + -8;
            puVar9 = puVar9 + -2;
          } while (iVar3 != 0);
        }
        puVar9 = puVar4 + uVar1 * 2;
        for (; puVar4 != puVar9; puVar4 = puVar4 + 2) {
          *puVar4 = *(undefined4 *)(unaff_EBP + -0x1c);
          puVar4[1] = *(undefined4 *)(unaff_EBP + -0x18);
        }
      }
      else {
        FUN_0059d5d9(puVar9,uVar1 - uVar2,unaff_EBP + -0x1c,*(undefined4 *)(unaff_EBP + 8));
        uVar7 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar1 - uVar2) * 8;
        FUN_00424217(*(undefined4 *)(unaff_EBP + 8),puVar9,extraout_ECX[1],uVar7);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 8;
        for (puVar4 = *(undefined4 **)(unaff_EBP + 8); puVar4 != puVar9; puVar4 = puVar4 + 2) {
          *puVar4 = *(undefined4 *)(unaff_EBP + -0x1c);
          puVar4[1] = *(undefined4 *)(unaff_EBP + -0x18);
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

