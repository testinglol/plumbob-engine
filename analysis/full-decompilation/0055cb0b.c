
void __thiscall FUN_0055cb0b(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x148);
  iVar2 = *(int *)(iVar1 + 8);
  if (param_2 == 0) {
    while (iVar2 != iVar1) {
      FUN_0054f484(0);
      FUN_0041674f();
      iVar1 = *(int *)(param_1 + 0x148);
    }
  }
  else {
    while (iVar2 != iVar1) {
      if (*(int *)(*(int *)(iVar2 + 0x14) + 0x1d8) == param_2) {
        if (*(int *)(iVar2 + 0x14) == 0) {
          return;
        }
        if (*(char *)(param_1 + 0x121) == '\0') {
          FUN_0054f7ae(1);
          return;
        }
        FUN_0054f484(1);
        return;
      }
      FUN_0041674f();
      iVar1 = *(int *)(param_1 + 0x148);
    }
  }
  return;
}

