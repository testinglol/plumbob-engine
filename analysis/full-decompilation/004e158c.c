
void __thiscall FUN_004e158c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_004e1787(param_3,*(undefined4 *)(param_1 + 4),param_2);
  iVar1 = *(int *)(param_1 + 4);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_004e12df();
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - param_2 >> 5) * -0x20;
  return;
}

