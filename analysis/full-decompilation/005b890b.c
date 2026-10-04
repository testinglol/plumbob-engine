
int * __fastcall FUN_005b890b(int *param_1)

{
  void *pvVar1;
  char *_Str;
  size_t sVar2;
  
  pvVar1 = operator_new((param_1[1] - *param_1) + 1);
  FUN_006358b0(pvVar1,*param_1);
  _Str = (char *)FUN_0064a52a(pvVar1);
  if (_Str != (char *)0x0) {
    sVar2 = _strlen(_Str);
    FUN_00431779(_Str,_Str + sVar2);
  }
  FUN_006321f0(pvVar1);
  return param_1;
}

