
void __thiscall FUN_005dae65(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x1cc);
  while( true ) {
    if (piVar2 == *(int **)(param_1 + 0x1d0)) {
      return;
    }
    if (*piVar2 == param_2) break;
    piVar2 = piVar2 + 4;
  }
  if (piVar2 == *(int **)(param_1 + 0x1d0)) {
    return;
  }
  iVar1 = (int)piVar2 - (int)*(int **)(param_1 + 0x1cc) >> 4;
  if (iVar1 < *(int *)(param_1 + 0x1d8)) {
    *(int *)(param_1 + 0x1d8) = *(int *)(param_1 + 0x1d8) + -1;
  }
  if (iVar1 < *(int *)(param_1 + 0x1dc)) {
    *(int *)(param_1 + 0x1dc) = *(int *)(param_1 + 0x1dc) + -1;
  }
  FUN_005db3b0(piVar2);
  return;
}

