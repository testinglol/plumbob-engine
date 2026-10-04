
int * __thiscall FUN_0041f723(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  for (piVar1 = *(int **)(param_1 + 4);
      (piVar2 = *(int **)(param_1 + 8), piVar1 != *(int **)(param_1 + 8) &&
      ((*piVar1 != param_2 || (piVar2 = piVar1, piVar1[1] != param_3)))); piVar1 = piVar1 + 3) {
  }
  return piVar2;
}

