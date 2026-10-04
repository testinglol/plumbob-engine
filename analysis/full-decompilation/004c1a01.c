
void FUN_004c1a01(void)

{
  int iVar1;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 uVar2;
  
  if (*(int *)(unaff_ESI + 0x20) < 999) {
    if (*(int *)(unaff_ESI + 0xc) != unaff_EDI) {
      for (iVar1 = 0; iVar1 < *(int *)(unaff_ESI + 4); iVar1 = iVar1 + 1) {
        FUN_006321f0(*(undefined4 *)(*(int *)(unaff_ESI + 0xc) + iVar1 * 4));
      }
      FUN_006321f0(*(undefined4 *)(unaff_ESI + 0xc));
    }
    if (*(int *)(unaff_ESI + 0x10) != unaff_EDI) {
      for (iVar1 = 0; iVar1 < *(int *)(unaff_ESI + 4); iVar1 = iVar1 + 1) {
        FUN_006321f0(*(undefined4 *)(*(int *)(unaff_ESI + 0x10) + iVar1 * 4));
      }
      FUN_006321f0(*(undefined4 *)(unaff_ESI + 0x10));
    }
    if (*(int *)(unaff_ESI + 0x14) != unaff_EDI) {
      for (iVar1 = 0; iVar1 < *(int *)(unaff_ESI + 4); iVar1 = iVar1 + 1) {
        FUN_006321f0(*(undefined4 *)(*(int *)(unaff_ESI + 0x14) + iVar1 * 4));
      }
      FUN_006321f0(*(undefined4 *)(unaff_ESI + 0x14));
    }
    if (*(int *)(unaff_ESI + 0x18) != unaff_EDI) {
      for (iVar1 = 0; iVar1 < *(int *)(unaff_ESI + 4); iVar1 = iVar1 + 1) {
        FUN_006321f0(*(undefined4 *)(*(int *)(unaff_ESI + 0x18) + iVar1 * 4));
      }
      FUN_006321f0(*(undefined4 *)(unaff_ESI + 0x18));
    }
    if (*(int *)(unaff_ESI + 0x1c) == unaff_EDI) goto LAB_004c1ac5;
    for (; unaff_EDI < *(int *)(unaff_ESI + 4); unaff_EDI = unaff_EDI + 1) {
      FUN_006321f0(*(undefined4 *)(*(int *)(unaff_ESI + 0x1c) + unaff_EDI * 4));
    }
    uVar2 = *(undefined4 *)(unaff_ESI + 0x1c);
  }
  else {
    uVar2 = *(undefined4 *)(unaff_ESI + 0xc);
  }
  FUN_006321f0(uVar2);
LAB_004c1ac5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

