
undefined4 * FUN_0048174b(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046de64();
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1b] = 0;
  extraout_ECX[0x1c] = 0;
  FUN_004817ed(0,0,0);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

