
void FUN_005dbeb0(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00673b40;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_005dc217();
  FUN_005da467(extraout_ECX);
  FUN_005da55e(extraout_ECX);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006029b3();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

