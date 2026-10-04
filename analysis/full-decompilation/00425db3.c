
int __thiscall FUN_00425db3(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x154);
  while( true ) {
    if (piVar1 == *(int **)(param_1 + 0x158)) {
      return 0;
    }
    if (*(int *)(*piVar1 + 0x10c) == param_2) break;
    piVar1 = piVar1 + 1;
  }
  return *piVar1;
}

