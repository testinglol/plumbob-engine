
void FUN_005d5afd(void)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[-2] = &PTR_LAB_006736b4;
  extraout_ECX[-1] = &PTR_LAB_006736a8;
  *extraout_ECX = &PTR_FUN_00673690;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_005fda63();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX + 0x45;
  extraout_ECX[0x45] = &PTR_FUN_006697ec;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_004054b4();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00602489();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d5a0d();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00602e69();
  uVar1 = -(uint)(extraout_ECX != (undefined4 *)0x8) & (uint)(extraout_ECX + -1);
  *(undefined ***)(-(uint)(uVar1 != 0) & uVar1 + 4) = &PTR_LAB_00673720;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

