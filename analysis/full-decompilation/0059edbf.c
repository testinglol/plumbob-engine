
undefined4 * FUN_0059edbf(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  extraout_ECX[7] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xd] = 0;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xc] = 0;
  FUN_005c4830();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x17] = 0;
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x1b] = 0;
  extraout_ECX[0x1c] = 0;
  extraout_ECX[0x1d] = 0;
  extraout_ECX[0x1e] = DAT_006e5490;
  *(undefined1 *)(extraout_ECX + 0x1f) = 0;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

