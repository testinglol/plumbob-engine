
void FUN_00449d6b(void)

{
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00667220;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00667230;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00464faf(unaff_EBP + -0x1c,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x14))
  ;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00465055();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

