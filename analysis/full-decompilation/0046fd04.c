
void __thiscall FUN_0046fd04(int param_1,undefined4 param_2,undefined2 param_3)

{
  *(undefined1 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0x58) = 0x53545223;
  *(undefined2 *)(param_1 + 0x54) = param_3;
  if (*(char *)(param_1 + 0x5d) < '\0') {
    *(char *)(param_1 + 0x5d) = *(char *)(DAT_006e486c + 100) + -1;
  }
  FUN_0046fd72();
  return;
}

