
undefined4 __thiscall FUN_005dffdc(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  DAT_006fe8fc = param_4;
  DAT_006fe900 = (uint)*(ushort *)(param_1[0xd] + (param_1[0xe] * param_3 + param_2) * 2);
  DAT_006fe904 = (**(code **)(*param_1 + 0xd0))();
  iVar1 = (**(code **)(*param_1 + 0xcc))();
  FUN_005dff89(iVar1 + (((uint)(DAT_006fe904 * param_3) >> 1) + param_2) * 2);
  return 1;
}

