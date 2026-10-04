
undefined4 * FUN_00604890(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d56da();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005eea7d();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00607b44();
  *extraout_ECX = &PTR_LAB_00676c60;
  extraout_ECX[1] = &PTR_LAB_00676c54;
  extraout_ECX[2] = &PTR_FUN_00676c3c;
  DAT_006fefc4 = GetModuleHandleA((LPCSTR)0x0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

