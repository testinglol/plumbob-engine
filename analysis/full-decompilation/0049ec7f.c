
void FUN_0049ec7f(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int *extraout_ECX;
  int iVar9;
  int unaff_EBP;
  uint uVar10;
  
  FUN_00634c24();
  uVar10 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (uVar10 != 0) {
    iVar9 = extraout_ECX[1];
    if ((uint)(extraout_ECX[2] - iVar9 >> 2) < uVar10) {
      uVar2 = iVar9 - *extraout_ECX >> 2;
      *(uint *)(unaff_EBP + -0x14) = uVar2;
      piVar5 = (int *)(unaff_EBP + 0xc);
      if (uVar10 <= uVar2) {
        piVar5 = (int *)(unaff_EBP + -0x14);
      }
      iVar9 = *piVar5 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x14) = iVar9;
      if (iVar9 == 0) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
      }
      else {
        uVar6 = FUN_00401742(iVar9 * 4);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar6;
      }
      iVar3 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      puVar7 = (undefined4 *)
               FUN_00430957(iVar3,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                            *(undefined4 *)(unaff_EBP + 8),0);
      for (; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar7 = **(undefined4 **)(unaff_EBP + 0x10);
        puVar7 = puVar7 + 1;
      }
      iVar3 = FUN_00430957(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar7,
                           *(undefined4 *)(unaff_EBP + 8),0);
      iVar8 = extraout_ECX[2] - *extraout_ECX >> 2;
      if (iVar8 != 0) {
        FUN_0040189d(*extraout_ECX,iVar8 << 2);
      }
      iVar8 = *(int *)(unaff_EBP + 0xc);
      extraout_ECX[1] = iVar3;
      *extraout_ECX = iVar8;
      extraout_ECX[2] = iVar8 + iVar9 * 4;
    }
    else {
      puVar7 = (undefined4 *)extraout_ECX[1];
      uVar2 = iVar9 - *(int *)(unaff_EBP + 8) >> 2;
      *(undefined4 *)(unaff_EBP + 0x10) = **(undefined4 **)(unaff_EBP + 0x10);
      *(uint *)(unaff_EBP + 0xc) = uVar2;
      if (uVar10 < uVar2) {
        *(undefined4 **)(unaff_EBP + 0xc) = puVar7;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar10 * -4;
        FUN_00430957(*(undefined4 *)(unaff_EBP + 0xc),puVar7,puVar7,*(undefined4 *)(unaff_EBP + 8),0
                    );
        iVar9 = *(int *)(unaff_EBP + 0xc);
        puVar4 = *(undefined4 **)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + uVar10 * 4;
        iVar3 = iVar9 - (int)puVar4 >> 2;
        if (0 < iVar3) {
          iVar9 = iVar9 - (int)puVar7;
          do {
            puVar1 = (undefined4 *)(iVar9 + -4 + (int)puVar7);
            puVar7 = puVar7 + -1;
            iVar3 = iVar3 + -1;
            *puVar7 = *puVar1;
          } while (iVar3 != 0);
        }
        puVar7 = puVar4 + uVar10;
        for (; puVar4 != puVar7; puVar4 = puVar4 + 1) {
          *puVar4 = *(undefined4 *)(unaff_EBP + 0x10);
        }
      }
      else {
        iVar9 = uVar10 - uVar2;
        if (iVar9 != 0) {
          uVar6 = *(undefined4 *)(unaff_EBP + 0x10);
          puVar4 = puVar7;
          for (iVar3 = iVar9; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar4 = uVar6;
            puVar4 = puVar4 + 1;
          }
        }
        uVar6 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + iVar9 * 4;
        FUN_00430957(*(undefined4 *)(unaff_EBP + 8),puVar7,extraout_ECX[1],uVar6,0);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 4;
        for (puVar4 = *(undefined4 **)(unaff_EBP + 8); puVar4 != puVar7; puVar4 = puVar4 + 1) {
          *puVar4 = *(undefined4 *)(unaff_EBP + 0x10);
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

