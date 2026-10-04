
void FUN_005e6e76(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffb4;
  iVar3 = extraout_ECX[1];
  if (iVar3 == extraout_ECX[2]) {
    iVar3 = (iVar3 - *extraout_ECX) / 0x2c;
    iVar5 = 0;
    if (iVar3 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar3 * 2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      iVar5 = FUN_00401742(*(int *)(unaff_EBP + -0x14) * 0x2c);
    }
    iVar3 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x1c) = iVar5;
    *(int *)(unaff_EBP + -0x18) = iVar5;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar3 = FUN_005e729d(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar5,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x18) = iVar3;
    *(int *)(unaff_EBP + -0x20) = iVar3;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar3 != 0) {
      FUN_005e5f74(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar1 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x18) = iVar3 + 0x2c;
    uVar4 = FUN_005e729d(*(undefined4 *)(unaff_EBP + 8),iVar1,iVar3 + 0x2c,
                         *(undefined4 *)(unaff_EBP + 8));
    puVar6 = (undefined4 *)*extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
    puVar2 = (undefined4 *)extraout_ECX[1];
    *(undefined4 **)(unaff_EBP + 8) = puVar2;
    if (puVar6 != puVar2) {
      do {
        (**(code **)*puVar6)(0);
        puVar6 = puVar6 + 0xb;
      } while (puVar6 != *(undefined4 **)(unaff_EBP + 8));
    }
    iVar3 = (extraout_ECX[2] - *extraout_ECX) / 0x2c;
    if (iVar3 != 0) {
      FUN_0040189d(*extraout_ECX,iVar3 * 0x2c);
    }
    iVar3 = *(int *)(unaff_EBP + 0xc);
    *extraout_ECX = iVar5;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = *(int *)(unaff_EBP + -0x14) * 0x2c + iVar5;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar3;
    *(int *)(unaff_EBP + -0x18) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar3 != 0) {
      FUN_005e5f74(iVar3 + -0x2c);
    }
    uVar4 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x2c;
    FUN_005e5f74(uVar4);
    iVar3 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005e716d(*(undefined4 *)(unaff_EBP + 8),iVar3 + -0x58,iVar3 + -0x2c);
    FUN_005e5fd3(unaff_EBP + -0x4c);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005e5e16();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

