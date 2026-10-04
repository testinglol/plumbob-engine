
undefined4 __fastcall FUN_005deb54(int param_1)

{
  if (*(int **)(param_1 + 0x48) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x48) + 4))();
    if (*(undefined4 **)(param_1 + 0x48) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x48))(1);
    }
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  if (*(undefined4 **)(param_1 + 0x4c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x4c))(1);
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  if (*(int *)(param_1 + 0x5c) != 0) {
    FUN_005e3581();
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  if (*(int *)(param_1 + 0x60) != 0) {
    FUN_005e3581();
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  return 1;
}

