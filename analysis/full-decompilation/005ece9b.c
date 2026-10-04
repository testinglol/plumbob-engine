
void FUN_005ece9b(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *extraout_ECX;
  undefined4 *puVar10;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  puVar7 = (undefined4 *)extraout_ECX[1];
  if (puVar7 == (undefined4 *)extraout_ECX[2]) {
    iVar6 = (int)puVar7 - *extraout_ECX >> 3;
    if (iVar6 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar6 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar6 = iVar6 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar6;
    }
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_00401742(iVar6 << 3);
    }
    iVar9 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x18) = iVar6;
    *(int *)(unaff_EBP + -0x1c) = iVar6;
    puVar7 = (undefined4 *)
             FUN_00424217(iVar9,*(undefined4 *)(unaff_EBP + 8),iVar6,*(undefined4 *)(unaff_EBP + 8))
    ;
    if (puVar7 != (undefined4 *)0x0) {
      puVar10 = *(undefined4 **)(unaff_EBP + 0xc);
      *puVar7 = *puVar10;
      puVar7[1] = puVar10[1];
    }
    iVar8 = FUN_00424217(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar7 + 2,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar9 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    for (iVar5 = *extraout_ECX; iVar5 != iVar9; iVar5 = iVar5 + 8) {
    }
    iVar9 = extraout_ECX[2] - *extraout_ECX >> 3;
    if (iVar9 != 0) {
      FUN_0040189d(*extraout_ECX,iVar9 << 3);
    }
    iVar9 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar6;
    extraout_ECX[1] = iVar8;
    extraout_ECX[2] = iVar6 + iVar9 * 8;
  }
  else {
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = puVar7[-2];
      puVar7[1] = puVar7[-1];
    }
    extraout_ECX[1] = extraout_ECX[1] + 8;
    iVar9 = extraout_ECX[1];
    iVar6 = iVar9 + -0x10;
    uVar2 = **(undefined4 **)(unaff_EBP + 0xc);
    uVar3 = (*(undefined4 **)(unaff_EBP + 0xc))[1];
    puVar7 = *(undefined4 **)(unaff_EBP + 8);
    iVar5 = iVar6 - (int)puVar7 >> 3;
    if (0 < iVar5) {
      *(int *)(unaff_EBP + 8) = iVar5;
      puVar10 = (undefined4 *)(iVar9 + -8);
      do {
        uVar4 = *(undefined4 *)(iVar6 + -8);
        piVar1 = (int *)(unaff_EBP + 8);
        *piVar1 = *piVar1 + -1;
        iVar9 = *piVar1;
        puVar10[-2] = uVar4;
        puVar10[-1] = *(undefined4 *)(iVar6 + -4);
        iVar6 = iVar6 + -8;
        puVar10 = puVar10 + -2;
      } while (iVar9 != 0);
    }
    *puVar7 = uVar2;
    puVar7[1] = uVar3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

