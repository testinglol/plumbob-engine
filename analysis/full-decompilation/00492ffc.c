
void __fastcall FUN_00492ffc(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0xc); iVar1 != *(int *)(param_1 + 0x10); iVar1 = iVar1 + 4) {
    FUN_00485b4c();
  }
  FUN_0052ea87(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  for (iVar1 = *(int *)(param_1 + 0x18); iVar1 != *(int *)(param_1 + 0x1c); iVar1 = iVar1 + 4) {
    FUN_00485b4c();
  }
  FUN_0052ea87(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
  return;
}

