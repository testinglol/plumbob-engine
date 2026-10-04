
int __thiscall FUN_005946e8(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3;
  if (0 < iVar1) {
    piVar2 = *(int **)(param_1 + 4);
    do {
      if (param_2 <= *piVar2) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar3 < iVar1);
  }
  return iVar1;
}

