
void FUN_0043de5b(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar3 = *(int **)(extraout_ECX + 0x20);
  if (piVar3 != *(int **)(extraout_ECX + 0x24)) {
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      *(undefined2 *)(iVar1 + 0xa4) = 0;
    } while (piVar3 != *(int **)(extraout_ECX + 0x24));
  }
  FUN_0043de11();
  FUN_0055e4e2(unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00415784(*(undefined4 *)(unaff_EBP + 8));
  *(int *)(unaff_EBP + -0x28) = extraout_ECX + 0x1244;
  *(int *)(unaff_EBP + -0x1c) = unaff_EBP + -0x2c;
  uVar4 = DAT_006c34c8;
  *(int *)(unaff_EBP + -0x24) = unaff_EBP + -0x38;
  uVar2 = DAT_006e4f08;
  *(int *)(unaff_EBP + -0x2c) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
  *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_0066702c;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00464f5b(unaff_EBP + -0x20,*(undefined4 *)(unaff_EBP + 8),uVar2,0);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00465055();
  FUN_004071be(*(undefined4 *)(extraout_ECX + 0x1270),*(undefined4 *)(extraout_ECX + 0x1274));
  *(undefined4 *)(unaff_EBP + 8) = 0;
  FUN_0040555d(unaff_EBP + 8);
  for (piVar3 = *(int **)(extraout_ECX + 0x20); piVar3 != *(int **)(extraout_ECX + 0x24);
      piVar3 = piVar3 + 1) {
    while ((uint)(*(int *)(extraout_ECX + 0x1274) - *(int *)(extraout_ECX + 0x1270) >> 2) <=
           (uint)(int)*(short *)(*piVar3 + 0xa4)) {
      *(undefined4 *)(unaff_EBP + 8) = 0;
      FUN_0040555d(unaff_EBP + 8);
    }
    *(int *)(unaff_EBP + -0x14) = *(int *)(extraout_ECX + 0x1270) + *(short *)(*piVar3 + 0xa4) * 4;
    uVar4 = FUN_0045741b();
    **(undefined4 **)(unaff_EBP + -0x14) = uVar4;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004d6053();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

