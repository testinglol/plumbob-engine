
undefined4 FUN_0053308c(char *param_1,undefined4 *param_2)

{
  size_t _Size;
  int iVar1;
  
  _Size = _strlen(param_1);
  if (_Size == param_2[1] - (int)*param_2) {
    iVar1 = _memcmp(param_1,(void *)*param_2,_Size);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}

