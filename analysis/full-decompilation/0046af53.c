
void FUN_0046af53(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *extraout_ECX;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  puVar1 = (undefined4 *)extraout_ECX[1];
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffb8;
  if (puVar1 == (undefined4 *)extraout_ECX[2]) {
    iVar4 = ((int)puVar1 - *extraout_ECX) / 0x2c;
    if (iVar4 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar4 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar4 = iVar4 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar4;
    }
    if (iVar4 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      uVar2 = FUN_00401742(iVar4 * 0x2c);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    iVar5 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
    puVar1 = (undefined4 *)
             FUN_0046b0e9(iVar5,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                          *(undefined4 *)(unaff_EBP + 8));
    if (puVar1 != (undefined4 *)0x0) {
      puVar6 = *(undefined4 **)(unaff_EBP + 0xc);
      puVar7 = puVar1;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      iVar4 = *(int *)(unaff_EBP + -0x14);
    }
    uVar2 = FUN_0046b0e9(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar1 + 0xb,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar5 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 8) = uVar2;
    for (iVar3 = *extraout_ECX; iVar3 != iVar5; iVar3 = iVar3 + 0x2c) {
    }
    iVar5 = (extraout_ECX[2] - *extraout_ECX) / 0x2c;
    if (iVar5 != 0) {
      FUN_0040189d(*extraout_ECX,iVar5 * 0x2c);
    }
    iVar5 = *(int *)(unaff_EBP + -0x18);
    iVar3 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar5;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = iVar4 * 0x2c + iVar5;
  }
  else {
    if (puVar1 != (undefined4 *)0x0) {
      puVar6 = puVar1 + -0xb;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar1 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar1 = puVar1 + 1;
      }
    }
    extraout_ECX[1] = extraout_ECX[1] + 0x2c;
    iVar4 = extraout_ECX[1];
    puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
    puVar6 = (undefined4 *)(unaff_EBP + -0x48);
    for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar1 = (undefined4 *)(iVar4 + -0x58);
    *(int *)(unaff_EBP + 0xc) = iVar4 + -0x2c;
    iVar4 = ((int)puVar1 - *(int *)(unaff_EBP + 8)) / 0x2c;
    if (0 < iVar4) {
      do {
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + -0x2c;
        puVar1 = puVar1 + -0xb;
        iVar4 = iVar4 + -1;
        puVar6 = puVar1;
        puVar7 = *(undefined4 **)(unaff_EBP + 0xc);
        for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
      } while (iVar4 != 0);
    }
    puVar1 = (undefined4 *)(unaff_EBP + -0x48);
    puVar6 = *(undefined4 **)(unaff_EBP + 8);
    for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

