
void FUN_00626060(int *param_1)

{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    if (piVar1 != param_1 + 3) {
      if (param_1[1] != 0) {
        FUN_005a9340(param_1[1]);
      }
      if (piVar1 != (int *)0x0) {
        FUN_005a9340(piVar1);
      }
    }
    FUN_005a9340(param_1);
  }
  return;
}

