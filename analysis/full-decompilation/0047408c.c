
undefined4 * FUN_0047408c(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046fca5();
  extraout_ECX[3] = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046fca5();
  extraout_ECX[0x1e] = &PTR_FUN_0066643c;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046f824(extraout_ECX + 0x3c,0,0x100);
  extraout_ECX[0x39] = &PTR_FUN_00666524;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x7c] = 0;
  extraout_ECX[0x7d] = 0;
  extraout_ECX[0x7e] = 0;
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)((int)extraout_ECX + 6) = 0;
  *extraout_ECX = uVar2;
  uVar1 = *(undefined2 *)(unaff_EBP + 0xc);
  extraout_ECX[0x7f] = 5;
  *(undefined2 *)(extraout_ECX + 1) = uVar1;
  extraout_ECX[2] = 0;
  return extraout_ECX;
}

