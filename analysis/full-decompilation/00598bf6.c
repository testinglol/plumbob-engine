
bool __thiscall FUN_00598bf6(int param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_005b9169(*(undefined4 *)(param_1 + 4));
  if ((cVar1 != '\0') &&
     (cVar1 = FUN_005b90ab(*(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2), cVar1 != '\0'))
  {
    cVar1 = FUN_00598c3b(*(undefined4 *)(param_1 + 0x60),param_2);
    return cVar1 != '\0';
  }
  return false;
}

