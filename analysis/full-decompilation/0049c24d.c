
undefined4 * FUN_0049c24d(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004a46d5();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00635e55(extraout_ECX + 0x38,0x14,0x20,FUN_0049c428,&LAB_0049c435);
  extraout_ECX[0xe0] = 0;
  extraout_ECX[0xe1] = 0;
  *extraout_ECX = &PTR_FUN_006683c0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x1b] = 0;
  extraout_ECX[0x1c] = 0;
  extraout_ECX[0x1d] = 0;
  extraout_ECX[0x1e] = 0;
  extraout_ECX[0x36] = 0xffffffff;
  extraout_ECX[0x33] = 0xffffffff;
  extraout_ECX[0x10] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 8;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 6;
  extraout_ECX[0xc] = 3;
  extraout_ECX[0xd] = 0x40de9;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[0x13] = 0x80;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xf] = 0x7f;
  extraout_ECX[0x11] = 0x3ea0d973;
  extraout_ECX[0x14] = 0x50743b;
  extraout_ECX[0x15] = 0xe3508;
  extraout_ECX[0x16] = 0x9d7541;
  extraout_ECX[0x17] = 0x513c12;
  extraout_ECX[0x2f] = 0x14d525;
  extraout_ECX[0x30] = 0x1400;
  extraout_ECX[0x31] = 0xfe242e;
  extraout_ECX[0x32] = 0x140000;
  extraout_ECX[0x1f] = 0x20;
  *(undefined1 *)(extraout_ECX + 0x20) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x81) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x82) = 1;
  extraout_ECX[0x21] = 0x3ef40de9;
  extraout_ECX[0x22] = 0x4aa47b44;
  extraout_ECX[0x24] = 0x1e;
  extraout_ECX[0x25] = 0x3c;
  *(undefined1 *)(extraout_ECX + 0x26) = 1;
  extraout_ECX[0x27] = 0xffffffb7;
  extraout_ECX[0x28] = 0x55;
  extraout_ECX[0x29] = 0;
  extraout_ECX[0x2a] = 0;
  extraout_ECX[0x2b] = 800;
  extraout_ECX[0x2c] = 300;
  extraout_ECX[0x2d] = 0x4b0;
  extraout_ECX[0x2e] = 500;
  *(undefined1 *)(extraout_ECX + 0x23) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x8d) = 0;
  FUN_0049c48b(2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

