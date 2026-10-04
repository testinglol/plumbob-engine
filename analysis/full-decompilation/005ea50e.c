
void __thiscall FUN_005ea50e(int param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xec);
  if (puVar1 != (undefined4 *)0x0) {
    if (*(char *)(param_1 + 0xf0) == '\0') {
      FUN_005e3581();
    }
    else if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    *(undefined4 *)(param_1 + 0xec) = 0;
  }
  *(undefined4 *)(param_1 + 0xec) = param_2;
  FUN_005e357a();
  *(undefined1 *)(param_1 + 0xf0) = param_3;
  return;
}

