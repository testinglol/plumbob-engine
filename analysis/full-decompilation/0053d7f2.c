
undefined4 * FUN_0053d7f2(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined1 *)((int)extraout_ECX + 6) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)((int)extraout_ECX + 9) = 0;
  *(undefined1 *)(extraout_ECX + 3) = 0;
  *(undefined1 *)(extraout_ECX + 7) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1d) = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xf] = 0;
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x11] = 0;
  *extraout_ECX = &PTR_FUN_0066f3d0;
  *(undefined1 *)(extraout_ECX + 1) = 0xff;
  *(undefined1 *)((int)extraout_ECX + 5) = 0xff;
  *(undefined1 *)((int)extraout_ECX + 6) = 0;
  *(undefined1 *)((int)extraout_ECX + 7) = 0xff;
  *(undefined1 *)(extraout_ECX + 2) = 0xff;
  *(undefined1 *)((int)extraout_ECX + 9) = 0;
  *(undefined1 *)((int)extraout_ECX + 10) = 0xff;
  *(undefined1 *)((int)extraout_ECX + 0xb) = 0xff;
  *(undefined1 *)(extraout_ECX + 3) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  extraout_ECX[4] = 8;
  extraout_ECX[5] = 0xffffffff;
  extraout_ECX[6] = 0xffffffff;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[0x16] = 0;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  *(undefined1 *)(extraout_ECX + 0x12) = 0;
  FUN_0053ff32(0x40);
  FUN_0053ff32(0x40);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

