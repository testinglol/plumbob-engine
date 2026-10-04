
void __thiscall FUN_005f98d6(int param_1,uint param_2)

{
  if (param_2 == 0) {
    param_2 = 1;
  }
  if (6 < param_2) {
    param_2 = 6;
  }
  *(uint *)(param_1 + 0xc4) = param_2;
  return;
}

