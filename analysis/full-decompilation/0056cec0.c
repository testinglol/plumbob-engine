
void __fastcall FUN_0056cec0(int param_1)

{
  *(undefined4 *)(param_1 + 0x194) = 0xffffffff;
  if (*(undefined4 **)(param_1 + 0x1dc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x1dc))(1);
  }
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  FUN_005dbf4d();
  return;
}

