
void FUN_0042a889(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042ee97();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005d9122();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

