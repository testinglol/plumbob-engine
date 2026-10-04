
void FUN_004f7325(void)

{
  char *_Str;
  char *_Str_00;
  size_t sVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  if (((DAT_006f29f5 != '\0') && (_Str = *(char **)(unaff_EBP + 8), _Str != (char *)0x0)) &&
     (_Str_00 = *(char **)(unaff_EBP + 0xc), _Str_00 != (char *)0x0)) {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    sVar1 = _strlen(s_The_skill___006cb2d8);
    FUN_00412d8a(s_The_skill___006cb2d8,s_The_skill___006cb2d8 + sVar1);
    sVar1 = _strlen(_Str);
    FUN_00412d8a(_Str,_Str + sVar1);
    sVar1 = _strlen(s___could_not_be_loaded_because_th_006cb2fc);
    FUN_00412d8a(s___could_not_be_loaded_because_th_006cb2fc,
                 s___could_not_be_loaded_because_th_006cb2fc + sVar1);
    sVar1 = _strlen(_Str_00);
    FUN_00412d8a(_Str_00,_Str_00 + sVar1);
    sVar1 = _strlen(s__cfp__is_not_present__006cb2e4);
    FUN_00412d8a(s__cfp__is_not_present__006cb2e4,s__cfp__is_not_present__006cb2e4 + sVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

