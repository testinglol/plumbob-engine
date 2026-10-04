
undefined4 FUN_0057b37e(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar1 = operator_new(0x14);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005d499c(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)((int)pvVar1 + 0xc) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)((int)pvVar1 + 0x10) = *(undefined4 *)(unaff_EBP + 0x10);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  FUN_00601324(unaff_EBP + -0x10);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

