
void FUN_00455926(void)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *extraout_ECX;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  int unaff_EBP;
  uint uVar10;
  undefined1 *puVar11;
  
  FUN_00634c24();
  iVar6 = *(int *)(unaff_EBP + 0x10);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  if (*(int *)(unaff_EBP + 0xc) != iVar6) {
    iVar8 = extraout_ECX[1];
    uVar10 = iVar6 - *(int *)(unaff_EBP + 0xc);
    if (extraout_ECX[2] - iVar8 < (int)(uVar10 + 1)) {
      uVar9 = iVar8 - *extraout_ECX;
      *(uint *)(unaff_EBP + -0x1c) = uVar10;
      piVar4 = (int *)(unaff_EBP + -0x1c);
      *(uint *)(unaff_EBP + -0x18) = uVar9;
      if (uVar10 <= uVar9) {
        piVar4 = (int *)(unaff_EBP + -0x18);
      }
      iVar8 = *piVar4 + 1 + uVar9;
      *(int *)(unaff_EBP + -0x18) = iVar8;
      if (iVar8 == 0) {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
      }
      else {
        uVar5 = FUN_00401742(iVar8);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
        iVar6 = *(int *)(unaff_EBP + 0x10);
      }
      puVar7 = (undefined1 *)*extraout_ECX;
      puVar11 = *(undefined1 **)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -4) = 2;
      for (iVar8 = *(int *)(unaff_EBP + 8) - (int)puVar7; 0 < iVar8; iVar8 = iVar8 + -1) {
        uVar2 = *puVar7;
        puVar7 = puVar7 + 1;
        *puVar11 = uVar2;
        puVar11 = puVar11 + 1;
      }
      FUN_00635190(puVar11,*(undefined4 *)(unaff_EBP + 0xc),iVar6 - *(int *)(unaff_EBP + 0xc));
      puVar7 = *(undefined1 **)(unaff_EBP + 8);
      puVar11 = puVar11 + (*(int *)(unaff_EBP + 0x10) - *(int *)(unaff_EBP + 0xc));
      for (iVar6 = extraout_ECX[1] - (int)puVar7; 0 < iVar6; iVar6 = iVar6 + -1) {
        uVar2 = *puVar7;
        puVar7 = puVar7 + 1;
        *puVar11 = uVar2;
        puVar11 = puVar11 + 1;
      }
      FUN_00401651(puVar11);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00401729();
      iVar6 = *(int *)(unaff_EBP + -0x14);
      iVar8 = *(int *)(unaff_EBP + -0x18);
      *extraout_ECX = iVar6;
      extraout_ECX[1] = (int)puVar11;
      extraout_ECX[2] = iVar6 + iVar8;
    }
    else {
      iVar8 = iVar8 - *(int *)(unaff_EBP + 8);
      iVar3 = extraout_ECX[1];
      *(int *)(unaff_EBP + -0x1c) = iVar3;
      if (iVar8 < (int)uVar10) {
        *(int *)(unaff_EBP + 0x10) = iVar3 + 1;
        iVar1 = iVar8 + 1 + *(int *)(unaff_EBP + 0xc);
        *(int *)(unaff_EBP + -0x18) = iVar1;
        FUN_00635190(iVar3 + 1,iVar1,iVar6 - iVar1);
        extraout_ECX[1] = extraout_ECX[1] + (uVar10 - iVar8);
        iVar6 = extraout_ECX[1];
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_004746d5(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),iVar6,
                     *(undefined4 *)(unaff_EBP + 0xc),0);
        iVar6 = *(int *)(unaff_EBP + -0x18);
        iVar3 = *(int *)(unaff_EBP + 0xc);
        extraout_ECX[1] = extraout_ECX[1] + iVar8;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00636510(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),iVar6 - iVar3);
      }
      else {
        FUN_004746d5((iVar3 - uVar10) + 1,iVar3 + 1,iVar3 + 1,*(undefined4 *)(unaff_EBP + 0xc),0);
        extraout_ECX[1] = extraout_ECX[1] + uVar10;
        iVar6 = *(int *)(unaff_EBP + 8);
        FUN_00635190(uVar10 + iVar6,iVar6,(iVar8 - uVar10) + 1);
        FUN_00636510(iVar6,*(undefined4 *)(unaff_EBP + 0xc),uVar10);
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

