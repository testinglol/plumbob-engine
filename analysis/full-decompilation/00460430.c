
void FUN_00460430(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *extraout_ECX;
  undefined4 *puVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  puVar3 = (undefined4 *)extraout_ECX[1];
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd8;
  if (puVar3 == (undefined4 *)extraout_ECX[2]) {
    iVar2 = ((int)puVar3 - *extraout_ECX) / 0xc;
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar2 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar2 = iVar2 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar2;
    }
    if (iVar2 == 0) {
      iVar2 = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      iVar2 = FUN_00401742(iVar2 * 0xc);
      *(int *)(unaff_EBP + -0x18) = iVar2;
    }
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    puVar3 = (undefined4 *)
             FUN_005f0ae8(iVar1,*(undefined4 *)(unaff_EBP + 8),iVar2,*(undefined4 *)(unaff_EBP + 8))
    ;
    if (puVar3 != (undefined4 *)0x0) {
      puVar6 = *(undefined4 **)(unaff_EBP + 0xc);
      *puVar3 = *puVar6;
      puVar3[1] = puVar6[1];
      puVar3[2] = puVar6[2];
      iVar2 = *(int *)(unaff_EBP + -0x18);
    }
    uVar4 = FUN_005f0ae8(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar3 + 3,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar1 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + 8) = uVar4;
    for (iVar5 = *extraout_ECX; iVar5 != iVar1; iVar5 = iVar5 + 0xc) {
    }
    iVar1 = (extraout_ECX[2] - *extraout_ECX) / 0xc;
    if (iVar1 != 0) {
      FUN_0040189d(*extraout_ECX,iVar1 * 0xc);
    }
    iVar1 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar2;
    extraout_ECX[1] = iVar1;
    extraout_ECX[2] = iVar2 + *(int *)(unaff_EBP + -0x14) * 0xc;
  }
  else {
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar3[-3];
      puVar3[1] = puVar3[-2];
      puVar3[2] = puVar3[-1];
    }
    puVar3 = *(undefined4 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 0xc;
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -0x28) = *puVar3;
    puVar6 = (undefined4 *)(iVar2 + -0x18);
    *(undefined4 *)(unaff_EBP + -0x24) = puVar3[1];
    *(undefined4 *)(unaff_EBP + -0x20) = puVar3[2];
    iVar1 = ((int)puVar6 - *(int *)(unaff_EBP + 8)) / 0xc;
    puVar3 = (undefined4 *)(iVar2 + -0xc);
    if (0 < iVar1) {
      do {
        puVar3[-3] = puVar6[-3];
        puVar3[-2] = puVar6[-2];
        iVar1 = iVar1 + -1;
        puVar3[-1] = puVar6[-1];
        puVar3 = puVar3 + -3;
        puVar6 = puVar6 + -3;
      } while (iVar1 != 0);
    }
    puVar3 = *(undefined4 **)(unaff_EBP + 8);
    *puVar3 = *(undefined4 *)(unaff_EBP + -0x28);
    puVar3[1] = *(undefined4 *)(unaff_EBP + -0x24);
    puVar3[2] = *(undefined4 *)(unaff_EBP + -0x20);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

