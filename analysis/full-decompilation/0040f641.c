
int __thiscall FUN_0040f641(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  FUN_0040fc83(param_3,iVar1,param_2);
  *(int *)(param_1 + 4) = iVar1 + ((param_3 - param_2) / 0x90) * -0x90;
  return param_2;
}

