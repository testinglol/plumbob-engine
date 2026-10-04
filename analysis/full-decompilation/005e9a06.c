
void __thiscall FUN_005e9a06(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x84);
  iVar2 = *(int *)(param_1 + 0x7c);
  iVar3 = *(int *)(param_1 + 0x88);
  iVar4 = *(int *)(param_1 + 0x80);
  FUN_005dda18(param_2,param_3,param_4,param_5);
  if ((param_4 - param_2 != iVar1 - iVar2) || (param_5 - param_3 != iVar3 - iVar4)) {
    FUN_005e9d7d();
  }
  return;
}

