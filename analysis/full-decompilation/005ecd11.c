
void __thiscall FUN_005ecd11(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x104))();
  iVar2 = (**(code **)(*param_1 + 0x108))();
  if (*param_2 < 0) {
    *param_2 = 0;
  }
  else if (iVar1 < *param_2) {
    *param_2 = iVar1;
  }
  if (param_2[1] < 0) {
    param_2[1] = 0;
  }
  else if (iVar2 < param_2[1]) {
    param_2[1] = iVar2;
  }
  return;
}

