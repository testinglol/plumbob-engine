
void __thiscall FUN_004b0367(int param_1,int param_2,undefined4 param_3)

{
  FUN_004b038a(*(undefined4 *)(param_1 + 0x70 + param_2 * 4),param_3);
  if (*(char *)(param_1 + 0x78) != '\0') {
    *(int *)(param_1 + 0x7c) = param_2;
  }
  return;
}

