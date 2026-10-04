
void FUN_004f725b(void)

{
  size_t sVar1;
  char *_Str;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006f29f5 != '\0') {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    sVar1 = _strlen(s_Object___006cb2cc);
    FUN_00412d8a(s_Object___006cb2cc,s_Object___006cb2cc + sVar1);
    thunk_FUN_00457ea7();
    _Str = (char *)FUN_004096c2();
    sVar1 = _strlen(_Str);
    FUN_00412d8a(_Str,_Str + sVar1);
    sVar1 = _strlen(s___is_attempting_to_run_the_anima_006cb29c);
    FUN_00412d8a(s___is_attempting_to_run_the_anima_006cb29c,
                 s___is_attempting_to_run_the_anima_006cb29c + sVar1);
    sVar1 = _strlen(*(char **)(unaff_EBP + 0xc));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0xc),sVar1 + *(int *)(unaff_EBP + 0xc));
    sVar1 = _strlen(s____and_the_skill_does_not_seem_t_006cb254);
    FUN_00412d8a(s____and_the_skill_does_not_seem_t_006cb254,
                 s____and_the_skill_does_not_seem_t_006cb254 + sVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

