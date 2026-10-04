
int __thiscall FUN_0046ef93(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0046f2bb(param_3,*(undefined4 *)(param_1 + 4),param_2);
  iVar1 = *(int *)(param_1 + 4);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0xc) {
    FUN_004b503e();
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + ((param_3 - param_2) / -0xc) * 0xc;
  return param_2;
}

