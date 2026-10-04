
void FUN_005ba44c(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = extraout_ECX + 0xc;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005bb5f0();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005481b6();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

