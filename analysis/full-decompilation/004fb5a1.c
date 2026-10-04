
undefined4 FUN_004fb5a1(int *param_1)

{
  if (DAT_006c9f58 != '\0') {
    CoInitialize((LPVOID)0x0);
  }
  (**(code **)(*param_1 + 0x2c))();
  *(undefined1 *)(param_1 + 0x43) = 1;
  if (DAT_006c9f58 == '\0') {
    FUN_004fb1a5();
  }
  else {
    FUN_00637ec4(0);
  }
  return 0;
}

