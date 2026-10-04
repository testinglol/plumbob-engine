
undefined4 * FUN_0057d56c(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  uVar1 = FUN_00401742(0xc);
  extraout_ECX[1] = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(undefined4 *)(extraout_ECX[1] + 4) = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = FUN_00401742(0xc);
  extraout_ECX[2] = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX[2] + 4) = extraout_ECX[2];
  extraout_ECX[3] = 0;
  *(undefined1 *)(extraout_ECX + 4) = 0;
  *extraout_ECX = &PTR_FUN_006719ac;
  return extraout_ECX;
}

