
int __thiscall FUN_00465062(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  while( true ) {
    if (piVar1 == (int *)param_1[1]) {
      return 0;
    }
    if (*(int *)(*piVar1 + 0xc) == param_2) break;
    piVar1 = piVar1 + 1;
  }
  if (piVar1 == (int *)param_1[1]) {
    return 0;
  }
  return ((int *)*piVar1)[1] - *(int *)*piVar1 >> 2;
}

