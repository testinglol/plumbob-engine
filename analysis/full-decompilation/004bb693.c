
void __thiscall
FUN_004bb693(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  param_1[1] = param_3;
  *param_1 = 0;
  param_1[2] = param_4;
  param_1[7] = param_2;
  param_1[5] = param_5;
  param_1[3] = param_6;
  param_1[4] = 1 << ((byte)param_6 & 0x1f);
  return;
}

