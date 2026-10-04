
undefined4 * FUN_00562c86(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e372a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  extraout_ECX[0x6e] = 0;
  extraout_ECX[0x70] = 0;
  extraout_ECX[0x72] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x6f] = 0;
  extraout_ECX[0x71] = 0;
  extraout_ECX[0x73] = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x65] = 0;
  extraout_ECX[0x66] = 0;
  extraout_ECX[0x67] = 0;
  extraout_ECX[0x74] = 0;
  extraout_ECX[0x75] = 0;
  extraout_ECX[0x77] = uVar1;
  *extraout_ECX = &PTR_FUN_00670a74;
  *(undefined1 *)(extraout_ECX + 0x76) = 1;
  return extraout_ECX;
}

