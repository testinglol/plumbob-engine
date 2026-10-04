
void __fastcall FUN_00588830(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x260) - *(int *)(param_1 + 0x25c) >> 2 != 0) {
    do {
      FUN_0058379c();
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(param_1 + 0x260) - *(int *)(param_1 + 0x25c) >> 2));
  }
  uVar1 = 0;
  if (*(int *)(param_1 + 0x26c) - *(int *)(param_1 + 0x268) >> 2 != 0) {
    do {
      FUN_0058379c();
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(param_1 + 0x26c) - *(int *)(param_1 + 0x268) >> 2));
  }
  uVar1 = 0;
  if (*(int *)(param_1 + 0x278) - *(int *)(param_1 + 0x274) >> 2 != 0) {
    do {
      FUN_0058379c();
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(param_1 + 0x278) - *(int *)(param_1 + 0x274) >> 2));
  }
  FUN_0058379c();
  if (*(int *)(param_1 + 0x250) != 0) {
    FUN_00599480(*(int *)(param_1 + 0x250));
    *(undefined4 *)(param_1 + 0x250) = 0;
    *(undefined4 *)(param_1 + 0x254) = 0;
  }
  return;
}

