
undefined4 __thiscall FUN_005d2835(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  for (piVar1 = (int *)*param_1; (piVar1 != (int *)param_1[1] && (*piVar1 != param_2));
      piVar1 = piVar1 + 1) {
  }
  if (piVar1 != (int *)param_1[1]) {
    FUN_005db2f2(piVar1);
  }
  return 0;
}

