
undefined4 * FUN_004cb630(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[6] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_00668b60;
  extraout_ECX[8] = uVar1;
  extraout_ECX[9] = uVar2;
  FUN_0049eb1c(uVar1);
  FUN_0049eb1c(*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[7] = 0;
  return extraout_ECX;
}

