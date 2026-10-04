
void __fastcall FUN_005f090f(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)*param_1;
  if (piVar2 != (int *)*param_1) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_005eed47();
      FUN_0040189d(piVar2,0x40);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  *(int *)*param_1 = *param_1;
  *(int *)(*param_1 + 4) = *param_1;
  return;
}

