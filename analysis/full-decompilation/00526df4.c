
int __fastcall FUN_00526df4(int param_1)

{
  if ((*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x104) == 0x2d) &&
     (*(int *)(param_1 + 0x110) - *(int *)(param_1 + 0x108) == 0x2d)) {
    return *(int *)(*(int *)(param_1 + 0x118) + 0x1c);
  }
  return *(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x104);
}

