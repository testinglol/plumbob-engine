
void __fastcall FUN_00445e8a(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 200) == 0) {
    iVar2 = FUN_0043acf5(0x2f726fff);
    iVar3 = FUN_0043acf5(0xbaa71c5);
    if (((iVar2 != 0) && (sVar1 = FUN_00440b6d(iVar2), sVar1 != 0)) &&
       (iVar2 = FUN_00407498((int)sVar1), iVar2 != 0)) {
      *(ushort *)(iVar2 + 0x5a) = *(ushort *)(iVar2 + 0x5a) | 0x4000;
      *(int *)(param_1 + 200) = iVar2;
    }
    if (((iVar3 != 0) && (sVar1 = FUN_00440b6d(iVar3), sVar1 != 0)) &&
       (iVar2 = FUN_00407498((int)sVar1), iVar2 != 0)) {
      *(ushort *)(iVar2 + 0x5a) = *(ushort *)(iVar2 + 0x5a) | 0x4000;
      *(int *)(param_1 + 0xcc) = iVar2;
    }
  }
  return;
}

