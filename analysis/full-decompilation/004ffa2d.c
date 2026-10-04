
void __thiscall FUN_004ffa2d(int *param_1,int *param_2)

{
  int iVar1;
  
  param_1[0x40] = 0;
  param_1[0x38] = *param_2;
  iVar1 = param_2[1];
  param_1[0x37] = iVar1;
  param_1[0x39] = param_1[0x3f] + iVar1;
  param_1[0x36] = param_1[0x38] - param_1[0x3e];
  (**(code **)(*param_1 + 0x60))(param_1[0x36],param_1[0x37],param_1[0x38],param_1[0x39]);
  return;
}

