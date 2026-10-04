
undefined4 __thiscall FUN_005e923f(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  if (((puVar1 != (undefined4 *)0x0) && (*(char *)(param_1 + 0x14) != '\0')) &&
     (puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined1 *)(param_1 + 0x14) = 1;
  return 1;
}

