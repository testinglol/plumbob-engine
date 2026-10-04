
void FUN_0046ade1(void)

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
  
  FUN_00634c24();
  puVar1 = (undefined4 *)extraout_ECX[1];
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  if (puVar1 == (undefined4 *)extraout_ECX[2]) {
    iVar4 = ((int)puVar1 - *extraout_ECX) / 0x14;
    if (iVar4 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar4 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar4 = iVar4 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar4;
    }
    if (iVar4 == 0) {
      iVar4 = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      iVar4 = FUN_00401742(iVar4 * 0x14);
      *(int *)(unaff_EBP + -0x18) = iVar4;
    }
    iVar5 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x1c) = iVar4;
    puVar1 = (undefined4 *)
             FUN_0046b0bd(iVar5,*(undefined4 *)(unaff_EBP + 8),iVar4,*(undefined4 *)(unaff_EBP + 8))
    ;
    if (puVar1 != (undefined4 *)0x0) {
      puVar6 = *(undefined4 **)(unaff_EBP + 0xc);
      puVar7 = puVar1;
      for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      iVar4 = *(int *)(unaff_EBP + -0x18);
    }
    uVar2 = FUN_0046b0bd(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar1 + 5,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar5 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 8) = uVar2;
    for (iVar3 = *extraout_ECX; iVar3 != iVar5; iVar3 = iVar3 + 0x14) {
    }
    iVar5 = (extraout_ECX[2] - *extraout_ECX) / 0x14;
    if (iVar5 != 0) {
      FUN_0040189d(*extraout_ECX,iVar5 * 0x14);
    }
    iVar5 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar4;
    extraout_ECX[1] = iVar5;
    extraout_ECX[2] = iVar4 + *(int *)(unaff_EBP + -0x14) * 0x14;
  }
  else {
    if (puVar1 != (undefined4 *)0x0) {
      puVar6 = puVar1 + -5;
      for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar1 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar1 = puVar1 + 1;
      }
    }
    extraout_ECX[1] = extraout_ECX[1] + 0x14;
    iVar4 = extraout_ECX[1];
    puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
    puVar6 = (undefined4 *)(unaff_EBP + -0x30);
    for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar1 = (undefined4 *)(iVar4 + -0x28);
    *(int *)(unaff_EBP + 0xc) = iVar4 + -0x14;
    iVar4 = ((int)puVar1 - *(int *)(unaff_EBP + 8)) / 0x14;
    if (0 < iVar4) {
      do {
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + -0x14;
        puVar1 = puVar1 + -5;
        iVar4 = iVar4 + -1;
        puVar6 = puVar1;
        puVar7 = *(undefined4 **)(unaff_EBP + 0xc);
        for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
      } while (iVar4 != 0);
    }
    puVar1 = (undefined4 *)(unaff_EBP + -0x30);
    puVar6 = *(undefined4 **)(unaff_EBP + 8);
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

