
undefined4 __thiscall FUN_005dff0b(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  DAT_006fe8fc = param_4;
  DAT_006fe900 = (uint)*(ushort *)(param_1[0xd] + (param_1[0xe] * param_3 + param_2) * 2);
  DAT_006fe904 = (**(code **)(*param_1 + 0xd0))();
  DAT_006fe908 = (**(code **)(*param_1 + 0xcc))();
  DAT_006fe90c = DAT_006fe908 + ((param_1[8] + -1) * DAT_006fe904 + param_1[7]) * 2;
  DAT_006fe910 = param_1[7];
  FUN_005dff89(DAT_006fe908 + (((uint)(DAT_006fe904 * param_3) >> 1) + param_2) * 2);
  return 1;
}

