
void __thiscall FUN_0052d519(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = FUN_0040542d();
  if (iVar1 != 0) {
    iVar2 = FUN_004051c1(param_2);
    if (iVar2 < 0) {
      return;
    }
    if (10 < iVar2) {
      return;
    }
  }
  FUN_005d499c(*(int *)(param_1 + 0x148) + iVar2 * 0xc);
  FUN_005d499c(*(int *)(param_1 + 0x154) + iVar2 * 0xc);
  return;
}

