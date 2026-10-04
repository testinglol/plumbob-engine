
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00598f28(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *extraout_ECX = 0;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c35b0();
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x1b] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 **)(unaff_EBP + -0x1c) = extraout_ECX + 0x1c;
  FUN_0054821c(0x28,unaff_EBP + -0xd);
  uVar2 = extraout_ECX[0x1c];
  *(undefined1 *)(unaff_EBP + -4) = 4;
  uVar2 = FUN_005fd5b4(uVar2,0x28,unaff_EBP + -0x14,*(undefined4 *)(unaff_EBP + -0x1c));
  extraout_ECX[0x1d] = uVar2;
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x1f] = 0;
  extraout_ECX[0x20] = 0;
  extraout_ECX[0x21] = 0;
  uVar1 = _DAT_0066745c;
  extraout_ECX[0x22] = 0;
  extraout_ECX[0x23] = 0;
  extraout_ECX[0x24] = 0;
  extraout_ECX[0x25] = 1;
  extraout_ECX[0x26] = 1;
  extraout_ECX[0x27] = 0;
  extraout_ECX[0x28] = 0xffffffff;
  extraout_ECX[0x2a] = 0xffffffff;
  extraout_ECX[0x2c] = 0xffffffff;
  extraout_ECX[0x2e] = 0xffffffff;
  extraout_ECX[0x29] = 0;
  extraout_ECX[0x2b] = 0;
  extraout_ECX[0x2d] = 0;
  extraout_ECX[0x2f] = uVar1;
  extraout_ECX[0x30] = uVar1;
  extraout_ECX[0x31] = uVar1;
  uVar1 = _DAT_00667458;
  extraout_ECX[0x32] = _DAT_00667458;
  extraout_ECX[0x33] = uVar1;
  extraout_ECX[0x34] = uVar1;
  *unaff_FS_OFFSET = uVar2;
  return extraout_ECX;
}

