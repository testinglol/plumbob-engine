
void FUN_004f7613(void)

{
  int *piVar1;
  char *_Str;
  size_t sVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  _Str = (char *)FUN_005d5f70();
  if ((_Str != (char *)0x0) && (DAT_006f2a11 == '\0')) {
    DAT_006f2a11 = '\x01';
    FUN_005d4956(s_Crash_in_006cb454);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    sVar2 = _strlen(_Str);
    FUN_00412d8a(_Str,_Str + sVar2);
    FUN_005d4956(s_Sound_System_Error_006cb440);
    piVar1 = (int *)(DAT_006f2a08 + 0x48);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    (**(code **)(*piVar1 + 0x2c))(unaff_EBP + -0x18,unaff_EBP + -0x24,0,0);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

