
void FUN_0042afde(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042eb29();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

