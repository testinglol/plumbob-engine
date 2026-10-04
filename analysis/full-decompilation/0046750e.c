
void __fastcall FUN_0046750e(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    if (*(int *)(*(int *)(iVar2 + 0x14) + 0x34) != 0) {
      FUN_00468843();
    }
    FUN_0041674f();
    iVar1 = *(int *)(param_1 + 4);
  }
  return;
}

