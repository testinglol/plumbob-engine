
void __thiscall FUN_005e4320(int *param_1,int param_2)

{
  if (param_1[0x39] != param_2) {
    (**(code **)(*param_1 + 0x168))();
  }
  param_1[0x39] = param_2;
  return;
}

