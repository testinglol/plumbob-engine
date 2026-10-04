
int __fastcall FUN_0059964b(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x130);
  for (iVar2 = *(int *)(param_1 + 0x28); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x20)) {
    iVar1 = FUN_0059964b();
    if (iVar3 <= iVar1) {
      iVar3 = iVar1;
    }
  }
  return iVar3;
}

