
undefined4 __fastcall FUN_005dc646(int param_1)

{
  if (*(char *)(param_1 + 0x3c) == '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 1;
  }
  FUN_005de7e8(&stack0x00000004);
  FUN_00601324(&stack0x00000004);
  *(undefined1 *)(param_1 + 0x3c) = 0;
  return 1;
}

