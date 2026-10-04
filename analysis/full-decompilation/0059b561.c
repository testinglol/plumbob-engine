
undefined4 FUN_0059b561(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (*(int *)(unaff_EBP + 8) == 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  else {
    uVar1 = FUN_00401742(*(int *)(unaff_EBP + 8) << 2);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00520ae5(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
               *(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}

