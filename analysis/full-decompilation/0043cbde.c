
undefined4 __fastcall FUN_0043cbde(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = (*(int **)(param_1 + 0x1c))[1] - **(int **)(param_1 + 0x1c) >> 3;
  if (0 < iVar2) {
    do {
      if (*(int *)(**(int **)(param_1 + 0x1c) + iVar1 * 8) != 0) {
        FUN_004c725d();
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  return 1;
}

