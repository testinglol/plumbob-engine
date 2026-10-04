
undefined4 FUN_005cba91(int param_1)

{
  if (((((*(byte *)(param_1 + 4) & 0x40) != 0) && (*(int *)(param_1 + 0x1c) == 0)) &&
      (*(int *)(param_1 + 0x10) == 0x7c00)) &&
     ((*(int *)(param_1 + 0x14) == 0x3e0 && (*(int *)(param_1 + 0x18) == 0x1f)))) {
    return 1;
  }
  return 0;
}

