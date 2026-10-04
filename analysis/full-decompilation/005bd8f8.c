
void FUN_005bd8f8(void)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  int iVar8;
  int *extraout_ECX;
  int iVar9;
  uint uVar10;
  undefined2 extraout_var;
  undefined4 *puVar11;
  int unaff_EBP;
  undefined2 *puVar12;
  
  FUN_00634c24();
  uVar10 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (uVar10 != 0) {
    iVar9 = extraout_ECX[1];
    if ((uint)(extraout_ECX[2] - iVar9 >> 1) < uVar10) {
      uVar2 = iVar9 - *extraout_ECX >> 1;
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
        uVar6 = FUN_00401742(iVar9 * 2);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar6;
      }
      iVar3 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      puVar7 = (undefined2 *)
               FUN_004031c7(iVar3,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                            *(undefined4 *)(unaff_EBP + 8),0);
      for (; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar7 = **(undefined2 **)(unaff_EBP + 0x10);
        puVar7 = puVar7 + 1;
      }
      iVar3 = FUN_004031c7(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar7,
                           *(undefined4 *)(unaff_EBP + 8),0);
      iVar8 = extraout_ECX[2] - *extraout_ECX >> 1;
      if (iVar8 != 0) {
        FUN_0040189d(*extraout_ECX,iVar8 * 2);
      }
      iVar8 = *(int *)(unaff_EBP + 0xc);
      extraout_ECX[1] = iVar3;
      *extraout_ECX = iVar8;
      extraout_ECX[2] = iVar8 + iVar9 * 2;
    }
    else {
      puVar11 = (undefined4 *)extraout_ECX[1];
      uVar1 = **(undefined2 **)(unaff_EBP + 0x10);
      uVar2 = iVar9 - *(int *)(unaff_EBP + 8) >> 1;
      *(uint *)(unaff_EBP + 0x10) = CONCAT22(extraout_var,uVar1);
      *(uint *)(unaff_EBP + -0x14) = uVar2;
      if (uVar10 < uVar2) {
        *(undefined4 **)(unaff_EBP + 0xc) = puVar11;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + uVar10 * -2;
        FUN_004031c7(*(undefined4 *)(unaff_EBP + 0xc),puVar11,puVar11,*(undefined4 *)(unaff_EBP + 8)
                     ,0);
        iVar9 = *(int *)(unaff_EBP + 0xc);
        puVar7 = *(undefined2 **)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + uVar10 * 2;
        iVar3 = iVar9 - (int)puVar7 >> 1;
        if (0 < iVar3) {
          iVar9 = iVar9 - (int)puVar11;
          do {
            puVar11 = (undefined4 *)((int)puVar11 + -2);
            iVar3 = iVar3 + -1;
            *(undefined2 *)puVar11 = *(undefined2 *)(iVar9 + (int)puVar11);
          } while (iVar3 != 0);
        }
        puVar12 = puVar7 + uVar10;
        for (; puVar7 != puVar12; puVar7 = puVar7 + 1) {
          *puVar7 = *(undefined2 *)(unaff_EBP + 0x10);
        }
      }
      else {
        uVar10 = uVar10 - uVar2;
        *(uint *)(unaff_EBP + 0xc) = uVar10;
        if (uVar10 != 0) {
          puVar4 = puVar11;
          for (uVar2 = uVar10 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar4 = CONCAT22(uVar1,uVar1);
            puVar4 = puVar4 + 1;
          }
          for (uVar10 = (uint)((uVar10 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined2 *)puVar4 = uVar1;
            puVar4 = (undefined4 *)((int)puVar4 + 2);
          }
        }
        uVar6 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 0xc) * 2;
        FUN_004031c7(*(undefined4 *)(unaff_EBP + 8),puVar11,extraout_ECX[1],uVar6,0);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + -0x14) * 2;
        for (puVar4 = *(undefined4 **)(unaff_EBP + 8); puVar4 != puVar11;
            puVar4 = (undefined4 *)((int)puVar4 + 2)) {
          *(undefined2 *)puVar4 = *(undefined2 *)(unaff_EBP + 0x10);
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

