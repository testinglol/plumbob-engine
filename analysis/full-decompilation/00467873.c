
undefined2 * FUN_00467873(void)

{
  undefined2 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined2 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(extraout_ECX + 2) = 0;
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(extraout_ECX + 6) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  *(undefined4 *)(extraout_ECX + 10) = 0;
  *(undefined4 *)(extraout_ECX + 0xc) = 0;
  *(undefined4 *)(extraout_ECX + 0xe) = 0;
  *(undefined4 *)(extraout_ECX + 0x10) = 0;
  *(undefined4 *)(extraout_ECX + 0x12) = 0;
  *(undefined4 *)(extraout_ECX + 0x14) = 0;
  *(undefined4 *)(extraout_ECX + 0x16) = 0;
  *(undefined4 *)(extraout_ECX + 0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00635e55(extraout_ECX + 0x40,8,0x40,FUN_004678f9,FUN_00416e17);
  *extraout_ECX = *(undefined2 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(extraout_ECX + 0x3c) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined1 *)((int)extraout_ECX + 0x73) = 0;
  FUN_00467999();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

