
void __fastcall FUN_0042528e(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  piVar1 = *(int **)(param_1 + 0x14c);
  for (piVar2 = *(int **)(param_1 + 0x148); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      *(undefined2 *)(*piVar2 + 0xee) = 0;
    }
  }
  piVar2 = *(int **)(param_1 + 0x154);
  if (piVar2 != *(int **)(param_1 + 0x158)) {
    do {
      iVar5 = 0;
      iVar3 = FUN_004102e1();
      if (0 < iVar3) {
        do {
          puVar4 = (undefined4 *)FUN_004102ab(iVar5);
          iVar3 = FUN_00425769(*puVar4);
          if (iVar3 != 0) {
            *(short *)(iVar3 + 0xee) = (short)*(undefined4 *)(*piVar2 + 0x10c);
          }
          iVar5 = iVar5 + 1;
          iVar3 = FUN_004102e1();
        } while (iVar5 < iVar3);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != *(int **)(param_1 + 0x158));
  }
  return;
}

