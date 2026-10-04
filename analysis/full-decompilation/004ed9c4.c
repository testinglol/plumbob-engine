
undefined4 __fastcall FUN_004ed9c4(int param_1)

{
  if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4) & 0xfffffffcU) == 0) {
    return 0;
  }
  if (**(int **)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0x10) * 4) == 2) {
    FUN_004ed482();
  }
  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0x10) * 4) + 4);
}

