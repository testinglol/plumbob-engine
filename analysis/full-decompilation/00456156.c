
void __fastcall FUN_00456156(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      *(undefined2 *)(*(int *)(param_1 + 8) + iVar1 * 2) = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return;
}

