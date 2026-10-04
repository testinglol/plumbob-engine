
undefined4 FUN_004d6339(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar3;
  
  FUN_00634c24();
  uVar3 = extraout_ECX;
  pvVar1 = operator_new(1);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  uVar2 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004e07ca(uVar3);
  }
  DAT_006f2358 = uVar2;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

