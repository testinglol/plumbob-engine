
int __thiscall FUN_00425ddf(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x154);
  if (param_2 == 0) {
    for (; piVar1 != *(int **)(param_1 + 0x158); piVar1 = piVar1 + 1) {
      if (*(int *)(*piVar1 + 0x10c) == 0) {
LAB_00425e23:
        return *piVar1;
      }
    }
  }
  else {
    for (; piVar1 != *(int **)(param_1 + 0x158); piVar1 = piVar1 + 1) {
      if ((*(int *)(*piVar1 + 0x110) == param_2) || (*(int *)(*piVar1 + 0x13c) == param_2))
      goto LAB_00425e23;
    }
  }
  return 0;
}

