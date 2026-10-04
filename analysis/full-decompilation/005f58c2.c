
void __thiscall FUN_005f58c2(int *param_1,int *param_2)

{
  int iVar1;
  
  param_1[0x45] = (int)param_2;
  iVar1 = (**(code **)(*param_2 + 0x58))();
  param_1[0x3c] = iVar1 + 3;
  (**(code **)(*param_1 + 0x168))();
  return;
}

