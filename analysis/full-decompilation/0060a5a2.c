
undefined4 * FUN_0060a5a2(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_006770f4;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 5;
  extraout_ECX[3] = 0xc;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[6] = 0;
  extraout_ECX[7] = 0;
  *(undefined1 *)(extraout_ECX + 8) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x21) = 0;
  pvVar1 = operator_new(0xc);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[9] = uVar2;
  return extraout_ECX;
}

