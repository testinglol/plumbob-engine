
undefined4 FUN_005cb8aa(int param_1)

{
  if (((((*(byte *)(param_1 + 4) & 0x40) != 0) && (*(int *)(param_1 + 0x1c) == 0xf000)) &&
      (*(int *)(param_1 + 0x10) == 0xf00)) &&
     ((*(int *)(param_1 + 0x14) == 0xf0 && (*(int *)(param_1 + 0x18) == 0xf)))) {
    return 1;
  }
  return 0;
}

