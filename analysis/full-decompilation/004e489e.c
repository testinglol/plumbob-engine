
undefined4 * FUN_004e489e(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *extraout_ECX = 0xffffffff;
  *(undefined2 *)(extraout_ECX + 1) = 0xffff;
  *(undefined2 *)((int)extraout_ECX + 6) = 0xffff;
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046f824(extraout_ECX + 5,0,0x40);
  extraout_ECX[2] = &PTR_FUN_0066651c;
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX + 0x15;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x17] = 0;
  FUN_00401aae(8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00401a79();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX + 0x18;
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  FUN_00401aae(8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00401a79();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

