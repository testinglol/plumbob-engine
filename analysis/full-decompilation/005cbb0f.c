
undefined4 FUN_005cbb0f(int param_1)

{
  if (((((*(byte *)(param_1 + 4) & 0x40) != 0) && (*(int *)(param_1 + 0x1c) == -0x40000000)) &&
      (*(int *)(param_1 + 0x10) == 0x3ff00000)) &&
     ((*(int *)(param_1 + 0x14) == 0xffc00 && (*(int *)(param_1 + 0x18) == 0x3ff)))) {
    return 1;
  }
  return 0;
}

