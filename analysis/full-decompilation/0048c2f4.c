
int FUN_0048c2f4(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_006e5790;
  if (param_1 != 0) {
    for (; piVar1 != DAT_006e5794; piVar1 = piVar1 + 1) {
      if (*(int *)(*piVar1 + 8) == param_1) {
        return *piVar1;
      }
    }
  }
  return 0;
}

