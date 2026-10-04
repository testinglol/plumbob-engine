
undefined4 * FUN_0047c307(void)

{
  size_t sVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  sVar1 = _strlen(*(char **)(unaff_EBP + 8));
  FUN_00401a3c(*(undefined4 *)(unaff_EBP + 8),sVar1 + *(int *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

