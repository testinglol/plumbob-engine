
undefined4 * FUN_0050806c(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0047343b(0,0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00635e55(extraout_ECX + 0x48,0xc,0xe,FUN_005d48d9,FUN_005b8770);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00635e55(extraout_ECX + 0x72,0xc,5,FUN_005d48d9,FUN_005b8770);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d48d9();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x35] = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(extraout_ECX + 0x3c) = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x46] = 0;
  extraout_ECX[0x47] = 0;
  *extraout_ECX = &PTR_FUN_0066a830;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

