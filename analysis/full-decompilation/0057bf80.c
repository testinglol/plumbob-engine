
undefined4 __thiscall FUN_0057bf80(float *param_1,int param_2,int param_3,int param_4)

{
  *param_1 = (float)param_2;
  param_1[1] = (float)param_3;
  param_1[2] = (float)param_4;
  (**(code **)(*(int *)param_1[8] + 0x14))((float)param_2,(float)param_3,(float)param_4);
  return 1;
}

