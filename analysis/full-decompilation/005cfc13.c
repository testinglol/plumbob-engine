
undefined4 __fastcall FUN_005cfc13(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  for (piVar2 = *(int **)(param_1 + 0x28); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 4))();
    }
  }
  piVar1 = *(int **)(param_1 + 0x20);
  for (piVar2 = *(int **)(param_1 + 0x1c); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      FUN_005cfd0a(*piVar2);
    }
  }
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  return 0;
}

