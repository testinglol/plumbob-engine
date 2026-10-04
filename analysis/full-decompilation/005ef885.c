
undefined4 FUN_005ef885(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005eec0c();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 == (undefined4 *)0x0) {
    _memset((void *)(unaff_EBP + -0x44),0,0x10);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x44) = *puVar1;
    *(undefined4 *)(unaff_EBP + -0x40) = puVar1[1];
    *(undefined4 *)(unaff_EBP + -0x3c) = puVar1[2];
    *(undefined4 *)(unaff_EBP + -0x38) = puVar1[3];
  }
  FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 0xc));
  FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 0x10));
  FUN_005f05c2(unaff_EBP + -0x44);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005eed47();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

