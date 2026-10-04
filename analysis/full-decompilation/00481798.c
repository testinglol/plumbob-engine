
undefined4 * FUN_00481798(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046de64();
  uVar1 = *(undefined4 *)(unaff_EBP + 0x10);
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1b] = 0;
  uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
  extraout_ECX[0x1c] = 0;
  FUN_004817ed(*(undefined4 *)(unaff_EBP + 8),uVar2,uVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

