
char __thiscall FUN_004d1a49(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  *(undefined4 *)(param_1 + 0x170) = 0;
  if ((*(int **)(param_1 + 0x174) != (int *)0x0) &&
     (cVar1 = (**(code **)(**(int **)(param_1 + 0x174) + 0x2c))(param_2,param_3), cVar1 != '\0')) {
    return '\x01';
  }
  cVar1 = '\0';
  if (DAT_006e54ac != (int *)0x0) {
    cVar1 = (**(code **)(*DAT_006e54ac + 0x4c))(param_2,param_3);
  }
  if (cVar1 == '\0') {
    cVar1 = FUN_005dd72f(param_2,param_3);
  }
  return cVar1;
}

