
void __thiscall FUN_004c946e(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_004c9668(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_0041e98b();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 8;
  }
  return;
}

