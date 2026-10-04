
undefined4 * FUN_005cf650(void)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005c35b0();
  uVar1 = extraout_ECX[5];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_006734ac;
  extraout_ECX[5] = uVar1 & 0xfffc0007 | 4;
  FUN_00462f2f(&DAT_006fe6d0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x16] = DAT_006fe710;
  extraout_ECX[5] = extraout_ECX[5] | 3;
  extraout_ECX[1] = 0x7fffffff;
  extraout_ECX[2] = 0x7fffffff;
  extraout_ECX[3] = 0x80000000;
  extraout_ECX[4] = 0x80000000;
  return extraout_ECX;
}

