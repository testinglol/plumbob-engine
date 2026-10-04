
undefined4 * FUN_005dbd68(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00673ce0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[6] = 0;
  extraout_ECX[7] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  uVar1 = FUN_00401742(0xc);
  extraout_ECX[0xe] = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(undefined4 *)(extraout_ECX[0xe] + 4) = extraout_ECX[0xe];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0xf) = 0;
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x12] = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x17] = 0;
  *(undefined1 *)(extraout_ECX + 0x18) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x61) = 1;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  *(undefined1 *)(extraout_ECX + 0x1b) = 0;
  FUN_005d48d9();
  extraout_ECX[0x1f] = 0;
  extraout_ECX[0x20] = 0;
  extraout_ECX[0x21] = 0;
  extraout_ECX[0x22] = 0;
  extraout_ECX[0x23] = 0;
  extraout_ECX[0x24] = 0;
  extraout_ECX[0x25] = 0;
  extraout_ECX[0x26] = 0;
  uVar1 = DAT_006d7440;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  extraout_ECX[0x27] = uVar1;
  FUN_0047343b(0,0);
  *extraout_ECX = &PTR_FUN_00673b40;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005da404(extraout_ECX);
  extraout_ECX[0x28] = 0;
  extraout_ECX[0x29] = DAT_006d7444;
  extraout_ECX[0x2a] = 0x96;
  extraout_ECX[0x2b] = 0;
  extraout_ECX[0x2d] = 0;
  extraout_ECX[0x34] = 0;
  *(undefined1 *)(extraout_ECX + 0x2c) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

