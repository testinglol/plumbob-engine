
undefined4 * FUN_0052a597(void)

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
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *extraout_ECX = &PTR_FUN_0066d910;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x3c] = 0;
  _memset(extraout_ECX + 0x36,0,0x18);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x3d] = 0;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

