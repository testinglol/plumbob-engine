
undefined4 FUN_004faaff(void)

{
  undefined4 uVar1;
  char *_Str;
  size_t sVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005d48d9();
  uVar1 = *(undefined4 *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d4bbf(uVar1);
  sVar2 = _strlen(&DAT_006c3d7c);
  FUN_00412d8a(&DAT_006c3d7c,&DAT_006c3d7c + sVar2);
  _Str = *(char **)(extraout_ECX + 8);
  sVar2 = _strlen(_Str);
  FUN_00412d8a(_Str,_Str + sVar2);
  FUN_005b86bd(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

