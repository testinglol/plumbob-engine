
int * __thiscall FUN_00410263(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 300);
  while( true ) {
    if (piVar1 == *(int **)(param_1 + 0x130)) {
      return (int *)0x0;
    }
    if (*piVar1 == param_2) break;
    piVar1 = piVar1 + 1;
  }
  return piVar1;
}

