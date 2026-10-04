
int __fastcall FUN_0040d106(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined1 local_a0 [152];
  int local_8;
  
  FUN_0040d0d9();
  FUN_00472fca(*(undefined4 *)(param_1 + 8),2);
  iVar1 = (*(int **)(param_1 + 0x7c))[1];
  iVar3 = **(int **)(param_1 + 0x7c);
  local_8 = iVar3;
  if (iVar3 != iVar1) {
    do {
      cVar2 = FUN_00473098(local_a0);
      if (cVar2 != '\0') break;
      iVar3 = iVar3 + 0x98;
    } while (iVar3 != iVar1);
    if (iVar3 != iVar1) {
      return (iVar3 - local_8) / 0x98;
    }
  }
  return -1;
}

