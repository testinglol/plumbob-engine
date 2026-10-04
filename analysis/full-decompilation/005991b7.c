
void __thiscall FUN_005991b7(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = *(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x7c) >> 2;
  if (0 < iVar2) {
    piVar1 = *(int **)(param_1 + 0x7c);
    piVar3 = piVar1;
    do {
      if (*piVar3 == param_2) {
        *(undefined4 *)(param_1 + 0x94) = 1;
        FUN_005db2f2(piVar1 + iVar4);
        if (param_2 == 0) {
          return;
        }
        FUN_00597a0d();
        FUN_006321f0(param_2);
        return;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < iVar2);
  }
  return;
}

