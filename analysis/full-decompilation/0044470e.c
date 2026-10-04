
void FUN_0044470e(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x28) = extraout_ECX;
  pvVar1 = operator_new(0x78);
  *(void **)(unaff_EBP + -0x18) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + -0x18) == 0) {
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  }
  else {
    uVar2 = FUN_00435ed2(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -0x2c) = uVar2;
  }
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x14);
  FUN_004360c1(0,*(undefined4 *)(unaff_EBP + 0xc));
  FUN_00448554(unaff_EBP + -0x10);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

