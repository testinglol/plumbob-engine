
undefined4 FUN_0059787c(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar1 = operator_new(0x80);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005978f7();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005972be();
  FUN_00597a90(*(undefined4 *)(unaff_EBP + 8),extraout_ECX,*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
               *(undefined4 *)(unaff_EBP + 0x18),*(undefined4 *)(unaff_EBP + 0x1c));
  FUN_0059b11b(unaff_EBP + -0x10);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x78) = 0;
  return *(undefined4 *)(unaff_EBP + -0x10);
}

