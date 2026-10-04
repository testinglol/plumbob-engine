
void FUN_00448657(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x28) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00448a16();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x24) = **(undefined4 **)(unaff_EBP + -0x28);
  FUN_0040189d(*(undefined4 *)(unaff_EBP + -0x24),0x18);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

