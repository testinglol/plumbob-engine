
void __thiscall FUN_00489ca6(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_00489d1a(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_00489f40();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x3c;
  }
  return;
}

