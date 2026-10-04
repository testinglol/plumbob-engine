
void __thiscall FUN_004619b0(undefined1 *param_1,undefined4 *param_2)

{
  *param_2 = param_1;
  *(undefined1 *)(param_2 + 1) = *param_1;
  *(undefined1 *)((int)param_2 + 5) = param_1[1];
  *(undefined1 *)((int)param_2 + 6) = param_1[2];
  return;
}

