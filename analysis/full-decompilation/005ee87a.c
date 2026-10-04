
void __thiscall
FUN_005ee87a(int param_1,int param_2,undefined4 *param_3,undefined4 param_4,int param_5)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xd8 + param_2 * 4);
  if (((puVar1 != (undefined4 *)0x0) && (puVar1 != param_3)) && (puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 **)(param_1 + 0xd8 + param_2 * 4) = param_3;
  *(undefined4 *)(param_1 + 0xe8 + param_2 * 4) = param_4;
  if (param_5 != 0) {
    FUN_005d4bbf(param_5);
  }
  return;
}

