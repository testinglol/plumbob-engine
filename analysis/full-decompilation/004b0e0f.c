
void FUN_004b0e0f(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(*(int *)(*DAT_006e486c + 0x14) + 0x1c);
  for (piVar2 = *(int **)(*(int *)(*DAT_006e486c + 0x14) + 0x18);
      (piVar2 != piVar1 && (*piVar2 != 0)); piVar2 = piVar2 + 1) {
    FUN_0043908c(param_1);
  }
  return;
}

