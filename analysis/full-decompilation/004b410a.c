
void FUN_004b410a(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *extraout_ECX;
  undefined4 *puVar5;
  int unaff_EBP;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  puVar3 = (undefined4 *)extraout_ECX[1];
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  if (puVar3 == (undefined4 *)extraout_ECX[2]) {
    iVar6 = (int)puVar3 - *extraout_ECX >> 4;
    if (iVar6 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar6 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar6 = iVar6 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar6;
    }
    if (iVar6 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      uVar2 = FUN_00401742(iVar6 << 4);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
    puVar3 = (undefined4 *)
             FUN_004612c6(iVar1,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                          *(undefined4 *)(unaff_EBP + 8));
    if (puVar3 != (undefined4 *)0x0) {
      puVar5 = *(undefined4 **)(unaff_EBP + 0xc);
      *puVar3 = *puVar5;
      puVar3[1] = puVar5[1];
      puVar3[2] = puVar5[2];
      puVar3[3] = puVar5[3];
      iVar6 = *(int *)(unaff_EBP + -0x14);
    }
    iVar4 = FUN_004612c6(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar3 + 4,
                         *(undefined4 *)(unaff_EBP + 8));
    for (iVar1 = *extraout_ECX; iVar1 != extraout_ECX[1]; iVar1 = iVar1 + 0x10) {
    }
    iVar1 = extraout_ECX[2] - *extraout_ECX >> 4;
    if (iVar1 != 0) {
      FUN_0040189d(*extraout_ECX,iVar1 << 4);
    }
    iVar1 = *(int *)(unaff_EBP + -0x18);
    extraout_ECX[1] = iVar4;
    *extraout_ECX = iVar1;
    extraout_ECX[2] = iVar6 * 0x10 + iVar1;
  }
  else {
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar3[-4];
      puVar3[1] = puVar3[-3];
      puVar3[2] = puVar3[-2];
      puVar3[3] = puVar3[-1];
    }
    puVar5 = *(undefined4 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 0x10;
    iVar6 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -0x2c) = *puVar5;
    *(undefined4 *)(unaff_EBP + -0x28) = puVar5[1];
    puVar3 = (undefined4 *)(iVar6 + -0x20);
    *(undefined4 *)(unaff_EBP + -0x24) = puVar5[2];
    iVar1 = (int)puVar3 - *(int *)(unaff_EBP + 8) >> 4;
    *(undefined4 *)(unaff_EBP + -0x20) = puVar5[3];
    puVar5 = (undefined4 *)(iVar6 + -0x10);
    if (0 < iVar1) {
      do {
        puVar5[-4] = puVar3[-4];
        puVar5[-3] = puVar3[-3];
        puVar5[-2] = puVar3[-2];
        iVar1 = iVar1 + -1;
        puVar5[-1] = puVar3[-1];
        puVar3 = puVar3 + -4;
        puVar5 = puVar5 + -4;
      } while (iVar1 != 0);
    }
    puVar3 = *(undefined4 **)(unaff_EBP + 8);
    *puVar3 = *(undefined4 *)(unaff_EBP + -0x2c);
    puVar3[1] = *(undefined4 *)(unaff_EBP + -0x28);
    puVar3[2] = *(undefined4 *)(unaff_EBP + -0x24);
    puVar3[3] = *(undefined4 *)(unaff_EBP + -0x20);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

