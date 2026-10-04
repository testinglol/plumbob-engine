
undefined4 FUN_005cb9ac(int param_1)

{
  if (((((*(byte *)(param_1 + 4) & 0x40) != 0) && (*(int *)(param_1 + 0x1c) == -0x1000000)) &&
      (*(int *)(param_1 + 0x10) == 0xff0000)) &&
     ((*(int *)(param_1 + 0x14) == 0xff00 && (*(int *)(param_1 + 0x18) == 0xff)))) {
    return 1;
  }
  return 0;
}

