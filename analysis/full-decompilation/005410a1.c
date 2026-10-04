
void __thiscall FUN_005410a1(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_00541581(param_3,*(undefined4 *)(param_1 + 4),param_2);
  iVar1 = *(int *)(param_1 + 4);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 4) {
    FUN_005421a6(iVar2);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - param_2 >> 2) * -4;
  return;
}

