
void __fastcall FUN_004ce493(int param_1)

{
  if (*(undefined4 **)(param_1 + 0x58) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x58))(1);
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}

