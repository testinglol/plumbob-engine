
undefined4 FUN_00533cd8(void)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 8) == 0) {
    uVar1 = FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005d499c(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
  }
  else {
    FUN_005d49b7(*(undefined4 *)(unaff_EBP + 8));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

