
int __thiscall FUN_00468be1(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  FUN_00469315(param_3,iVar1,param_2);
  *(int *)(param_1 + 4) = iVar1 + ((param_3 - param_2) / 0xc) * -0xc;
  return param_2;
}

