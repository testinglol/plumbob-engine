
void FUN_00424560(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar4;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  piVar4 = *(int **)(extraout_ECX + 0x154);
  piVar1 = *(int **)(extraout_ECX + 0x158);
  *(undefined4 *)(unaff_EBP + -4) = 7;
  if (piVar4 != piVar1) {
    do {
      iVar2 = *piVar4;
      if (iVar2 != 0) {
        FUN_00410173();
        FUN_006321f0(iVar2);
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != *(int **)(extraout_ECX + 0x158));
  }
  FUN_0042ed71(*(undefined4 *)(extraout_ECX + 0x154),*(undefined4 *)(extraout_ECX + 0x158));
  for (piVar4 = *(int **)(extraout_ECX + 0x148); piVar4 != *(int **)(extraout_ECX + 0x14c);
      piVar4 = piVar4 + 1) {
    iVar2 = *piVar4;
    *(int *)(unaff_EBP + -0x10) = iVar2;
    if (iVar2 != 0) {
      FUN_00423852();
      FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
    }
  }
  FUN_0042ed71(*(undefined4 *)(extraout_ECX + 0x148),*(undefined4 *)(extraout_ECX + 0x14c));
  iVar2 = *(int *)(extraout_ECX + 0x198);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  piVar4 = (int *)(extraout_ECX + 0x194);
  if (iVar2 - *(int *)(extraout_ECX + 0x194) >> 2 != 0) {
    do {
      iVar2 = *(int *)(*piVar4 + *(int *)(unaff_EBP + -0x10) * 4);
      *(int *)(unaff_EBP + -0x14) = iVar2;
      if (iVar2 != 0) {
        FUN_0041f37d();
        FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x14));
      }
      iVar2 = *(int *)(extraout_ECX + 0x198);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(uint *)(unaff_EBP + -0x10) < (uint)(iVar2 - *piVar4 >> 2));
  }
  FUN_0042ed71(*piVar4,*(undefined4 *)(extraout_ECX + 0x198));
  iVar2 = *piVar4;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_0042ebf5();
  uVar3 = *(undefined4 *)(extraout_ECX + 0x174);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  FUN_00542b02();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  uVar3 = *(undefined4 *)(extraout_ECX + 0x154);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  FUN_0048c4c9();
  uVar3 = *(undefined4 *)(extraout_ECX + 0x148);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  uVar3 = *(undefined4 *)(extraout_ECX + 0x110);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
  FUN_00542b02();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

