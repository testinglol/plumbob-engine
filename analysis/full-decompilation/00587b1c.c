
int FUN_00587b1c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *_Str2;
  char *_Str1;
  
  iVar1 = FUN_0046fbe5(0xffffffff);
  iVar2 = FUN_0046fbe5(0xffffffff);
  iVar2 = iVar2 - iVar1;
  for (iVar1 = 1; (iVar2 == 0 && (iVar3 = FUN_0046fbe5(0xffffffff), iVar1 <= iVar3));
      iVar1 = iVar1 + 1) {
    _Str2 = (char *)FUN_004705f2(iVar1,0xffffffff);
    _Str1 = (char *)FUN_004705f2(iVar1,0xffffffff);
    iVar2 = _strcmp(_Str1,_Str2);
  }
  return iVar2;
}

