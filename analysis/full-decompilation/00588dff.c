
undefined4 __thiscall FUN_00588dff(int *param_1,int param_2)

{
  param_1[0x4e] = param_2;
  param_1[1] = param_2;
  param_1[0x61] = param_2 + 0xae0;
  (**(code **)(*param_1 + 0x14))();
  (**(code **)(*param_1 + 4))();
  return 1;
}

