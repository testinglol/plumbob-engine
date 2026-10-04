
undefined4 * FUN_005c32ce(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005c1719();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  extraout_ECX[1] = 0;
  extraout_ECX[7] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = 0;
  extraout_ECX[6] = 0x80000000;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

