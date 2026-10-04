
void FUN_0043e0d0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x68);
  iVar1 = 5;
  do {
    if (*piVar2 != 0) {
      FUN_00456c3e(*piVar2);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = *(int *)(param_1 + 0x90);
  if (iVar1 != 0) {
    FUN_005481b6();
    FUN_006321f0(iVar1);
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  FUN_004c7318();
  if ((*(byte *)(param_1 + 0xb4) & 1) != 0) {
    for (piVar2 = *(int **)(param_1 + 0x94); piVar2 != *(int **)(param_1 + 0x98);
        piVar2 = piVar2 + 1) {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        thunk_FUN_0043e4e8();
        FUN_006321f0(iVar1);
      }
    }
    FUN_0052ea87(*(undefined4 *)(param_1 + 0x94),*(undefined4 *)(param_1 + 0x98));
    *(uint *)(param_1 + 0xb4) = *(uint *)(param_1 + 0xb4) & 0xfffffffe;
  }
  return;
}

