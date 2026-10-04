
undefined4 FUN_0040698d(void)

{
  int unaff_EBP;
  undefined4 uVar1;
  
  FUN_00634c24();
  uVar1 = 0;
  FUN_004659fc(0);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040690b(unaff_EBP + -0x18);
  if (0 < *(short *)(unaff_EBP + 8)) {
    if ((uint)(int)*(short *)(unaff_EBP + 8) <=
        (uint)(*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18) >> 2)) {
      uVar1 = *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + -4 + *(short *)(unaff_EBP + 8) * 4);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

