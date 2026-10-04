
int FUN_005bfe47(void)

{
  char *_Str1;
  int iVar1;
  
  if (DAT_006d2878 == -3) {
    DAT_006d2878 = 0;
    _Str1 = (char *)FUN_00637627(0,0);
    if (_Str1 != (char *)0x0) {
      iVar1 = _strcmp(_Str1,&DAT_006c0fe8);
      if (iVar1 == 0) {
        _Str1 = (char *)FUN_00637627(0,&DAT_006de560);
      }
      if (_Str1 != (char *)0x0) {
        iVar1 = FUN_006363c0(_Str1,&DAT_006c26dc);
        if (iVar1 != 0) {
          DAT_006d2878 = FUN_00635f62(iVar1 + 1);
        }
      }
    }
  }
  return DAT_006d2878;
}

