
void __thiscall FUN_00466617(int *param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 != 0) {
    for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
      if (*piVar1 == param_2) {
        return;
      }
    }
    piVar1 = operator_new(8);
    *piVar1 = param_2;
    piVar1[1] = *param_1;
    *(short *)(param_1 + 1) = (short)param_1[1] + 1;
    *param_1 = (int)piVar1;
  }
  return;
}

