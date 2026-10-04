
undefined4 * FUN_00418fea(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046597b();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0041308b();
  extraout_ECX[7] = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[3] = &PTR_LAB_006668bc;
  *extraout_ECX = &PTR_FUN_0066682c;
  extraout_ECX[6] = 0;
  extraout_ECX[8] = 0;
  *(undefined1 *)(extraout_ECX + 9) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x25) = 0;
  extraout_ECX[10] = 0;
  return extraout_ECX;
}

