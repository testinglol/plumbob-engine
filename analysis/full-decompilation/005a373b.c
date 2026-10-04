
void __fastcall FUN_005a373b(int param_1)

{
  if ((*(char *)(param_1 + 0x2c) != '\0') && (*(int *)(param_1 + 0x30) != 0)) {
    FUN_0042004f();
    FUN_00598d92();
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined1 *)(param_1 + 0x2c) = 0;
  }
  return;
}

