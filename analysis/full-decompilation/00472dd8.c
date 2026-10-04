
void FUN_00472dd8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int *extraout_ECX;
  undefined4 *puVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar4 = (undefined4 *)extraout_ECX[1];
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd8;
  if (puVar4 == (undefined4 *)extraout_ECX[2]) {
    iVar3 = ((int)puVar4 - *extraout_ECX) / 0xc;
    if (iVar3 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar3 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar3 = iVar3 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar3;
    }
    if (iVar3 == 0) {
      iVar2 = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      iVar2 = FUN_0041e684(iVar3 * 0x90);
      *(int *)(unaff_EBP + -0x18) = iVar2;
    }
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    puVar4 = (undefined4 *)
             FUN_005f0ae8(iVar1,*(undefined4 *)(unaff_EBP + 8),iVar2,*(undefined4 *)(unaff_EBP + 8))
    ;
    if (puVar4 != (undefined4 *)0x0) {
      puVar7 = *(undefined4 **)(unaff_EBP + 0xc);
      *puVar4 = *puVar7;
      puVar4[1] = puVar7[1];
      puVar4[2] = puVar7[2];
      iVar3 = *(int *)(unaff_EBP + -0x14);
      iVar2 = *(int *)(unaff_EBP + -0x18);
    }
    uVar5 = FUN_005f0ae8(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar4 + 3,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar1 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + 8) = uVar5;
    for (iVar6 = *extraout_ECX; iVar6 != iVar1; iVar6 = iVar6 + 0xc) {
    }
    if ((extraout_ECX[2] - *extraout_ECX) / 0xc != 0) {
      FUN_0041d9a9(*extraout_ECX);
    }
    iVar1 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar2;
    extraout_ECX[1] = iVar1;
    extraout_ECX[2] = iVar2 + iVar3 * 0xc;
  }
  else {
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = puVar4[-3];
      puVar4[1] = puVar4[-2];
      puVar4[2] = puVar4[-1];
    }
    puVar4 = *(undefined4 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 0xc;
    iVar3 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -0x28) = *puVar4;
    puVar7 = (undefined4 *)(iVar3 + -0x18);
    *(undefined4 *)(unaff_EBP + -0x24) = puVar4[1];
    *(undefined4 *)(unaff_EBP + -0x20) = puVar4[2];
    iVar2 = ((int)puVar7 - *(int *)(unaff_EBP + 8)) / 0xc;
    puVar4 = (undefined4 *)(iVar3 + -0xc);
    if (0 < iVar2) {
      do {
        puVar4[-3] = puVar7[-3];
        puVar4[-2] = puVar7[-2];
        iVar2 = iVar2 + -1;
        puVar4[-1] = puVar7[-1];
        puVar4 = puVar4 + -3;
        puVar7 = puVar7 + -3;
      } while (iVar2 != 0);
    }
    puVar4 = *(undefined4 **)(unaff_EBP + 8);
    *puVar4 = *(undefined4 *)(unaff_EBP + -0x28);
    puVar4[1] = *(undefined4 *)(unaff_EBP + -0x24);
    puVar4[2] = *(undefined4 *)(unaff_EBP + -0x20);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

