
void __thiscall FUN_005e4a3a(int param_1,char param_2)

{
  *(char *)(param_1 + 0x16d) = param_2;
  if (param_2 == '\0') {
    if (*(undefined4 **)(param_1 + 0xd4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0xd4))(1);
    }
    *(undefined4 *)(param_1 + 0xd4) = 0;
  }
  return;
}

