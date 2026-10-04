
void FUN_005bb719(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int *extraout_ECX;
  int iVar9;
  int unaff_EBP;
  undefined4 *puVar10;
  
  FUN_00634c24();
  uVar2 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (uVar2 != 0) {
    iVar9 = extraout_ECX[1];
    if ((uint)(extraout_ECX[2] - iVar9 >> 2) < uVar2) {
      uVar3 = iVar9 - *extraout_ECX >> 2;
      *(uint *)(unaff_EBP + -0x14) = uVar3;
      piVar6 = (int *)(unaff_EBP + 0xc);
      if (uVar2 <= uVar3) {
        piVar6 = (int *)(unaff_EBP + -0x14);
      }
      iVar9 = *piVar6 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + 0xc) = iVar9;
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = FUN_00401742(iVar9 * 4);
      }
      iVar4 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar9;
      *(int *)(unaff_EBP + -0x18) = iVar9;
      uVar7 = FUN_00520ae5(iVar4,*(undefined4 *)(unaff_EBP + 8),iVar9,*(undefined4 *)(unaff_EBP + 8)
                          );
      uVar7 = FUN_005fd5b4(uVar7,uVar2,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      iVar8 = FUN_00520ae5(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar7,
                           *(undefined4 *)(unaff_EBP + 8));
      for (iVar4 = *extraout_ECX; iVar4 != extraout_ECX[1]; iVar4 = iVar4 + 4) {
      }
      iVar4 = extraout_ECX[2] - *extraout_ECX >> 2;
      if (iVar4 != 0) {
        FUN_0040189d(*extraout_ECX,iVar4 << 2);
      }
      iVar4 = *(int *)(unaff_EBP + 0xc);
      *extraout_ECX = iVar9;
      extraout_ECX[1] = iVar8;
      extraout_ECX[2] = iVar9 + iVar4 * 4;
    }
    else {
      puVar10 = (undefined4 *)extraout_ECX[1];
      uVar3 = iVar9 - *(int *)(unaff_EBP + 8) >> 2;
      *(undefined4 *)(unaff_EBP + 0x10) = **(undefined4 **)(unaff_EBP + 0x10);
      *(uint *)(unaff_EBP + 0xc) = uVar3;
      if (uVar2 < uVar3) {
        *(undefined4 **)(unaff_EBP + 0xc) = puVar10;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar2 * -4;
        FUN_00520ae5(*(undefined4 *)(unaff_EBP + 0xc),puVar10,puVar10,*(undefined4 *)(unaff_EBP + 8)
                    );
        iVar9 = *(int *)(unaff_EBP + 0xc);
        puVar5 = *(undefined4 **)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + uVar2 * 4;
        iVar4 = iVar9 - (int)puVar5 >> 2;
        if (0 < iVar4) {
          iVar9 = iVar9 - (int)puVar10;
          do {
            puVar1 = (undefined4 *)(iVar9 + -4 + (int)puVar10);
            puVar10 = puVar10 + -1;
            iVar4 = iVar4 + -1;
            *puVar10 = *puVar1;
          } while (iVar4 != 0);
        }
        puVar10 = puVar5 + uVar2;
        for (; puVar5 != puVar10; puVar5 = puVar5 + 1) {
          *puVar5 = *(undefined4 *)(unaff_EBP + 0x10);
        }
      }
      else {
        FUN_005fd5b4(puVar10,uVar2 - uVar3,unaff_EBP + 0x10,*(undefined4 *)(unaff_EBP + 8));
        uVar7 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (uVar2 - uVar3) * 4;
        FUN_00520ae5(*(undefined4 *)(unaff_EBP + 8),puVar10,extraout_ECX[1],uVar7);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 4;
        for (puVar5 = *(undefined4 **)(unaff_EBP + 8); puVar5 != puVar10; puVar5 = puVar5 + 1) {
          *puVar5 = *(undefined4 *)(unaff_EBP + 0x10);
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

