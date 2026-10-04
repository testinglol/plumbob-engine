
void FUN_0043ddf8(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = (int *)(param_1 + 0xa0);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      FUN_0043e0d0(param_1);
    }
  }
  return;
}

