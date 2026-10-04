
void __thiscall FUN_005e433f(int *param_1,int param_2)

{
  if (param_1[0x3a] != param_2) {
    (**(code **)(*param_1 + 0x168))();
  }
  param_1[0x3a] = param_2;
  return;
}

