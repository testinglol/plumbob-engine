
void __thiscall FUN_004e4153(int param_1,byte param_2)

{
  *(byte *)(param_1 + 7) = *(byte *)(param_1 + 7) & 0x7e;
  if ((param_2 & 2) != 0) {
    *(byte *)(param_1 + 7) = *(byte *)(param_1 + 7) | 0x80;
  }
  if ((param_2 & 1) != 0) {
    *(byte *)(param_1 + 7) = *(byte *)(param_1 + 7) | 1;
  }
  return;
}

