
int __thiscall FUN_0042730f(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x118);
  iVar1 = *(int *)(param_2 + 0x11c);
  if ((*(int *)(param_1 + 0x164) != 0) && (*(int *)(param_2 + 0x110) == *(int *)(param_1 + 0x164)))
  {
    iVar2 = *(int *)(DAT_006e486c + 0x1c);
    iVar1 = __ftol();
    iVar1 = iVar1 + *(int *)(iVar2 + 0xa0) + *(int *)(iVar2 + 0x9c);
    iVar2 = FUN_0046d9e5();
  }
  return iVar2 + iVar1;
}

