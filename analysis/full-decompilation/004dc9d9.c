
undefined4 * FUN_004dc9d9(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX + 1;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  FUN_00401aae(8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00401a79();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[4] = 0;
  *extraout_ECX = &PTR_LAB_0066933c;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

