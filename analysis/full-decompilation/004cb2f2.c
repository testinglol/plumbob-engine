
void __thiscall FUN_004cb2f2(int *param_1,int param_2,int param_3)

{
  *(undefined1 *)(param_1 + 0x3c) = 0;
  param_1[0x3e] = param_3;
  param_1[0x40] = param_3;
  param_1[0x3d] = param_2;
  param_1[0x3f] = param_2;
  *(undefined1 *)((int)param_1 + 0x105) = 1;
  FUN_004cb21d(param_2,param_3);
  (**(code **)(*param_1 + 0x90))(0x400,1);
  return;
}

