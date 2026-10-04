
undefined4 FUN_00460748(undefined4 *param_1,char *param_2)

{
  size_t _Size;
  int iVar1;
  
  _Size = _strlen(param_2);
  if (param_1[1] - (int)*param_1 == _Size) {
    iVar1 = _memcmp((void *)*param_1,param_2,_Size);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}

