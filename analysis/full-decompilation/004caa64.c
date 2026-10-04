
undefined4 * FUN_004caa64(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c1719();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c1719();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0047343b(0,0);
  *(undefined1 *)(extraout_ECX + 0x3c) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xf1) = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x40] = 0;
  *(undefined1 *)(extraout_ECX + 0x41) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x105) = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x44] = 6;
  extraout_ECX[0x45] = 1;
  extraout_ECX[0x46] = 0;
  extraout_ECX[0x47] = 0;
  *(undefined1 *)(extraout_ECX + 0x48) = 1;
  *extraout_ECX = &PTR_FUN_006689c0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uVar1 = FUN_005e749a(4);
  FUN_005dde6d(uVar1);
  FUN_004cac05(*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

