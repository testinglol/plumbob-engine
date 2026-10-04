
void __thiscall FUN_0049e0f1(int *param_1,int param_2)

{
  param_1[0x1f] = param_1[0x1f] + param_2;
  if (param_1[0x1f] < 2) {
    param_1[0x1f] = 2;
  }
  (**(code **)(*param_1 + 8))();
  (**(code **)(*param_1 + 4))();
  (**(code **)(*param_1 + 0xc))();
  return;
}

