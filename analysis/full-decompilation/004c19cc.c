
void FUN_004c19cc(void)

{
  int extraout_ECX;
  int iVar1;
  int unaff_EBP;
  int iVar2;
  undefined4 uVar3;
  
  FUN_00634c24();
  iVar2 = 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  iVar1 = *(int *)(extraout_ECX + 8);
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  if (iVar1 != 0) {
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00415317();
    FUN_004c1a01();
    return;
  }
  if (*(int *)(extraout_ECX + 0x20) < 999) {
    if (*(int *)(extraout_ECX + 0xc) != 0) {
      for (iVar1 = 0; iVar1 < *(int *)(extraout_ECX + 4); iVar1 = iVar1 + 1) {
        FUN_006321f0(*(undefined4 *)(*(int *)(extraout_ECX + 0xc) + iVar1 * 4));
      }
      FUN_006321f0(*(undefined4 *)(extraout_ECX + 0xc));
    }
    if (*(int *)(extraout_ECX + 0x10) != 0) {
      for (iVar1 = 0; iVar1 < *(int *)(extraout_ECX + 4); iVar1 = iVar1 + 1) {
        FUN_006321f0(*(undefined4 *)(*(int *)(extraout_ECX + 0x10) + iVar1 * 4));
      }
      FUN_006321f0(*(undefined4 *)(extraout_ECX + 0x10));
    }
    if (*(int *)(extraout_ECX + 0x14) != 0) {
      for (iVar1 = 0; iVar1 < *(int *)(extraout_ECX + 4); iVar1 = iVar1 + 1) {
        FUN_006321f0(*(undefined4 *)(*(int *)(extraout_ECX + 0x14) + iVar1 * 4));
      }
      FUN_006321f0(*(undefined4 *)(extraout_ECX + 0x14));
    }
    if (*(int *)(extraout_ECX + 0x18) != 0) {
      for (iVar1 = 0; iVar1 < *(int *)(extraout_ECX + 4); iVar1 = iVar1 + 1) {
        FUN_006321f0(*(undefined4 *)(*(int *)(extraout_ECX + 0x18) + iVar1 * 4));
      }
      FUN_006321f0(*(undefined4 *)(extraout_ECX + 0x18));
    }
    if (*(int *)(extraout_ECX + 0x1c) == 0) goto LAB_004c1ac5;
    for (; iVar2 < *(int *)(extraout_ECX + 4); iVar2 = iVar2 + 1) {
      FUN_006321f0(*(undefined4 *)(*(int *)(extraout_ECX + 0x1c) + iVar2 * 4));
    }
    uVar3 = *(undefined4 *)(extraout_ECX + 0x1c);
  }
  else {
    uVar3 = *(undefined4 *)(extraout_ECX + 0xc);
  }
  FUN_006321f0(uVar3);
LAB_004c1ac5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

