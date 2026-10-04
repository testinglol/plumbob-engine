
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0052d4b9(int param_1,undefined4 param_2)

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
  (**(code **)(**(int **)(*(int *)(param_1 + 0xf0) + 0x18) + 0x9c))
            (*(int *)(param_1 + 0x13c) + iVar2 * 0xc);
  _DAT_006f3c9c = *(undefined4 *)(&DAT_006f3c14 + iVar2 * 8);
  _DAT_006f3c98 = *(undefined4 *)(&DAT_006f3c10 + iVar2 * 8);
  return;
}

