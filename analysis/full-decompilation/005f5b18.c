
undefined4 * FUN_005f5b18(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x35] = 2;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0x20;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x3b] = 0;
  extraout_ECX[0x3c] = 0;
  *(undefined1 *)(extraout_ECX + 0x41) = 0;
  extraout_ECX[0x42] = 0;
  *(undefined1 *)(extraout_ECX + 0x47) = 1;
  *extraout_ECX = &PTR_FUN_006758d4;
  FUN_005f6557(0,0,0x20,0x60);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)((int)extraout_ECX + 0x11d) = 0;
  extraout_ECX[0x48] = 0;
  return extraout_ECX;
}

