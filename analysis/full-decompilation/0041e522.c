
void FUN_0041e522(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *extraout_ECX;
  undefined4 *puVar9;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  iVar7 = extraout_ECX[1];
  if (iVar7 == extraout_ECX[2]) {
    iVar7 = iVar7 - *extraout_ECX >> 3;
    if (iVar7 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar7 * 2;
    }
    iVar7 = 0;
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      iVar7 = FUN_0041e684(*(int *)(unaff_EBP + -0x14) << 6);
    }
    iVar8 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x18) = iVar7;
    *(int *)(unaff_EBP + -0x1c) = iVar7;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar8 = FUN_00424217(iVar8,*(undefined4 *)(unaff_EBP + 8),iVar7,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar8;
    *(int *)(unaff_EBP + -0x20) = iVar8;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (iVar8 != 0) {
      FUN_004c97cc(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar6 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar6 = FUN_00424217(*(undefined4 *)(unaff_EBP + 8),iVar6,iVar8 + 8,
                         *(undefined4 *)(unaff_EBP + 8));
    for (iVar8 = *extraout_ECX; iVar8 != extraout_ECX[1]; iVar8 = iVar8 + 8) {
    }
    if ((extraout_ECX[2] - *extraout_ECX & 0xfffffff8U) != 0) {
      FUN_0041d9a9(*extraout_ECX);
    }
    iVar8 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar7;
    extraout_ECX[1] = iVar6;
    extraout_ECX[2] = iVar7 + iVar8 * 8;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar7;
    *(int *)(unaff_EBP + -0x18) = iVar7;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar7 != 0) {
      FUN_004c97cc(iVar7 + -8);
    }
    extraout_ECX[1] = extraout_ECX[1] + 8;
    iVar8 = extraout_ECX[1];
    iVar7 = iVar8 + -0x10;
    uVar2 = **(undefined4 **)(unaff_EBP + 0xc);
    uVar3 = (*(undefined4 **)(unaff_EBP + 0xc))[1];
    puVar4 = *(undefined4 **)(unaff_EBP + 8);
    iVar6 = iVar7 - (int)puVar4 >> 3;
    if (0 < iVar6) {
      *(int *)(unaff_EBP + 8) = iVar6;
      puVar9 = (undefined4 *)(iVar8 + -8);
      do {
        uVar5 = *(undefined4 *)(iVar7 + -8);
        piVar1 = (int *)(unaff_EBP + 8);
        *piVar1 = *piVar1 + -1;
        iVar8 = *piVar1;
        puVar9[-2] = uVar5;
        puVar9[-1] = *(undefined4 *)(iVar7 + -4);
        iVar7 = iVar7 + -8;
        puVar9 = puVar9 + -2;
      } while (iVar8 != 0);
    }
    *puVar4 = uVar2;
    puVar4[1] = uVar3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

