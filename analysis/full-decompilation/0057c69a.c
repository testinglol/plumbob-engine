
undefined4 * FUN_0057c69a(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = 0;
  *(undefined4 **)(unaff_EBP + -0x1c) = extraout_ECX;
  *extraout_ECX = 0;
  FUN_0057befc();
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0057c4d2();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[0x17] = 0;
  *(undefined1 *)(extraout_ECX + 0x18) = 0;
  FUN_005bc6b5(0xffffffff);
  FUN_00580a42(100,unaff_EBP + -0xf,unaff_EBP + -0xe,unaff_EBP + -0xd);
  extraout_ECX[0x25] = 0;
  extraout_ECX[0x26] = 0;
  extraout_ECX[0x27] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  extraout_ECX[0x28] = 0x3fffffff;
  extraout_ECX[0x29] = 0;
  FUN_00575830(unaff_EBP + -0xf);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  uVar1 = FUN_00401742(0x18);
  extraout_ECX[0x2c] = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(undefined4 *)(extraout_ECX[0x2c] + 4) = extraout_ECX[0x2c];
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_00580b42(100,unaff_EBP + -0xd,unaff_EBP + -0xe,unaff_EBP + -0xf);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  extraout_ECX[0x33] = 0;
  extraout_ECX[0x34] = 0;
  extraout_ECX[0x35] = 0;
  FUN_00580b92(100,unaff_EBP + -0x12,unaff_EBP + -0x11,unaff_EBP + -0x10);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_00580be2(100,unaff_EBP + -0xd,unaff_EBP + -0xe,unaff_EBP + -0xf);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  extraout_ECX[0x40] = 0;
  FUN_005d909f();
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_005d909f();
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_00575830(unaff_EBP + -0x12);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  extraout_ECX[0x54] = 0;
  FUN_00580c32(100,unaff_EBP + -0xf,unaff_EBP + -0x10,unaff_EBP + -0x11);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_00580c82(100,unaff_EBP + -0xd,unaff_EBP + -0xe,unaff_EBP + -0x12);
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_00580ad6(0x100,unaff_EBP + -0x18);
  do {
    extraout_ECX[0x28] = extraout_ECX[0x28] + 1;
    *(undefined4 *)(iVar2 + extraout_ECX[0x25]) = extraout_ECX[0x28];
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x400);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

