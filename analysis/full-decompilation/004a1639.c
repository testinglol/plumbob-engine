
void __fastcall FUN_004a1639(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 3 != 0) {
    do {
      FUN_004c7318();
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 3));
  }
  return;
}

