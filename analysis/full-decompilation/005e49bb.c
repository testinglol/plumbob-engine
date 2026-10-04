
void __thiscall
FUN_005e49bb(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  FUN_005dd95d(param_2,param_3,param_4,param_5);
  if (param_5 == param_1) {
    (**(code **)(*param_1 + 0x108))();
  }
  else {
    (**(code **)(*param_1 + 0x10c))(param_2,param_3,param_1);
  }
  return;
}

