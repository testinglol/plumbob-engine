
undefined4 __fastcall FUN_005e79c5(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iStack_20;
  int local_1c;
  
  if (*(char *)(param_1 + 4) != '\0') {
    iStack_20 = *(int *)(param_1 + 0x10);
    local_1c = iStack_20;
    FUN_005e8037(&iStack_20);
    FUN_005e7f83();
    iVar1 = *(int *)(param_1 + 0x1c);
    iVar2 = *(int *)(iVar1 + 8);
    while (iVar2 != iVar1) {
      local_1c = *(undefined4 *)(iVar2 + 0x14);
      iStack_20 = 0x5e7a0f;
      (**(code **)(**(int **)(param_1 + 8) + 0x14))();
      local_1c = 0x5e7a17;
      FUN_0041674f();
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    iStack_20 = *(int *)(param_1 + 0x1c);
    local_1c = iStack_20;
    FUN_005e8037(&iStack_20);
    FUN_005e7fdd();
    iVar1 = *(int *)(param_1 + 0x28);
    iVar2 = *(int *)(iVar1 + 8);
    while (iVar2 != iVar1) {
      puVar3 = *(undefined4 **)(iVar2 + 0x14);
      if (puVar3 != (undefined4 *)0x0) {
        local_1c = 1;
        iStack_20 = 0x5e7a52;
        (**(code **)*puVar3)();
      }
      local_1c = 0x5e7a5a;
      FUN_0041674f();
      iVar1 = *(int *)(param_1 + 0x28);
    }
    iStack_20 = *(int *)(param_1 + 0x28);
    local_1c = iStack_20;
    FUN_005e8037(&iStack_20);
    FUN_005e80a3();
    iVar1 = *(int *)(param_1 + 0x34);
    iVar2 = *(int *)(iVar1 + 8);
    while (iVar2 != iVar1) {
      local_1c = 1;
      iStack_20 = *(int *)(iVar2 + 0x14);
      (**(code **)(**(int **)(param_1 + 0xc) + 0x34))();
      local_1c = 0x5e7a9d;
      FUN_0041674f();
      iVar1 = *(int *)(param_1 + 0x34);
    }
    iStack_20 = *(int *)(param_1 + 0x34);
    local_1c = iStack_20;
    FUN_005e8037(&iStack_20);
    FUN_005e7f83();
    *(undefined1 *)(param_1 + 4) = 0;
  }
  return 1;
}

