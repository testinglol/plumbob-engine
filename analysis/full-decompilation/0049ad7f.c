
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0049ad7f(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0x3f800000;
  *(undefined4 *)(unaff_EBP + -0x7c) = 0;
  uVar1 = _DAT_006682e0;
  *(undefined4 *)(unaff_EBP + -0x78) = _DAT_006682e0;
  *(undefined4 **)(unaff_EBP + -0x90) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x74) = 0;
  *(undefined4 *)(unaff_EBP + -0x70) = 0;
  *(undefined4 *)(unaff_EBP + -0x5c) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x58) = 0;
  *(undefined4 *)(unaff_EBP + -0x54) = 0;
  *(undefined4 *)(unaff_EBP + -0x50) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  uVar1 = FUN_00462e7a(unaff_EBP + -0x2c,unaff_EBP + -0x5c,unaff_EBP + -0x7c,unaff_EBP + -0x4c);
  FUN_005c3650(uVar1);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0x3f800000;
  *(undefined4 *)(unaff_EBP + -0x6c) = 0;
  uVar1 = _DAT_006682dc;
  *(undefined4 *)(unaff_EBP + -0x68) = _DAT_006682dc;
  *(undefined4 *)(unaff_EBP + -100) = 0;
  *(undefined4 *)(unaff_EBP + -0x60) = 0;
  *(undefined4 *)(unaff_EBP + -0x8c) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x88) = 0;
  *(undefined4 *)(unaff_EBP + -0x84) = 0;
  *(undefined4 *)(unaff_EBP + -0x80) = 0;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  uVar1 = FUN_00462e7a(unaff_EBP + -0x3c,unaff_EBP + -0x8c,unaff_EBP + -0x6c,unaff_EBP + -0x1c);
  FUN_005c3650(uVar1);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c35b0();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c35b0();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c35b0();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *extraout_ECX = &PTR_FUN_006682e8;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  _memset(extraout_ECX + 100,0,8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

