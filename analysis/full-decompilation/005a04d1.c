
undefined4 * FUN_005a04d1(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x1c) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c35b0();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c35b0();
  *(undefined4 *)(unaff_EBP + -0x10) = 0x3f800000;
  *(undefined4 *)(unaff_EBP + -0x14) = 0x3f800000;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x18) = 0x3f800000;
  *(undefined1 *)(extraout_ECX + 0x2b) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xad) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xae) = 0;
  FUN_005a07ba(unaff_EBP + -0x18,unaff_EBP + -0x14,unaff_EBP + -0x10);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

