
undefined4 * FUN_004dfbc8(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d909f();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d909f();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d909f();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d909f();
  extraout_ECX[0x26] = 0;
  extraout_ECX[0x27] = 0;
  extraout_ECX[0x28] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  extraout_ECX[0x1c] = 0;
  pvVar1 = operator_new(0x20);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005ed88f();
  }
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *extraout_ECX = uVar2;
  FUN_005ed902();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

