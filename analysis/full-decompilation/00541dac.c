
void FUN_00541dac(void)

{
  int unaff_EBP;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x541db6;
  FUN_00634c24();
  uStack_4 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uStack_8 = 0x541dc5;
  FUN_005412f4();
  uStack_4 = *(undefined4 *)(unaff_EBP + 0x18);
  *(undefined4 **)(unaff_EBP + 0x10) = &uStack_8;
  FUN_005412dc(unaff_EBP + 0x14);
  FUN_00542013(*(undefined4 *)(unaff_EBP + 8),0,
               *(int *)(unaff_EBP + 0xc) - *(int *)(unaff_EBP + 8) >> 2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    uStack_4 = 0x541dfe;
    FUN_0053d900();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

