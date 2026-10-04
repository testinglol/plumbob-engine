
void FUN_0054cb4f(void)

{
  int *piVar1;
  char cVar2;
  char *_Str;
  size_t sVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(char *)(extraout_ECX + 0x1c4) == '\0') && (*(char *)(extraout_ECX + 0x128) != '\0')) {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004f2baf(unaff_EBP + -0x18);
    _Str = (char *)FUN_0041532c(0x58);
    sVar3 = _strlen(_Str);
    FUN_00412d8a(_Str,_Str + sVar3);
    sVar3 = _strlen(s___dtl_006cdab0);
    FUN_00412d8a(s___dtl_006cdab0,s___dtl_006cdab0 + sVar3);
    cVar2 = FUN_005d8a11(unaff_EBP + -0x18);
    piVar1 = *(int **)(extraout_ECX + 0x180);
    if ((char)piVar1[0x5a] != cVar2) {
      *(char *)(piVar1 + 0x5a) = cVar2;
      (**(code **)(*piVar1 + 0x168))();
    }
    *(undefined1 *)(extraout_ECX + 0x1c4) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

