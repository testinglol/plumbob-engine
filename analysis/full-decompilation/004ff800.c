
void FUN_004ff800(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00669c90;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_004ff9de();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00635f6d(extraout_ECX + 0x47,0x10,4,FUN_00416e17);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

