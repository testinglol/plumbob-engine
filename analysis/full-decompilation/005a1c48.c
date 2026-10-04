
undefined4 __thiscall FUN_005a1c48(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_2 * 4 + *(int *)(param_1 + 0xec));
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0xec));
}

