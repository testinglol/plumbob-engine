
void __thiscall FUN_00410917(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 300);
  while( true ) {
    if (piVar1 == *(int **)(param_1 + 0x130)) {
      return;
    }
    if (*piVar1 == param_2) break;
    piVar1 = piVar1 + 1;
  }
  FUN_0042ec52(piVar1);
  return;
}

