
void __thiscall FUN_005d78c0(int *param_1,int param_2)

{
  if (param_1[0x3b] != 0) {
    FUN_005da4c7(param_1[0x3b]);
  }
  param_1[0x3b] = param_2;
  if (param_2 != 0) {
    (**(code **)(*param_1 + 0x20))(param_2);
    (**(code **)(*(int *)param_1[0x3b] + 0x98))();
  }
  return;
}

