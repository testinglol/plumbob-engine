
void FUN_005e7450(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0067435c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005e7588(1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e7604();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

