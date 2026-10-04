
void FUN_00471b90(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd8;
  iVar4 = extraout_ECX[1];
  if (iVar4 == extraout_ECX[2]) {
    iVar4 = (iVar4 - *extraout_ECX) / 0xc;
    if (iVar4 == 0) {
      iVar4 = 1;
    }
    else {
      iVar4 = iVar4 * 2;
    }
    *(int *)(unaff_EBP + -0x18) = iVar4;
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00401742(iVar4 * 0xc);
    }
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x1c) = iVar4;
    *(int *)(unaff_EBP + -0x14) = iVar4;
    iVar3 = FUN_004722fb(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar4,*(undefined4 *)(unaff_EBP + 8));
    if (iVar3 != 0) {
      FUN_0046fbcc(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar2 = extraout_ECX[1];
    *(int *)(unaff_EBP + -0x14) = iVar3 + 0xc;
    uVar5 = FUN_004722fb(*(undefined4 *)(unaff_EBP + 8),iVar2,iVar3 + 0xc,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar5;
    iVar2 = extraout_ECX[1];
    *(int *)(unaff_EBP + 8) = iVar2;
    if (iVar3 != iVar2) {
      do {
        FUN_0042004f();
        iVar3 = iVar3 + 0xc;
      } while (iVar3 != *(int *)(unaff_EBP + 8));
    }
    iVar3 = (extraout_ECX[2] - *extraout_ECX) / 0xc;
    if (iVar3 != 0) {
      FUN_0040189d(*extraout_ECX,iVar3 * 0xc);
    }
    iVar3 = *(int *)(unaff_EBP + 0xc);
    *extraout_ECX = iVar4;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = iVar4 + *(int *)(unaff_EBP + -0x18) * 0xc;
  }
  else {
    if (iVar4 != 0) {
      FUN_0046fbcc(iVar4 + -0xc);
    }
    puVar6 = *(undefined4 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 0xc;
    iVar4 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -0x28) = *puVar6;
    uVar1 = *(undefined1 *)(puVar6 + 2);
    *(undefined4 *)(unaff_EBP + -0x24) = puVar6[1];
    puVar6 = (undefined4 *)(iVar4 + -0x18);
    *(undefined1 *)(unaff_EBP + -0x20) = uVar1;
    iVar3 = ((int)puVar6 - *(int *)(unaff_EBP + 8)) / 0xc;
    puVar7 = (undefined4 *)(iVar4 + -0xc);
    if (0 < iVar3) {
      do {
        puVar7[-3] = puVar6[-3];
        puVar7[-2] = puVar6[-2];
        iVar3 = iVar3 + -1;
        puVar7[-1] = puVar6[-1];
        puVar6 = puVar6 + -3;
        puVar7 = puVar7 + -3;
      } while (iVar3 != 0);
    }
    puVar6 = *(undefined4 **)(unaff_EBP + 8);
    *puVar6 = *(undefined4 *)(unaff_EBP + -0x28);
    puVar6[1] = *(undefined4 *)(unaff_EBP + -0x24);
    puVar6[2] = *(undefined4 *)(unaff_EBP + -0x20);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

