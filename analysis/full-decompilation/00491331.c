
void __fastcall FUN_00491331(int param_1)

{
  if (*(char *)(param_1 + 0x2c) == '\0') {
    if (*(int *)(param_1 + 0x44) != 0) {
      if (*(int *)(param_1 + 0x30) != 0) {
        FUN_004924ae(*(int *)(param_1 + 0x30));
        FUN_0049341e(*(undefined4 *)(param_1 + 0x44));
      }
      FUN_00485b4c();
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    *(undefined1 *)(param_1 + 0x2c) = 1;
  }
  return;
}

