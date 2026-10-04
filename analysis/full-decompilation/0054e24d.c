
undefined4 * FUN_0054e24d(void)

{
  undefined1 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e372a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00429bf0();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[0x84] = 0;
  extraout_ECX[0x85] = 0;
  FUN_0047343b(0,0);
  uVar1 = *(undefined1 *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined1 *)((int)extraout_ECX + 0x25d) = 0;
  extraout_ECX[0x98] = 1;
  extraout_ECX[0x99] = 0;
  *(undefined1 *)(extraout_ECX + 0x9a) = uVar1;
  *extraout_ECX = &PTR_FUN_00670204;
  FUN_0054df42();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x93] = *(undefined4 *)(unaff_EBP + 8);
  return extraout_ECX;
}

