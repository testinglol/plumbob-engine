
int __thiscall FUN_004b8e26(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  while( true ) {
    if (piVar1 == (int *)param_1[1]) {
      return 0;
    }
    if (*piVar1 == param_2) break;
    piVar1 = piVar1 + 2;
  }
  if (piVar1 == (int *)param_1[1]) {
    return 0;
  }
  *(int *)(piVar1[1] + 0x14) = *(int *)(piVar1[1] + 0x14) + 1;
  return piVar1[1];
}

