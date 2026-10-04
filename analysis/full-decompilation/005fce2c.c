
void FUN_005fce2c(void)

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
  int iVar10;
  int unaff_EBP;
  undefined4 *puVar11;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar2 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (uVar2 != 0) {
    iVar10 = extraout_ECX[1];
    if ((uint)(extraout_ECX[2] - iVar10 >> 2) < uVar2) {
      uVar3 = iVar10 - *extraout_ECX >> 2;
      *(uint *)(unaff_EBP + -0x14) = uVar3;
      piVar6 = (int *)(unaff_EBP + 0xc);
      if (uVar2 <= uVar3) {
        piVar6 = (int *)(unaff_EBP + -0x14);
      }
      iVar10 = *piVar6 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + 0xc) = iVar10;
      if (iVar10 == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = FUN_00401742(iVar10 * 4);
      }
      iVar4 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar10;
      *(int *)(unaff_EBP + -0x18) = iVar10;
      uVar7 = FUN_00520ae5(iVar4,*(undefined4 *)(unaff_EBP + 8),iVar10,
                           *(undefined4 *)(unaff_EBP + 8));
      uVar7 = FUN_005fd5b4(uVar7,uVar2,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      iVar8 = FUN_00520ae5(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar7,
                           *(undefined4 *)(unaff_EBP + 8));
      iVar4 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      for (iVar9 = *extraout_ECX; iVar9 != iVar4; iVar9 = iVar9 + 4) {
      }
      iVar4 = extraout_ECX[2] - *extraout_ECX >> 2;
      if (iVar4 != 0) {
        FUN_0040189d(*extraout_ECX,iVar4 << 2);
      }
      iVar4 = *(int *)(unaff_EBP + 0xc);
      *extraout_ECX = iVar10;
      extraout_ECX[1] = iVar8;
      extraout_ECX[2] = iVar10 + iVar4 * 4;
    }
    else {
      puVar11 = (undefined4 *)extraout_ECX[1];
      uVar3 = iVar10 - *(int *)(unaff_EBP + 8) >> 2;
      *(undefined4 *)(unaff_EBP + 0x10) = **(undefined4 **)(unaff_EBP + 0x10);
      *(uint *)(unaff_EBP + 0xc) = uVar3;
      if (uVar2 < uVar3) {
        *(undefined4 **)(unaff_EBP + 0xc) = puVar11;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar2 * -4;
        FUN_00520ae5(*(undefined4 *)(unaff_EBP + 0xc),puVar11,puVar11,*(undefined4 *)(unaff_EBP + 8)
                    );
        iVar10 = *(int *)(unaff_EBP + 0xc);
        puVar5 = *(undefined4 **)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + uVar2 * 4;
        iVar4 = iVar10 - (int)puVar5 >> 2;
        if (0 < iVar4) {
          iVar10 = iVar10 - (int)puVar11;
          do {
            puVar1 = (undefined4 *)(iVar10 + -4 + (int)puVar11);
            puVar11 = puVar11 + -1;
            iVar4 = iVar4 + -1;
            *puVar11 = *puVar1;
          } while (iVar4 != 0);
        }
        puVar11 = puVar5 + uVar2;
        for (; puVar5 != puVar11; puVar5 = puVar5 + 1) {
          *puVar5 = *(undefined4 *)(unaff_EBP + 0x10);
        }
      }
      else {
        FUN_005fd5b4(puVar11,uVar2 - uVar3,unaff_EBP + 0x10,*(undefined4 *)(unaff_EBP + 8));
        uVar7 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar2 - uVar3) * 4;
        FUN_00520ae5(*(undefined4 *)(unaff_EBP + 8),puVar11,extraout_ECX[1],uVar7);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 4;
        for (puVar5 = *(undefined4 **)(unaff_EBP + 8); puVar5 != puVar11; puVar5 = puVar5 + 1) {
          *puVar5 = *(undefined4 *)(unaff_EBP + 0x10);
        }
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

