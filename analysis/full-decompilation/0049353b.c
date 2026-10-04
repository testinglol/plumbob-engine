
void __fastcall FUN_0049353b(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 4); piVar1 != *(int **)(param_1 + 8); piVar1 = piVar1 + 1) {
    if (*piVar1 != 0) {
      FUN_00485b4c();
      *piVar1 = 0;
    }
  }
  FUN_0052ea87(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}

