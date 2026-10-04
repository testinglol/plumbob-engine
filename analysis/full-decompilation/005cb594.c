
undefined4 * __thiscall FUN_005cb594(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_0067347c;
  piVar1 = *(int **)(param_2 + 4);
  param_1[1] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return param_1;
}

