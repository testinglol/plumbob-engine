
void __fastcall FUN_00599556(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2;
  if (0 < iVar3) {
    do {
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      if (*(int *)(iVar1 + *(int *)(param_1 + 100)) != 0) {
        FUN_0059958f();
      }
    } while (iVar2 < iVar3);
  }
  *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;
  return;
}

