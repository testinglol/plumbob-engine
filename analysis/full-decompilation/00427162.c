
int __fastcall FUN_00427162(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = *(int **)(param_1 + 0x14c);
  iVar3 = 0;
  for (piVar4 = *(int **)(param_1 + 0x148); piVar4 != piVar1; piVar4 = piVar4 + 1) {
    if (*piVar4 != 0) {
      cVar2 = FUN_00423f63();
      if (cVar2 != '\0') {
        iVar3 = iVar3 + 1;
      }
    }
  }
  return iVar3;
}

