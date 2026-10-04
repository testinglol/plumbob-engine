
void __thiscall FUN_005ea559(int param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x104);
  if (((puVar1 != (undefined4 *)0x0) && (*(char *)(param_1 + 0x108) != '\0')) &&
     (puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 *)(param_1 + 0x104) = param_2;
  *(undefined1 *)(param_1 + 0x108) = param_3;
  return;
}

