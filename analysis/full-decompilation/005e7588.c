
void __thiscall FUN_005e7588(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uStack_10;
  undefined4 local_c;
  
  if (param_2 != '\0') {
    iVar1 = *(int *)(param_1 + 4);
    iVar2 = *(int *)(iVar1 + 8);
    while (iVar2 != iVar1) {
      puVar3 = *(undefined4 **)(iVar2 + 0x14);
      if (puVar3 != (undefined4 *)0x0) {
        local_c = 1;
        uStack_10 = 0x5e75b0;
        (**(code **)*puVar3)();
      }
      local_c = 0x5e75b8;
      FUN_0041674f();
      iVar1 = *(int *)(param_1 + 4);
    }
  }
  uStack_10 = *(undefined4 *)(param_1 + 4);
  local_c = uStack_10;
  FUN_005e8037(&uStack_10);
  FUN_005e75e0();
  return;
}

