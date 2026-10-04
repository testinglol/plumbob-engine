
void FUN_005715ab(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0067159c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  DAT_006f63bc = 0;
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX + 0x35;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005824b6();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005481b6();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0042ed0e();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00575a7d();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX + 9;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_005769d6();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005481b6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

