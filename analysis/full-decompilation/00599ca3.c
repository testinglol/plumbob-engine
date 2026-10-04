
void __fastcall FUN_00599ca3(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 2;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    if (*(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4) != 0) {
      FUN_00595e86();
    }
  }
  FUN_0052ea87(*(int *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
  return;
}

