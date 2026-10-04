
void FUN_0057d80c(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00671a74;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0057da7d();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0057ce80();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_006029b3();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00671918;
  return;
}

