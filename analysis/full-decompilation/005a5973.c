
int FUN_005a5973(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *extraout_ECX;
  int unaff_EBP;
  int iStack_58;
  uint *puStack_54;
  
  FUN_00634c24();
  puVar1 = *(uint **)(unaff_EBP + 8);
  iStack_58 = unaff_EBP + 8;
  puStack_54 = puVar1;
  FUN_005a5c09();
  if ((*(int *)(unaff_EBP + 8) == *extraout_ECX) ||
     (*puVar1 < *(uint *)(*(int *)(unaff_EBP + 8) + 0x10))) {
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(uint *)(unaff_EBP + -0x50) = *puVar1;
    puStack_54 = (uint *)(unaff_EBP + -0x30);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iStack_58 = 0x5a59ca;
    FUN_005a5856();
    puStack_54 = (uint *)(unaff_EBP + -0x50);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(int **)(unaff_EBP + -0x10) = &iStack_58;
    FUN_00602c56(unaff_EBP + 8);
    puVar2 = (undefined4 *)FUN_005a5a86(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + 8) = *puVar2;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    if (*(int *)(unaff_EBP + -0x4c) != 0) {
      puStack_54 = (uint *)0x5a5a00;
      FUN_005e3581();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    if (*(int *)(unaff_EBP + -0x30) != 0) {
      puStack_54 = (uint *)0x5a5a13;
      FUN_005e3581();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(int *)(unaff_EBP + 8) + 0x14;
}

