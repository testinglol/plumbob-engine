
void __thiscall FUN_00537ca4(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  FUN_005dda18(param_2,param_3,param_4,param_5);
  param_5 = param_5 - param_3;
  iVar1 = (param_4 - param_2) / 3;
  if (*(int **)(param_1 + 0xd4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xd4) + 0x60))(0,0,iVar1,param_5);
  }
  if (*(int **)(param_1 + 0xd8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xd8) + 0x60))(iVar1,0,iVar1 * 2,param_5);
  }
  if (*(int **)(param_1 + 0xdc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xdc) + 0x60))(iVar1 * 2,0,param_4 - param_2,param_5);
  }
  return;
}

