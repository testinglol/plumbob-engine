
void __thiscall FUN_00463155(int param_1,short param_2,undefined4 param_3)

{
  while ((uint)(*(int *)(param_1 + 0x1b0) - *(int *)(param_1 + 0x1ac) >> 2) < (uint)(int)param_2) {
    FUN_00464260(&DAT_00667478);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x1ac) + -4 + param_2 * 4) = param_3;
  if (DAT_006e5282 == param_2) {
    FUN_004341a6(0);
  }
  return;
}

