
void FUN_00566d9f(void)

{
  int *piVar1;
  char cVar2;
  char *_Str;
  size_t sVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(char *)(extraout_ECX + 0x44c) == '\0') && (*(char *)(extraout_ECX + 0x3b4) != '\0')) {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004f2baf(unaff_EBP + -0x18);
    _Str = (char *)FUN_0041532c(0x58);
    sVar3 = _strlen(_Str);
    FUN_00412d8a(_Str,_Str + sVar3);
    sVar3 = _strlen(s___stl_006ce320);
    FUN_00412d8a(s___stl_006ce320,s___stl_006ce320 + sVar3);
    cVar2 = FUN_005d8a11(unaff_EBP + -0x18);
    piVar1 = *(int **)(extraout_ECX + 0x408);
    if ((char)piVar1[0x5a] != cVar2) {
      *(char *)(piVar1 + 0x5a) = cVar2;
      (**(code **)(*piVar1 + 0x168))();
    }
    *(undefined1 *)(extraout_ECX + 0x44c) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

