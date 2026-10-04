
void FUN_00471a0e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = (iVar2 - *extraout_ECX) / 0xc;
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = iVar2 * 2;
    }
    *(int *)(unaff_EBP + -0x18) = iVar2;
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00401742(iVar2 * 0xc);
    }
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x14) = iVar2;
    iVar3 = FUN_004722fb(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar2,*(undefined4 *)(unaff_EBP + 8));
    if (iVar3 != 0) {
      FUN_0046fbbe();
    }
    iVar1 = extraout_ECX[1];
    *(int *)(unaff_EBP + -0x14) = iVar3 + 0xc;
    uVar4 = FUN_004722fb(*(undefined4 *)(unaff_EBP + 8),iVar1,iVar3 + 0xc,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
    iVar1 = extraout_ECX[1];
    *(int *)(unaff_EBP + 8) = iVar1;
    if (iVar3 != iVar1) {
      do {
        FUN_0042004f();
        iVar3 = iVar3 + 0xc;
      } while (iVar3 != *(int *)(unaff_EBP + 8));
    }
    iVar3 = (extraout_ECX[2] - *extraout_ECX) / 0xc;
    if (iVar3 != 0) {
      FUN_0040189d(*extraout_ECX,iVar3 * 0xc);
    }
    iVar3 = *(int *)(unaff_EBP + -0x20);
    *extraout_ECX = iVar2;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = iVar2 + *(int *)(unaff_EBP + -0x18) * 0xc;
  }
  else {
    if (iVar2 != 0) {
      FUN_0046fbcc(iVar2 + -0xc);
    }
    extraout_ECX[1] = extraout_ECX[1] + 0xc;
    puVar5 = (undefined4 *)(extraout_ECX[1] + -0x18);
    iVar2 = ((int)puVar5 - *(int *)(unaff_EBP + 8)) / 0xc;
    puVar6 = (undefined4 *)(extraout_ECX[1] + -0xc);
    if (0 < iVar2) {
      do {
        puVar6[-3] = puVar5[-3];
        puVar6[-2] = puVar5[-2];
        iVar2 = iVar2 + -1;
        puVar6[-1] = puVar5[-1];
        puVar5 = puVar5 + -3;
        puVar6 = puVar6 + -3;
      } while (iVar2 != 0);
    }
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    puVar5 = *(undefined4 **)(unaff_EBP + 8);
    *(undefined1 *)(unaff_EBP + -0x24) = 0xff;
    *puVar5 = *(undefined4 *)(unaff_EBP + -0x2c);
    puVar5[1] = *(undefined4 *)(unaff_EBP + -0x28);
    puVar5[2] = *(undefined4 *)(unaff_EBP + -0x24);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

