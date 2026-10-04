
void __thiscall FUN_0058570d(int *param_1,int param_2)

{
  int iVar1;
  
  FUN_00462f2f(param_2);
  param_1[0x1e] = *(int *)(param_2 + 0x40);
  iVar1 = (**(code **)(*param_1 + 0xac))();
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0xac))(param_2);
    FUN_005a0cba(param_2);
  }
  return;
}

