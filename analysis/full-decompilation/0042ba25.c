
int __thiscall FUN_0042ba25(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = 1;
  }
  else {
    for (piVar1 = *(int **)(param_1 + 0x174); piVar1 != *(int **)(param_1 + 0x178);
        piVar1 = piVar1 + 2) {
      if (*piVar1 == param_2) {
        return piVar1[1];
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}

