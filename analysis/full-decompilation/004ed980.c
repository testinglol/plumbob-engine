
void __thiscall FUN_004ed980(int param_1,int param_2)

{
  int *piVar1;
  
  if (((*(int *)(param_1 + 8) - *(int *)(param_1 + 4) & 0xfffffffcU) != 0) && (param_2 != 0)) {
    FUN_005d4bbf(param_2);
    piVar1 = *(int **)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0x10) * 4);
    if (*piVar1 != 4) {
      *piVar1 = 3;
    }
  }
  return;
}

