
void FUN_00407c20(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *extraout_ECX;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int unaff_EBP;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  FUN_00634c24();
  puVar2 = (undefined4 *)extraout_ECX[1];
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  if (puVar2 == (undefined4 *)extraout_ECX[2]) {
    iVar5 = (int)puVar2 - *extraout_ECX >> 5;
    if (iVar5 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar5 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar5 = iVar5 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar5;
    }
    if (iVar5 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      uVar1 = FUN_00401742(iVar5 << 5);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    iVar6 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
    puVar2 = (undefined4 *)
             FUN_005d222e(iVar6,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                          *(undefined4 *)(unaff_EBP + 8));
    if (puVar2 != (undefined4 *)0x0) {
      puVar8 = *(undefined4 **)(unaff_EBP + 0xc);
      puVar9 = puVar2;
      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      iVar5 = *(int *)(unaff_EBP + -0x14);
    }
    iVar3 = FUN_005d222e(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar2 + 8,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar6 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    for (iVar4 = *extraout_ECX; iVar4 != iVar6; iVar4 = iVar4 + 0x20) {
    }
    iVar6 = extraout_ECX[2] - *extraout_ECX >> 5;
    if (iVar6 != 0) {
      FUN_0040189d(*extraout_ECX,iVar6 << 5);
    }
    iVar6 = *(int *)(unaff_EBP + -0x18);
    extraout_ECX[1] = iVar3;
    *extraout_ECX = iVar6;
    extraout_ECX[2] = iVar5 * 0x20 + iVar6;
  }
  else {
    if (puVar2 != (undefined4 *)0x0) {
      puVar8 = puVar2 + -8;
      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar2 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar2 = puVar2 + 1;
      }
    }
    extraout_ECX[1] = extraout_ECX[1] + 0x20;
    puVar2 = (undefined4 *)(extraout_ECX[1] + -0x20);
    puVar7 = (undefined4 *)(extraout_ECX[1] + -0x40);
    iVar5 = *(int *)(unaff_EBP + 8);
    puVar8 = *(undefined4 **)(unaff_EBP + 0xc);
    puVar9 = (undefined4 *)(unaff_EBP + -0x3c);
    for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    iVar5 = (int)puVar7 - iVar5 >> 5;
    if (0 < iVar5) {
      do {
        puVar7 = puVar7 + -8;
        puVar2 = puVar2 + -8;
        iVar5 = iVar5 + -1;
        puVar8 = puVar7;
        puVar9 = puVar2;
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
      } while (iVar5 != 0);
    }
    puVar2 = (undefined4 *)(unaff_EBP + -0x3c);
    puVar8 = *(undefined4 **)(unaff_EBP + 8);
    for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

