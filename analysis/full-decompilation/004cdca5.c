
int __thiscall FUN_004cdca5(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_2 + 0x84);
  if (iVar1 == 0) {
    for (piVar2 = *(int **)(param_1 + 4); piVar2 != *(int **)(param_1 + 8); piVar2 = piVar2 + 1) {
      if (*(int *)(*piVar2 + 0x28) == param_2) {
        return *piVar2;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

