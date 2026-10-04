
int __fastcall FUN_00578f7e(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x74) + *(int *)(param_1 + 0x48);
  iVar1 = *(int *)(*(int *)(param_1 + 0x34) + 0x28);
  if (iVar1 <= iVar2) {
    iVar2 = iVar1 + -1;
  }
  return iVar2;
}

