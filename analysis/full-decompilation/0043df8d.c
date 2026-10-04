
void FUN_0043df8d(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar5;
  
  FUN_00634c24();
  FUN_0043de11();
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_0040555d(unaff_EBP + -0x14);
  for (piVar5 = *(int **)(extraout_ECX + 0x20); piVar5 != *(int **)(extraout_ECX + 0x24);
      piVar5 = piVar5 + 1) {
    iVar2 = *piVar5;
    if (*(int *)(iVar2 + 0xa0) < 1) {
      *(undefined2 *)(iVar2 + 0xa4) = 0;
    }
    else {
      uVar1 = *(undefined2 *)(unaff_EBP + -0x10);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      *(undefined2 *)(iVar2 + 0xa4) = uVar1;
      uVar4 = FUN_0045741b();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
      FUN_0040555d(unaff_EBP + -0x14);
    }
  }
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(int *)(unaff_EBP + -0x38) = extraout_ECX;
  *(int *)(unaff_EBP + -0x1c) = unaff_EBP + -0x38;
  uVar4 = DAT_006c34c8;
  *(int *)(unaff_EBP + -0x30) = unaff_EBP + -0x2c;
  uVar3 = DAT_006e4f08;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x34) = extraout_ECX + 0x1244;
  *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
  *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_0066702c;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00464eab(unaff_EBP + -0x20,3,*(undefined4 *)(unaff_EBP + 8),uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00465055();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004d6053();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

