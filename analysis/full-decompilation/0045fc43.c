
int __thiscall FUN_0045fc43(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  for (iVar2 = FUN_0046077a(param_3,iVar1,param_2); iVar2 != iVar1; iVar2 = iVar2 + 0x9c) {
    FUN_0045fae5();
  }
  *(int *)(param_1 + 4) = iVar1 + ((param_3 - param_2) / 0x9c) * -0x9c;
  return param_2;
}

