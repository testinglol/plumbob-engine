
void FUN_0059541d(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_ECX;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  iVar3 = *(int *)(extraout_ECX + 0x20);
  piVar1 = (int *)(extraout_ECX + 0x1c);
  iVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  iVar3 = iVar3 - *piVar1 >> 2;
  *(int *)(unaff_EBP + -0x14) = iVar3;
  if (0 < iVar3) {
    do {
      iVar3 = *(int *)(*piVar1 + iVar4 * 4);
      *(int *)(unaff_EBP + -0x10) = iVar3;
      if (iVar3 != 0) {
        FUN_00594d07();
        FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_EBP + -0x14));
  }
  if (*(int *)(extraout_ECX + 0x18) != 0) {
    FUN_005942ab();
  }
  *(undefined4 *)(extraout_ECX + 0x18) = 0;
  uVar2 = *(undefined4 *)(extraout_ECX + 0x28);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_0048c4c9();
  iVar3 = *piVar1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar3;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

