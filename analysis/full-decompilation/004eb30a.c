
int __thiscall FUN_004eb30a(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  for (iVar2 = FUN_004eb72a(param_3,iVar1,param_2); iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_004e8c66();
  }
  *(int *)(param_1 + 4) = iVar1 + ((param_3 - param_2) / 0x44) * -0x44;
  return param_2;
}

