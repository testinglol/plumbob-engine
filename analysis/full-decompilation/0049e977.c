
void __thiscall FUN_0049e977(uint *param_1,uint param_2,uint param_3)

{
  *param_1 = param_2 >> 0x10 & 0xff;
  param_1[2] = param_2 & 0xff;
  param_1[1] = param_2 >> 8 & 0xff;
  param_1[3] = param_3 >> 0x10 & 0xff;
  param_1[4] = param_3 >> 8 & 0xff;
  param_1[5] = param_3 & 0xff;
  return;
}

