
int __thiscall FUN_0046c3fb(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  for (iVar2 = FUN_0046c97b(param_3,iVar1,param_2); iVar2 != iVar1; iVar2 = iVar2 + 0x2c) {
    FUN_0046c1d5();
  }
  *(int *)(param_1 + 4) = iVar1 + ((param_3 - param_2) / 0x2c) * -0x2c;
  return param_2;
}

