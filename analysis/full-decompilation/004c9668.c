
void FUN_004c9668(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *extraout_ECX;
  undefined4 *puVar10;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  iVar7 = extraout_ECX[1];
  if (iVar7 == extraout_ECX[2]) {
    iVar7 = iVar7 - *extraout_ECX >> 3;
    if (iVar7 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar7 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar7 = iVar7 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar7;
    }
    if (iVar7 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_00401742(iVar7 << 3);
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
    iVar9 = FUN_00424217(*(undefined4 *)(unaff_EBP + 8),iVar6,iVar8 + 8,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar8 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    for (iVar6 = *extraout_ECX; iVar6 != iVar8; iVar6 = iVar6 + 8) {
    }
    iVar8 = extraout_ECX[2] - *extraout_ECX >> 3;
    if (iVar8 != 0) {
      FUN_0040189d(*extraout_ECX,iVar8 << 3);
    }
    iVar8 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar7;
    extraout_ECX[1] = iVar9;
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
      puVar10 = (undefined4 *)(iVar8 + -8);
      do {
        uVar5 = *(undefined4 *)(iVar7 + -8);
        piVar1 = (int *)(unaff_EBP + 8);
        *piVar1 = *piVar1 + -1;
        iVar8 = *piVar1;
        puVar10[-2] = uVar5;
        puVar10[-1] = *(undefined4 *)(iVar7 + -4);
        iVar7 = iVar7 + -8;
        puVar10 = puVar10 + -2;
      } while (iVar8 != 0);
    }
    *puVar4 = uVar2;
    puVar4[1] = uVar3;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

