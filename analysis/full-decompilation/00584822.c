
undefined4 * FUN_00584822(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[6] = 0;
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  extraout_ECX[7] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c35b0();
  extraout_ECX[0x1f] = 0;
  extraout_ECX[0x20] = DAT_00671d64;
  extraout_ECX[0x21] = DAT_00671d64;
  uVar1 = DAT_00671d64;
  extraout_ECX[0x23] = 0;
  extraout_ECX[0x26] = 0xffffffff;
  extraout_ECX[0x27] = 0xffffffff;
  extraout_ECX[0x24] = 0;
  extraout_ECX[0x22] = uVar1;
  extraout_ECX[0x28] = 0;
  extraout_ECX[0x25] = 0;
  extraout_ECX[0x29] = 0;
  *(undefined1 *)(extraout_ECX + 0x2a) = 0;
  extraout_ECX[0x2b] = 0x3c;
  extraout_ECX[0x2c] = 0x5a;
  extraout_ECX[0x2d] = 0;
  extraout_ECX[0x2e] = 0;
  extraout_ECX[0x2f] = 0;
  extraout_ECX[0x30] = 0;
  extraout_ECX[0x31] = 0;
  extraout_ECX[0x32] = 0;
  extraout_ECX[0x33] = 0;
  extraout_ECX[0x34] = 0;
  extraout_ECX[0x35] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined1 *)(extraout_ECX + 0x36) = 1;
  *(undefined1 *)((int)extraout_ECX + 0xd9) = 1;
  *(undefined1 *)((int)extraout_ECX + 0xda) = 1;
  *(undefined1 *)((int)extraout_ECX + 0xdb) = 1;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0xbf800000;
  FUN_0047343b(0,0);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined1 *)(extraout_ECX + 0x3d) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xf5) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xf6) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xf7) = 1;
  *(undefined1 *)(extraout_ECX + 0x3e) = 0;
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  *(undefined1 *)(extraout_ECX + 0x42) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x109) = 0;
  FUN_004733c6();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  *extraout_ECX = &PTR_LAB_00671d6c;
  uVar1 = FUN_0058567b();
  extraout_ECX[0x2d] = uVar1;
  if (extraout_ECX[0x30] == extraout_ECX[0x31]) {
    pvVar2 = operator_new(0x1c);
    *(void **)(unaff_EBP + -0x18) = pvVar2;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    if (pvVar2 == (void *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_0058364c();
    }
    *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005873ba(unaff_EBP + -0x10);
  }
  FUN_0047342b(0x3c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

