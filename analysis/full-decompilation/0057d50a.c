
undefined4 FUN_0057d50a(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar1 = operator_new(0x14);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0057d56c();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
  iVar3 = FUN_00581d7d(unaff_EBP + -0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(iVar3 + 4) = uVar2;
  return uVar2;
}

