
void __thiscall FUN_004cb341(int *param_1,int param_2,int param_3,int param_4)

{
  if (param_4 == 0) {
    param_4 = DAT_006c7824;
  }
  *(undefined1 *)(param_1 + 0x3c) = 1;
  param_1[0x3d] = param_1[0x1f];
  param_1[0x3e] = param_1[0x20];
  param_1[0x3f] = param_2;
  param_1[0x40] = param_3;
  *(undefined1 *)((int)param_1 + 0x105) = 1;
  FUN_004734bd(0,0x3f800000,param_4,DAT_006e5490);
  (**(code **)(*param_1 + 0x90))(0x400,0);
  param_1[0x29] = 0;
  return;
}

