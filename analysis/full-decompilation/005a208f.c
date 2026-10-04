
void __thiscall FUN_005a208f(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_00598d92();
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  *(undefined4 *)(param_1 + 0x30) = param_2;
  FUN_00599030(param_1 + 4);
  FUN_0042004f();
  *(undefined1 *)(param_1 + 0x2c) = 1;
  return;
}

