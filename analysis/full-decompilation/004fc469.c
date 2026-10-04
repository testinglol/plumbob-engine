
void __fastcall FUN_004fc469(int param_1)

{
  if (*(int *)(param_1 + 0x7c) != 0) {
    FUN_005da4c7(*(int *)(param_1 + 0x7c));
    *(undefined4 *)(param_1 + 0x7c) = 0;
    if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
      *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 0;
    }
  }
  if (*(int *)(param_1 + 0x78) != 0) {
    FUN_005e3581();
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  return;
}

