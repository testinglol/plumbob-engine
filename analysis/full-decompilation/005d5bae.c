
undefined4 * FUN_005d5bae(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00673884;
  FUN_005d909f();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0060162e();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d5fbc(unaff_EBP + -0xe,unaff_EBP + -0xd);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00673860;
  return extraout_ECX;
}

