
void FUN_0047d519(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  iVar5 = extraout_ECX[1];
  if (iVar5 == extraout_ECX[2]) {
    iVar5 = (iVar5 - *extraout_ECX) / 3;
    if (iVar5 == 0) {
      iVar5 = 1;
    }
    else {
      iVar5 = iVar5 * 2;
    }
    *(int *)(unaff_EBP + -0x18) = iVar5;
    if (iVar5 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    else {
      uVar7 = FUN_00401742(iVar5 * 3);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar7;
    }
    iVar6 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar6 = FUN_0047d95b(iVar6,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14),
                         *(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar6;
    *(int *)(unaff_EBP + -0x20) = iVar6;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar6 != 0) {
      FUN_00461b74(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar8 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar7 = FUN_0047d95b(*(undefined4 *)(unaff_EBP + 8),iVar8,iVar6 + 3,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar6 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + 8) = uVar7;
    for (iVar8 = *extraout_ECX; iVar8 != iVar6; iVar8 = iVar8 + 3) {
    }
    iVar6 = (extraout_ECX[2] - *extraout_ECX) / 3;
    if (iVar6 != 0) {
      FUN_0040189d(*extraout_ECX,iVar6 * 3);
    }
    iVar6 = *(int *)(unaff_EBP + -0x14);
    iVar8 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar6;
    extraout_ECX[1] = iVar8;
    extraout_ECX[2] = iVar6 + iVar5 * 3;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar5;
    *(int *)(unaff_EBP + -0x18) = iVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar5 != 0) {
      FUN_00461b74(iVar5 + -3);
    }
    puVar4 = *(undefined1 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 3;
    iVar5 = extraout_ECX[1];
    uVar1 = *puVar4;
    uVar2 = puVar4[1];
    uVar3 = puVar4[2];
    *(undefined1 *)(unaff_EBP + 0xc) = uVar1;
    *(undefined1 *)(unaff_EBP + 0xd) = uVar2;
    *(undefined1 *)(unaff_EBP + 0xe) = uVar3;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    puVar4 = *(undefined1 **)(unaff_EBP + 8);
    FUN_0047d8dc(puVar4,iVar5 + -6,iVar5 + -3,*(undefined4 *)(unaff_EBP + 8),0);
    puVar4[1] = *(undefined1 *)(unaff_EBP + 0xd);
    uVar2 = *(undefined1 *)(unaff_EBP + 0xe);
    *puVar4 = uVar1;
    puVar4[2] = uVar2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

