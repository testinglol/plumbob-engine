
void FUN_00540075(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffdc;
  iVar6 = extraout_ECX[1];
  if (iVar6 == extraout_ECX[2]) {
    iVar6 = (iVar6 - *extraout_ECX) / 6;
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
      iVar6 = FUN_00401742(iVar6 * 6);
    }
    iVar7 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x18) = iVar6;
    *(int *)(unaff_EBP + -0x1c) = iVar6;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar7 = FUN_00540424(iVar7,*(undefined4 *)(unaff_EBP + 8),iVar6,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar7;
    *(int *)(unaff_EBP + -0x24) = iVar7;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar7 != 0) {
      FUN_0054020a(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar9 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar8 = FUN_00540424(*(undefined4 *)(unaff_EBP + 8),iVar9,iVar7 + 6,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar7 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + 8) = uVar8;
    for (iVar9 = *extraout_ECX; iVar9 != iVar7; iVar9 = iVar9 + 6) {
    }
    iVar7 = (extraout_ECX[2] - *extraout_ECX) / 6;
    if (iVar7 != 0) {
      FUN_0040189d(*extraout_ECX,iVar7 * 6);
    }
    iVar7 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar6;
    extraout_ECX[1] = iVar7;
    extraout_ECX[2] = iVar6 + *(int *)(unaff_EBP + -0x14) * 6;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar6;
    *(int *)(unaff_EBP + -0x18) = iVar6;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar6 != 0) {
      FUN_0054020a(iVar6 + -6);
    }
    puVar5 = *(undefined1 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 6;
    iVar6 = extraout_ECX[1];
    uVar1 = puVar5[1];
    uVar3 = *(undefined2 *)(puVar5 + 2);
    uVar4 = *(undefined2 *)(puVar5 + 4);
    uVar2 = *puVar5;
    *(undefined1 *)(unaff_EBP + -0x23) = uVar1;
    *(undefined2 *)(unaff_EBP + -0x22) = uVar3;
    *(undefined2 *)(unaff_EBP + -0x20) = uVar4;
    *(undefined1 *)(unaff_EBP + -0x24) = uVar2;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    puVar5 = *(undefined1 **)(unaff_EBP + 8);
    FUN_005403de(puVar5,iVar6 + -0xc,iVar6 + -6,*(undefined4 *)(unaff_EBP + 8),0);
    *(undefined2 *)(puVar5 + 4) = *(undefined2 *)(unaff_EBP + -0x20);
    uVar2 = *(undefined1 *)(unaff_EBP + -0x24);
    puVar5[1] = uVar1;
    *(undefined2 *)(puVar5 + 2) = uVar3;
    *puVar5 = uVar2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

