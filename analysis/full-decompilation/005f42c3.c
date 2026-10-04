
void __thiscall FUN_005f42c3(int *param_1,int *param_2)

{
  int iVar1;
  
  param_1[0x45] = (int)param_2;
  if (((param_1[0x22] == param_1[0x20]) || (param_1[0x4c] < 1)) || (param_2 == (int *)0x0)) {
    param_1[0x41] = 0;
  }
  else {
    iVar1 = (**(code **)(*param_2 + 0x58))();
    param_1[0x41] = ((param_1[0x22] - iVar1 * param_1[0x4c]) - param_1[0x20]) / 2;
  }
  FUN_005f3a06(0);
  (**(code **)(*param_1 + 0x168))();
  return;
}

