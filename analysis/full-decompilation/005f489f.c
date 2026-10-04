
void __thiscall FUN_005f489f(int param_1,char param_2)

{
  if (*(char *)(param_1 + 0x196) != '\0') {
    if (param_2 == '\0') {
      if (*(undefined4 **)(param_1 + 0x198) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x198))(1);
      }
      *(undefined4 *)(param_1 + 0x198) = 0;
      *(undefined1 *)(param_1 + 0x196) = 0;
      return;
    }
    if (*(char *)(param_1 + 0x196) != '\0') {
      return;
    }
  }
  if (param_2 != '\0') {
    *(undefined1 *)(param_1 + 0x196) = 1;
  }
  return;
}

