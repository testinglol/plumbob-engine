
void FUN_005c1070(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005c1215();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042004f();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c2ee6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

