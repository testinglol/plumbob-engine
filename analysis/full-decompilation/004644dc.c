
void __thiscall
FUN_004644dc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[3] = param_4;
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 4) = param_5;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  *(undefined1 *)((int)param_1 + 0x13) = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  return;
}

