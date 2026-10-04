
bool __fastcall FUN_00523acd(int param_1)

{
  int iVar1;
  char *_Str;
  size_t sVar2;
  
  iVar1 = *(int *)(param_1 + 0xf0);
  if (iVar1 != 0) {
    _Str = *(char **)(iVar1 + 0xe4);
    sVar2 = _strlen(_Str);
    FUN_00431779(_Str,_Str + sVar2);
  }
  return iVar1 != 0;
}

