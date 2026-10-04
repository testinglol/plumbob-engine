
void __thiscall FUN_005c171f(uint *param_1,uint param_2)

{
  if (param_2 < 0x100) {
    param_2 = param_2 << 0x18;
  }
  else if (param_2 < 0x10000) {
    param_2 = param_2 << 0x10;
  }
  else if (param_2 < 0x1000000) {
    param_2 = param_2 << 8;
  }
  *param_1 = param_2;
  return;
}

