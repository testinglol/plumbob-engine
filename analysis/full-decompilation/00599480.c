
void __thiscall FUN_00599480(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  iVar2 = *(int *)(param_1 + 0x8c) - *(int *)(param_1 + 0x88) >> 2;
  if (0 < iVar2) {
    piVar1 = *(int **)(param_1 + 0x88);
    piVar4 = piVar1;
    do {
      if (*piVar4 == param_2) {
        FUN_005db2f2(piVar1 + iVar3);
        FUN_00595626();
        *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
        *(undefined4 *)(param_1 + 0x98) = 1;
        return;
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}

