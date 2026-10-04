
void __thiscall FUN_004c7109(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  while( true ) {
    if (piVar3 == (int *)param_1[1]) {
      return;
    }
    if (*piVar3 == param_2) break;
    piVar3 = piVar3 + 2;
  }
  if (piVar3 == (int *)param_1[1]) {
    return;
  }
  piVar1 = piVar3 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 != 0) {
    return;
  }
  iVar2 = *piVar3;
  if (iVar2 != 0) {
    FUN_004c7205();
    FUN_006321f0(iVar2);
  }
  FUN_004c9496(piVar3);
  return;
}

