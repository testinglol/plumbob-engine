
void FUN_004df937(void)

{
  if (DAT_006f21fd == '\x01') {
    DAT_006f21fd = '\0';
  }
  if (DAT_006c8c94 != (HANDLE)0xffffffff) {
    CloseHandle(DAT_006c8c94);
    DAT_006c8c94 = (HANDLE)0xffffffff;
  }
  if (DAT_006c8c98 != (HANDLE)0xffffffff) {
    CloseHandle(DAT_006c8c98);
    DAT_006c8c98 = (HANDLE)0xffffffff;
  }
  if (DAT_006c8c9c != -1) {
    FUN_004e0167(DAT_006c8c9c);
    DAT_006c8c9c = -1;
  }
  if (DAT_006f2204 != 0) {
    FUN_0063558d(DAT_006f2204);
    DAT_006f2204 = 0;
  }
  return;
}

