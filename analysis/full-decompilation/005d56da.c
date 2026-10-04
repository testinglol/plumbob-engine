
undefined4 * FUN_005d56da(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *extraout_ECX = &PTR_LAB_00673738;
  extraout_ECX[3] = 0;
  extraout_ECX[2] = &PTR_LAB_00673720;
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[1] = &PTR_LAB_00673714;
  extraout_ECX[2] = &PTR_FUN_006736fc;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[4] = 0;
  FUN_00602e26();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d586f();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d5bae();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d57b6();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  extraout_ECX[0x4e] = 0;
  FUN_005fd983();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *extraout_ECX = &PTR_LAB_006736b4;
  extraout_ECX[1] = &PTR_LAB_006736a8;
  extraout_ECX[2] = &PTR_FUN_00673690;
  pvVar1 = operator_new(0xe0);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00603243();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x4e] = uVar2;
  extraout_ECX[0x6b] = 0;
  *(undefined1 *)(extraout_ECX + 0x4f) = 1;
  return extraout_ECX;
}

