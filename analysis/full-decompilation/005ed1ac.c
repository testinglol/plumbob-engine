
undefined1 __fastcall FUN_005ed1ac(int param_1)

{
  if (*(char *)(param_1 + 0x10) != '\0') {
    *(undefined1 *)(param_1 + 0x10) = 0;
    CloseHandle(*(HANDLE *)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
    return 1;
  }
  return 0;
}

