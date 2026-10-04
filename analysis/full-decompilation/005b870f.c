
undefined4 * FUN_005b870f(void)

{
  char *_Str;
  size_t sVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  _Str = *(char **)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  sVar1 = _strlen(_Str);
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00401a3c(_Str,_Str + sVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

