
undefined4 __thiscall
FUN_00512b54(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1[0x48] != 0) {
    (**(code **)(*param_1 + 0xfc))(param_2,param_3,param_4);
    FUN_005d9912(param_1);
    param_1[0x48] = 0;
  }
  return 1;
}

