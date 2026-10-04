
void FUN_005d1c60(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar10;
  undefined4 *unaff_FS_OFFSET;
  
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
      uVar7 = FUN_005d2342(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar6,*(undefined4 *)(unaff_EBP + 8)
                          );
      uVar7 = FUN_005d236e(uVar7,uVar1,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      iVar8 = FUN_005d2342(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar7,
                           *(undefined4 *)(unaff_EBP + 8));
      iVar3 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      for (iVar9 = *extraout_ECX; iVar9 != iVar3; iVar9 = iVar9 + 8) {
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
      puVar10 = (undefined4 *)extraout_ECX[1];
      uVar7 = (*(undefined4 **)(unaff_EBP + 0x10))[1];
      uVar2 = iVar6 - *(int *)(unaff_EBP + 8) >> 3;
      *(undefined4 *)(unaff_EBP + -0x1c) = **(undefined4 **)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar7;
      *(uint *)(unaff_EBP + 0xc) = uVar2;
      if (uVar1 < uVar2) {
        *(undefined4 **)(unaff_EBP + 0xc) = puVar10;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar1 * -8;
        FUN_005d2342(*(undefined4 *)(unaff_EBP + 0xc),puVar10,puVar10,*(undefined4 *)(unaff_EBP + 8)
                    );
        iVar6 = *(int *)(unaff_EBP + 0xc);
        puVar4 = *(undefined4 **)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 8;
        iVar3 = iVar6 - (int)puVar4 >> 3;
        if (0 < iVar3) {
          do {
            iVar3 = iVar3 + -1;
            puVar10[-2] = *(undefined4 *)(iVar6 + -8);
            puVar10[-1] = *(undefined4 *)(iVar6 + -4);
            iVar6 = iVar6 + -8;
            puVar10 = puVar10 + -2;
          } while (iVar3 != 0);
        }
        puVar10 = puVar4 + uVar1 * 2;
        for (; puVar4 != puVar10; puVar4 = puVar4 + 2) {
          *puVar4 = *(undefined4 *)(unaff_EBP + -0x1c);
          puVar4[1] = *(undefined4 *)(unaff_EBP + -0x18);
        }
      }
      else {
        FUN_005d236e(puVar10,uVar1 - uVar2,unaff_EBP + -0x1c,*(undefined4 *)(unaff_EBP + 8));
        uVar7 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar1 - uVar2) * 8;
        FUN_005d2342(*(undefined4 *)(unaff_EBP + 8),puVar10,extraout_ECX[1],uVar7);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 8;
        for (puVar4 = *(undefined4 **)(unaff_EBP + 8); puVar4 != puVar10; puVar4 = puVar4 + 2) {
          *puVar4 = *(undefined4 *)(unaff_EBP + -0x1c);
          puVar4[1] = *(undefined4 *)(unaff_EBP + -0x18);
        }
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

