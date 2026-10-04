
undefined4 FUN_005d969a(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(extraout_ECX + 0x48) = DAT_006fe8bc;
  pvVar1 = operator_new(0x14);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  uVar2 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_005e73e4();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x170) = uVar2;
  FUN_004d5360();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x1bc) = 1;
  return 1;
}

