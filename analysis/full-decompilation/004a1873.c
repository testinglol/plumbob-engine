
int __thiscall FUN_004a1873(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_004a20ca(param_3,*(undefined4 *)(param_1 + 4),param_2);
  iVar1 = *(int *)(param_1 + 4);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x11c) {
    FUN_004a216a();
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + ((param_3 - param_2) / -0x11c) * 0x11c;
  return param_2;
}

