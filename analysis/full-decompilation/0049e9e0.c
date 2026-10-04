
undefined4 * FUN_0049e9e0(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *extraout_ECX = &PTR_FUN_0066843c;
  extraout_ECX[4] = uVar1;
  FUN_0049eb1c(uVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

