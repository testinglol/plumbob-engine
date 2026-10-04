
undefined4 * FUN_005e6010(void)

{
  undefined1 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_005e6b5a(unaff_EBP + -0xe,unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005e6bc5(unaff_EBP + -0x10,unaff_EBP + -0xf);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005e5d99();
  uVar1 = *(undefined1 *)(unaff_EBP + 8);
  *(undefined1 *)((int)extraout_ECX + 0x49) = 0;
  extraout_ECX[0x13] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined1 *)(extraout_ECX + 0x12) = uVar1;
  *extraout_ECX = &PTR_FUN_0067434c;
  FUN_005e6125(&DAT_006d75dc,FUN_005e6862,extraout_ECX,s_help__command____shows_all_comma_006d75e4);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

