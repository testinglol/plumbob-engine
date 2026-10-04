
undefined4 * FUN_005a54cd(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  puVar2 = (undefined4 *)FUN_00401742(0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + -0x14) = puVar2;
  *puVar2 = 0;
  puVar1 = puVar2 + 1;
  *(undefined4 **)(unaff_EBP + -0x18) = puVar1;
  *(undefined4 **)(unaff_EBP + -0x1c) = puVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_005a55af(*(undefined4 *)(unaff_EBP + 8));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar2;
}

