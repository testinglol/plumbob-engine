
void __fastcall FUN_00466cd9(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    iVar1 = *(int *)(iVar2 + 0x14);
    if (*(int *)(iVar1 + 0x34) != 0) {
      *(undefined1 *)(iVar1 + 0x70) = 1;
    }
    FUN_0041674f();
    iVar1 = *(int *)(param_1 + 4);
  }
  *(undefined4 *)(param_1 + 0x34) = 3;
  return;
}

