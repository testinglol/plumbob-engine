
undefined4 * FUN_005f4d1c(void)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0047343b(0,0);
  extraout_ECX[0x3e] = 0xffffffff;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_00675734;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x3b] = 0;
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x3d] = 0;
  *(undefined1 *)(extraout_ECX + 0x3f) = 0;
  extraout_ECX[0x45] = 0;
  piVar2 = (int *)FUN_005e7743();
  uVar3 = (**(code **)(*piVar2 + 0x10))(4);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x39] = uVar3;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

