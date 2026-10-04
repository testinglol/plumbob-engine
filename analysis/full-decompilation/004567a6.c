
undefined4 * FUN_004567a6(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x91] = 0;
  extraout_ECX[0x92] = 0;
  extraout_ECX[0x93] = 0;
  extraout_ECX[0x94] = 0;
  extraout_ECX[0x95] = 0;
  extraout_ECX[0x96] = 0;
  extraout_ECX[0x97] = 0;
  extraout_ECX[0x98] = 0;
  extraout_ECX[0x99] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *extraout_ECX = &PTR_FUN_006672b0;
  FUN_0046b266();
  FUN_0046b26e(2,&DAT_006c2648);
  FUN_0046b26e(2,&DAT_006c4364);
  FUN_0046b26e(2,&DAT_006c435c);
  FUN_0046b26e(3,&DAT_006c34cc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

