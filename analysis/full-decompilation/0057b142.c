
undefined4 * FUN_0057b142(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  *extraout_ECX = &PTR_FUN_006698c8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[4] = *(undefined4 *)(unaff_EBP + 0xc);
  uVar1 = FUN_00401742(0xc);
  extraout_ECX[5] = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(undefined4 *)(extraout_ECX[5] + 4) = extraout_ECX[5];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0057be3a(unaff_EBP + -0xd,unaff_EBP + 0xf);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00671754;
  return extraout_ECX;
}

