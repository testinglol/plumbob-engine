
undefined4 * FUN_005e7749(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined1 *)(extraout_ECX + 1) = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  *extraout_ECX = &PTR_LAB_006743bc;
  FUN_005d5fbc(unaff_EBP + -0xe,unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d5fbc(unaff_EBP + -0x10,unaff_EBP + -0xf);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004a42c7(unaff_EBP + -0xd,unaff_EBP + -0xe);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d5fbc(unaff_EBP + -0xf,unaff_EBP + -0x10);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00674364;
  return extraout_ECX;
}

