
void __thiscall FUN_0040155d(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (param_2 != 0) {
    for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
      if (*piVar1 == param_2) {
        return;
      }
    }
    piVar2 = operator_new(8);
    piVar2[1] = 0;
    *piVar2 = param_2;
    piVar1 = param_1;
    for (iVar3 = *param_1; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
      piVar1 = (int *)(iVar3 + 4);
    }
    *piVar1 = (int)piVar2;
    *(short *)(param_1 + 1) = (short)param_1[1] + 1;
  }
  return;
}

