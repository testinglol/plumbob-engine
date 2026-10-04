
int __thiscall FUN_0045fa46(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (param_2 + 0x9c != iVar1) {
    FUN_0046077a(param_2 + 0x9c,iVar1,param_2);
  }
  *(int *)(param_1 + 4) = iVar1 + -0x9c;
  FUN_0045fae5();
  return param_2;
}

