
void __fastcall FUN_00458449(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar1 = 0x3a;
    do {
      *(undefined2 *)(iVar1 + *(int *)(param_1 + 0x1c)) = *(undefined2 *)(param_1 + -0x30 + iVar1);
      iVar1 = iVar1 + 2;
    } while (iVar1 < 0x4a);
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}

