
void __fastcall FUN_00467999(int param_1)

{
  int *piVar1;
  
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined1 *)(param_1 + 0x71) = 0;
  *(undefined1 *)(param_1 + 0x72) = 0;
  *(undefined4 *)(param_1 + 0x280) = 0;
  *(undefined4 *)(param_1 + 0x284) = 0;
  FUN_00468acc(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c));
  piVar1 = *(int **)(param_1 + 0x10);
  *(undefined1 *)(param_1 + 0x74) = 0;
  *(undefined1 *)(param_1 + 0x75) = 0;
  *(undefined1 *)(param_1 + 0x76) = 1;
  *(undefined1 *)(param_1 + 0x77) = 0;
  *(undefined1 *)(param_1 + 0x70) = 1;
  for (; piVar1 != *(int **)(param_1 + 0x14); piVar1 = piVar1 + 1) {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 4))();
    }
  }
  FUN_0042ed71(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
  FUN_00468be1(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20));
  return;
}

