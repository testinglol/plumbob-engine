
undefined4 __thiscall FUN_005dc6f2(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int local_8;
  
  uVar2 = 0;
  local_8 = 0;
  FUN_00576b0a(**(undefined4 **)(param_1 + 0x38),*(undefined4 **)(param_1 + 0x38),&local_8);
  if (local_8 != 0) {
    if (*(char *)(param_1 + 0x3c) == '\0') {
      *(undefined1 *)(param_1 + 0x3c) = 1;
    }
    for (puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x38);
        puVar1 != *(undefined4 **)(param_1 + 0x38); puVar1 = (undefined4 *)*puVar1) {
      if (*(int *)(puVar1[2] + 8) == param_2) {
        uVar2 = puVar1[2];
        break;
      }
    }
    *(undefined1 *)(param_1 + 0x3c) = 0;
  }
  return uVar2;
}

