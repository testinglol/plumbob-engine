
void FUN_005648aa(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00670e10;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_00565340();
  DAT_006fea20 = extraout_ECX[0x118];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00635f6d(extraout_ECX + 0x48,0x60,6,&LAB_00564842);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

