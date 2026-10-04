
undefined4 * __thiscall FUN_005cb5eb(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_00673470;
  piVar1 = *(int **)(param_2 + 4);
  param_1[1] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return param_1;
}

