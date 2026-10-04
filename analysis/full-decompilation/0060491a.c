
void FUN_0060491a(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[-2] = &PTR_LAB_00676c60;
  extraout_ECX[-1] = &PTR_LAB_00676c54;
  *extraout_ECX = &PTR_FUN_00676c3c;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00607be8();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005eed93();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005d5afd();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

