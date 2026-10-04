
void __fastcall FUN_0049356e(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0x10); piVar1 != *(int **)(param_1 + 0x14); piVar1 = piVar1 + 1)
  {
    if (*piVar1 != 0) {
      FUN_00485b4c();
      *piVar1 = 0;
    }
  }
  FUN_0052ea87(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
  return;
}

