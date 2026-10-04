
void __thiscall FUN_00493bcf(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_00493c63(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_00493eac();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x34;
  }
  return;
}

