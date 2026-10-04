
void FUN_004e656a(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(unaff_EBP + -0x120,0,0x104);
  *(undefined ***)(unaff_EBP + -300) = &PTR_FUN_006664e8;
  uVar1 = FUN_0041532c(7,s_options_iff_006c9cf4,unaff_EBP + -300);
  FUN_004ee9ce(uVar1);
  iVar2 = FUN_00465a37(unaff_EBP + -300,1);
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x10) = 0x4f70746e;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00669400;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00464eab(unaff_EBP + -0x18,0,unaff_EBP + -0x370,0x80);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_00465055();
    FUN_0046b7ee();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

