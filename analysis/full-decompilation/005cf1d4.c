
void __thiscall FUN_005cf1d4(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x98) = *param_2;
  *(undefined4 *)(param_1 + 0x9c) = param_2[1];
  *(undefined4 *)(param_1 + 0xa0) = param_2[2];
  *(undefined4 *)(param_1 + 0xa4) = param_2[3];
  if (*(char *)(param_1 + 0x66) == '\x01') {
    FUN_005cddcf((undefined4 *)(param_1 + 0x98));
  }
  return;
}

