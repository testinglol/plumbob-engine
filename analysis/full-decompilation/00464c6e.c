
void __fastcall FUN_00464c6e(int param_1)

{
  if (*(char *)(param_1 + 0x13) != '\0') {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x24);
  }
  return;
}

