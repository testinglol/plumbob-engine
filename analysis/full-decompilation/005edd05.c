
void FUN_005edd05(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00675260;
  *(undefined4 *)(unaff_EBP + -4) = 5;
  FUN_005edeab();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_004054b4();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00635f6d(extraout_ECX + 0x3e,0xc,4,FUN_005b8770);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

