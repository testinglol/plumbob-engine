
void __thiscall FUN_004ed831(int param_1,int param_2)

{
  if ((param_2 < 0) || ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4) & 0xfffffffcU) == 0)) {
    param_2 = 0;
  }
  else if (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2 <= param_2) {
    param_2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2) + -1;
  }
  *(int *)(param_1 + 0x10) = param_2;
  return;
}

