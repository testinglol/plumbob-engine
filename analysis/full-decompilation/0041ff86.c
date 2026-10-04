
void __thiscall FUN_0041ff86(uint *param_1,uint param_2)

{
  if (param_2 < 4) {
    param_2 = 4;
  }
  *param_1 = param_2;
  if (param_2 < 0x200) {
    param_2 = param_2 << 7;
  }
  else if (param_2 < 0x800) {
    param_2 = param_2 << 5;
  }
  else {
    param_2 = param_2 << 4;
  }
  param_1[1] = param_2;
  return;
}

