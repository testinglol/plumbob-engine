
void __thiscall FUN_005f398c(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  if ((param_1[0x3d] - param_1[0x3c] >> 2 != 0) && (param_1[0x3d] - param_1[0x3c] >> 2 <= param_2))
  {
    param_2 = (param_1[0x3d] - param_1[0x3c] >> 2) + -1;
  }
  iVar1 = (**(code **)(*(int *)param_1[0x45] + 0x58))();
  param_1[0x4b] = param_2;
  param_1[0x40] = param_1[0x41] - iVar1 * param_2;
  FUN_005f4008();
  (**(code **)(*param_1 + 0x168))();
  return;
}

