
void __fastcall FUN_0047031c(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0x60); piVar1 != *(int **)(param_1 + 100); piVar1 = piVar1 + 1)
  {
    if (*piVar1 != 0) {
      FUN_006321f0(*piVar1);
    }
  }
  FUN_0047178d(*(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 100));
  return;
}

