
char __fastcall FUN_0054ebd3(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  FUN_0054f51d(0,0,0,0);
  cVar1 = FUN_0054e5e9(*(undefined4 *)(param_1 + 0x1d8));
  if (((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) && (*(int *)(param_1 + 0x244) != 0)) {
    iVar3 = *(int *)(param_1 + 0x208);
    iVar2 = *(int *)(param_1 + 0x20c);
    if (*(int *)(param_1 + 0x200) < 0) {
      iVar3 = iVar3 + *(int *)(param_1 + 0x200);
    }
    if (*(int *)(param_1 + 0x204) < 0) {
      iVar2 = iVar2 + *(int *)(param_1 + 0x204);
    }
    *(int *)(param_1 + 0x210) = iVar3;
    *(int *)(param_1 + 0x214) = iVar2;
  }
  if (cVar1 != '\0') {
    FUN_0054ec7a(param_1 + 0x210);
    if (DAT_006f5390 != 0) {
      FUN_0054fcb8(param_1 + 0x194,param_1 + 0x21c,1);
    }
  }
  return cVar1;
}

