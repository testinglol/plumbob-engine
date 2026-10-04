
undefined4 * FUN_00492f28(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[6] = 0;
  extraout_ECX[7] = 0;
  extraout_ECX[8] = 0;
  *extraout_ECX = &PTR_FUN_00668194;
  uVar1 = extraout_ECX[4];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0052ea87(extraout_ECX[3],uVar1);
  FUN_0052ea87(extraout_ECX[6],extraout_ECX[7]);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

