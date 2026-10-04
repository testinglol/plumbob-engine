
void __thiscall FUN_0046c39a(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_0046c637(iVar1,param_2);
  }
  else {
    FUN_0046cc16();
    *(int *)(param_1 + 4) = iVar1 + 0x2c;
  }
  return;
}

