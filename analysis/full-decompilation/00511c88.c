
undefined4 FUN_00511c88(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = FUN_004705f2(*(int *)(unaff_EBP + 0xc) + 1,0xffffffff);
  FUN_005d4bbf(uVar1);
  uVar1 = FUN_004705f2(1,0xffffffff);
  FUN_005d4bbf(uVar1);
  if (*(undefined1 **)(unaff_EBP + -0x1c) == &DAT_006de560) {
    FUN_005b86bd(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
  }
  else {
    FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x1c));
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

