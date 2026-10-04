
undefined4 __fastcall FUN_005d474e(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x58) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  return 0;
}

