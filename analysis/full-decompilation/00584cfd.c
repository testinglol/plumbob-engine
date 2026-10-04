
void __fastcall FUN_00584cfd(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2 != 0) {
    do {
      FUN_0058379c();
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2));
  }
  uVar1 = 0;
  if (*(int *)(param_1 + 0xd0) - *(int *)(param_1 + 0xcc) >> 2 != 0) {
    do {
      FUN_0058379c();
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(param_1 + 0xd0) - *(int *)(param_1 + 0xcc) >> 2));
  }
  return;
}

