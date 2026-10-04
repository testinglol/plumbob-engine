
void __thiscall FUN_004b8ec7(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_004b909d(param_3,*(undefined4 *)(param_1 + 4),param_2);
  iVar1 = *(int *)(param_1 + 4);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 8) {
    FUN_004b9149(iVar2);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - param_2 >> 3) * -8;
  return;
}

