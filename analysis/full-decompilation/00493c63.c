
void FUN_00493c63(void)

{
  int iVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  FUN_00634c24();
  iVar3 = extraout_ECX[1];
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffac;
  if (iVar3 == extraout_ECX[2]) {
    iVar3 = (iVar3 - *extraout_ECX) / 0x34;
    iVar7 = 0;
    if (iVar3 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar3 * 2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      iVar7 = FUN_00401742(*(int *)(unaff_EBP + -0x14) * 0x34);
    }
    iVar3 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x1c) = iVar7;
    *(int *)(unaff_EBP + -0x18) = iVar7;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar3 = FUN_00493f10(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar7,*(undefined4 *)(unaff_EBP + 0xc)
                        );
    *(int *)(unaff_EBP + -0x18) = iVar3;
    *(int *)(unaff_EBP + -0x20) = iVar3;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar3 != 0) {
      FUN_00493e7e(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar1 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x18) = iVar3 + 0x34;
    uVar2 = FUN_00493f10(*(undefined4 *)(unaff_EBP + 8),iVar1,iVar3 + 0x34,
                         *(undefined4 *)(unaff_EBP + 0xc));
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 8) = uVar2;
    iVar1 = extraout_ECX[1];
    *(int *)(unaff_EBP + 0xc) = iVar1;
    if (iVar3 != iVar1) {
      do {
        FUN_00488302(iVar3);
        iVar3 = iVar3 + 0x34;
      } while (iVar3 != *(int *)(unaff_EBP + 0xc));
    }
    iVar3 = (extraout_ECX[2] - *extraout_ECX) / 0x34;
    if (iVar3 != 0) {
      FUN_0040189d(*extraout_ECX,iVar3 * 0x34);
    }
    iVar3 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar7;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = *(int *)(unaff_EBP + -0x14) * 0x34 + iVar7;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar3;
    *(int *)(unaff_EBP + -0x18) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar3 != 0) {
      FUN_00493e7e(iVar3 + -0x34);
    }
    puVar4 = *(undefined4 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 0x34;
    FUN_00461b74(puVar4);
    uVar2 = *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x30);
    puVar6 = (undefined4 *)(unaff_EBP + -0x50);
    for (iVar3 = 0xb; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar4;
      puVar6 = puVar6 + 1;
    }
    *(undefined4 *)(unaff_EBP + -0x24) = uVar2;
    iVar3 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    puVar4 = *(undefined4 **)(unaff_EBP + 8);
    FUN_00493ede(puVar4,iVar3 + -0x68,iVar3 + -0x34,*(undefined4 *)(unaff_EBP + 0xc),0);
    FUN_00461b74(unaff_EBP + -0x54);
    uVar2 = *(undefined4 *)(unaff_EBP + -0x24);
    puVar5 = (undefined4 *)(unaff_EBP + -0x50);
    puVar6 = puVar4;
    for (iVar3 = 0xb; puVar6 = puVar6 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
    }
    puVar4[0xc] = uVar2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

