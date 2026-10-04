
void __thiscall FUN_004665e6(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  piVar2 = param_1;
  while( true ) {
    if (piVar3 == (int *)0x0) {
      return;
    }
    if (*piVar3 == param_2) break;
    piVar2 = piVar3 + 1;
    piVar3 = (int *)piVar3[1];
  }
  iVar1 = *piVar2;
  *piVar2 = *(int *)(iVar1 + 4);
  FUN_006321f0(iVar1);
  *(short *)(param_1 + 1) = (short)param_1[1] + -1;
  return;
}

