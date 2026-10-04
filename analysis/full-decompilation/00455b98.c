
void __thiscall FUN_00455b98(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[1] = param_2;
  *param_1 = 0;
  param_1[2] = param_3;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 1;
  return;
}

