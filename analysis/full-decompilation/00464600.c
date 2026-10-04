
void __thiscall
FUN_00464600(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  *param_1 = param_2;
  param_1[2] = param_3;
  param_1[1] = -1 << ((char)param_2 - 1U & 0x1f);
  param_1[4] = param_4;
  param_1[6] = param_5;
  param_1[3] = -1 << ((char)param_3 - 1U & 0x1f);
  param_1[5] = -1 << ((char)param_4 - 1U & 0x1f);
  param_1[7] = -1 << ((char)param_5 - 1U & 0x1f);
  return;
}

