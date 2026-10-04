
void FUN_0050814b(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066a830;
  *(undefined4 *)(unaff_EBP + -4) = 5;
  FUN_00508367();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00635f6d(extraout_ECX + 0x72,0xc,5,FUN_005b8770);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00635f6d(extraout_ECX + 0x48,0xc,0xe,FUN_005b8770);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

