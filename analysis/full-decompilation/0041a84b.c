
int __thiscall FUN_0041a84b(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0041adce(param_3,*(undefined4 *)(param_1 + 4),param_2);
  iVar1 = *(int *)(param_1 + 4);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x14) {
    FUN_0041a7c5();
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + ((param_3 - param_2) / -0x14) * 0x14;
  return param_2;
}

