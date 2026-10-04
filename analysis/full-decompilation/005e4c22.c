
void __fastcall FUN_005e4c22(int param_1)

{
  if (*(undefined4 **)(param_1 + 0xe0) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xe0))(1);
  }
  *(undefined4 *)(param_1 + 0xe0) = 0;
  FUN_005dbf4d();
  return;
}

