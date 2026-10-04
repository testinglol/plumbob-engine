
undefined4 __thiscall FUN_0060beeb(int param_1,int *param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_2 + 0x24))(0x40);
  if ((cVar1 != '\0') &&
     (cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x24))(0x40), cVar1 != '\0')) {
    return 1;
  }
  return 0;
}

