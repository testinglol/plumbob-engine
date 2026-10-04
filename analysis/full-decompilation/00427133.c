
int __fastcall FUN_00427133(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) == 0) {
    iVar1 = 0xb;
  }
  else {
    for (iVar2 = *(int *)(param_1 + 0x174); iVar2 != *(int *)(param_1 + 0x178); iVar2 = iVar2 + 8) {
      if (*(int *)(iVar2 + 4) == 1) {
        iVar1 = iVar1 + 1;
      }
    }
  }
  return iVar1;
}

