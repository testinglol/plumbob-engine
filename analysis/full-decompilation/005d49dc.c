
undefined4 __thiscall FUN_005d49dc(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  size_t _Size;
  
  _Size = param_1[1] - (int)*param_1;
  if ((_Size == param_2[1] - (int)*param_2) &&
     (iVar1 = _memcmp((void *)*param_1,(void *)*param_2,_Size), iVar1 == 0)) {
    return 1;
  }
  return 0;
}

