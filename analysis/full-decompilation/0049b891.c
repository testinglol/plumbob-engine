
undefined4 FUN_0049b891(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005c36c0(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0049b8e7();
  FUN_005c36c0(unaff_EBP + -0x54);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

