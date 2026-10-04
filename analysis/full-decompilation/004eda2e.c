
undefined4 __fastcall FUN_004eda2e(int param_1)

{
  if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4) & 0xfffffffcU) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0x10) * 4) + 0x1c);
}

