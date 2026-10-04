
int __thiscall FUN_004d419c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  for (iVar2 = FUN_004d4441(param_3,iVar1,param_2); iVar2 != iVar1; iVar2 = iVar2 + 0x1c) {
    FUN_004e8971();
  }
  *(int *)(param_1 + 4) = iVar1 + ((param_3 - param_2) / 0x1c) * -0x1c;
  return param_2;
}

