
void __fastcall FUN_005caacc(int param_1)

{
  int *piVar1;
  
  (**(code **)(*(int *)(param_1 + 0x80) + 4))(0);
  (**(code **)(*(int *)(param_1 + 0x90) + 4))(0);
  (**(code **)(*(int *)(param_1 + 0x88) + 4))(0);
  (**(code **)(*(int *)(param_1 + 0x78) + 4))(0);
  (**(code **)(*(int *)(param_1 + 0xe8) + 4))(0);
  (**(code **)(*(int *)(param_1 + 0x100) + 4))(0);
  (**(code **)(*(int *)(param_1 + 0x10c) + 4))(0);
  piVar1 = *(int **)(param_1 + 0x98);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x9c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  return;
}

