
undefined4 * FUN_005f65e3(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005f5b18();
  extraout_ECX[0x49] = &PTR_LAB_00675cb0;
  extraout_ECX[0x4e] = 0;
  extraout_ECX[0x50] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x4c] = 1;
  extraout_ECX[0x4f] = 0;
  extraout_ECX[0x51] = 0;
  uVar1 = FUN_005fd96f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x52] = uVar1;
  extraout_ECX[0x54] = 0;
  *(undefined1 *)(extraout_ECX + 0x55) = 1;
  *extraout_ECX = &PTR_FUN_00675ac8;
  extraout_ECX[0x49] = &PTR_LAB_00675aac;
  extraout_ECX[0x3c] = 0;
  return extraout_ECX;
}

