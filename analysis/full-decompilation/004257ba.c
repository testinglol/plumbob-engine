
void __thiscall FUN_004257ba(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  for (piVar3 = *(int **)(param_1 + 0x148); piVar3 != *(int **)(param_1 + 0x14c);
      piVar3 = piVar3 + 1) {
    iVar1 = *piVar3;
    if (((iVar1 != 0) && (*(int *)(iVar1 + 8) == param_2)) && (iVar2 == 0)) {
      iVar2 = iVar1;
    }
  }
  return;
}

