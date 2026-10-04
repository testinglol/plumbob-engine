
undefined4 * FUN_00416ebe(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046597b();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0041308b();
  extraout_ECX[0xb] = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[3] = &PTR_LAB_00666824;
  *extraout_ECX = &PTR_FUN_00666794;
  extraout_ECX[6] = 0;
  extraout_ECX[7] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  *(undefined1 *)(extraout_ECX + 10) = 0;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

