
undefined4 * FUN_00606233(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d48d9();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_00676d30;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  FUN_005d4bbf(uVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[10] = 0xffffffff;
  return extraout_ECX;
}

