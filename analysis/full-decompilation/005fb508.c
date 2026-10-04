
undefined4 __fastcall FUN_005fb508(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  return 1;
}

