
int __thiscall FUN_0041f7a9(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  for (piVar2 = *(int **)(param_1 + 4); piVar2 != *(int **)(param_1 + 8); piVar2 = piVar2 + 3) {
    if (*piVar2 == param_2) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

