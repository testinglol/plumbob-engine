
undefined4 FUN_005724f5(void)

{
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + 0x18);
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + 0x20);
  FUN_005d4d37();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00575bc0(unaff_EBP + -0x14,unaff_EBP + -0x44);
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x10);
    FUN_00576ee7(unaff_EBP + -0x1c);
  }
  FUN_00575a0a(unaff_EBP + -0x20,unaff_EBP + -0x44);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

