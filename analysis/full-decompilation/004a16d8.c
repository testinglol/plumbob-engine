
void __thiscall FUN_004a16d8(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_004a191c(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_004a2717();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x11c;
  }
  return;
}

