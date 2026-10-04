
undefined4 * FUN_0050f7c5(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047343b(0,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x35] = *(undefined4 *)(unaff_EBP + 8);
  *extraout_ECX = &PTR_FUN_0066bc84;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  *(undefined1 *)(extraout_ECX + 0x38) = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  *(undefined1 *)(extraout_ECX + 0x44) = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x45] = 0;
  return extraout_ECX;
}

