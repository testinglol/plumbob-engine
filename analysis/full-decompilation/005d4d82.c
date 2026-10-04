
int * __fastcall FUN_005d4d82(int *param_1)

{
  void *pvVar1;
  char *_Str;
  size_t sVar2;
  
  pvVar1 = operator_new((param_1[1] - *param_1) + 1);
  (*(code *)PTR_FUN_006d7024)(pvVar1,*param_1);
  _Str = (char *)(*(code *)PTR_FUN_006d70d4)(pvVar1);
  if (_Str != (char *)0x0) {
    sVar2 = _strlen(_Str);
    FUN_00431779(_Str,_Str + sVar2);
  }
  FUN_006321f0(pvVar1);
  return param_1;
}

