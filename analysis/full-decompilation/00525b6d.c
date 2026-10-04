
void FUN_00525b6d(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066d074;
  extraout_ECX[0x35] = &PTR_LAB_0066d064;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00525bfd();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e359a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

