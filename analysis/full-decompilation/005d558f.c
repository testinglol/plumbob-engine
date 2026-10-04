
void FUN_005d558f(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *extraout_ECX;
  undefined4 *puVar6;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  puVar3 = (undefined4 *)extraout_ECX[1];
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  if (puVar3 == (undefined4 *)extraout_ECX[2]) {
    iVar7 = (int)puVar3 - *extraout_ECX >> 4;
    if (iVar7 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar7 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar7 = iVar7 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar7;
    }
    if (iVar7 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      uVar2 = FUN_00401742(iVar7 << 4);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
    puVar3 = (undefined4 *)
             FUN_004612c6(iVar1,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                          *(undefined4 *)(unaff_EBP + 8));
    if (puVar3 != (undefined4 *)0x0) {
      puVar6 = *(undefined4 **)(unaff_EBP + 0xc);
      *puVar3 = *puVar6;
      puVar3[1] = puVar6[1];
      puVar3[2] = puVar6[2];
      puVar3[3] = puVar6[3];
      iVar7 = *(int *)(unaff_EBP + -0x14);
    }
    iVar4 = FUN_004612c6(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar3 + 4,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar1 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    for (iVar5 = *extraout_ECX; iVar5 != iVar1; iVar5 = iVar5 + 0x10) {
    }
    iVar1 = extraout_ECX[2] - *extraout_ECX >> 4;
    if (iVar1 != 0) {
      FUN_0040189d(*extraout_ECX,iVar1 << 4);
    }
    iVar1 = *(int *)(unaff_EBP + -0x18);
    extraout_ECX[1] = iVar4;
    *extraout_ECX = iVar1;
    extraout_ECX[2] = iVar7 * 0x10 + iVar1;
  }
  else {
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar3[-4];
      puVar3[1] = puVar3[-3];
      puVar3[2] = puVar3[-2];
      puVar3[3] = puVar3[-1];
    }
    puVar6 = *(undefined4 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 0x10;
    iVar7 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -0x2c) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x28) = puVar6[1];
    puVar3 = (undefined4 *)(iVar7 + -0x20);
    *(undefined4 *)(unaff_EBP + -0x24) = puVar6[2];
    iVar1 = (int)puVar3 - *(int *)(unaff_EBP + 8) >> 4;
    *(undefined4 *)(unaff_EBP + -0x20) = puVar6[3];
    puVar6 = (undefined4 *)(iVar7 + -0x10);
    if (0 < iVar1) {
      do {
        puVar6[-4] = puVar3[-4];
        puVar6[-3] = puVar3[-3];
        puVar6[-2] = puVar3[-2];
        iVar1 = iVar1 + -1;
        puVar6[-1] = puVar3[-1];
        puVar3 = puVar3 + -4;
        puVar6 = puVar6 + -4;
      } while (iVar1 != 0);
    }
    puVar3 = *(undefined4 **)(unaff_EBP + 8);
    *puVar3 = *(undefined4 *)(unaff_EBP + -0x2c);
    puVar3[1] = *(undefined4 *)(unaff_EBP + -0x28);
    puVar3[2] = *(undefined4 *)(unaff_EBP + -0x24);
    puVar3[3] = *(undefined4 *)(unaff_EBP + -0x20);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

