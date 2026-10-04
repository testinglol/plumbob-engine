
void FUN_0055fda8(void)

{
  DWORD DVar1;
  int iVar2;
  LPCSTR pCVar3;
  LPCSTR local_22c;
  undefined1 local_224 [260];
  int local_120;
  int local_11c;
  LPCSTR local_110;
  
  FUN_0046f824(local_224,0,0x104);
  FUN_0046f8e4(*(undefined4 *)(DAT_006e486c + 0x24));
  DVar1 = GetFileAttributesA(local_22c);
  if ((DVar1 & 1) == 0) {
    FUN_0054b752(1);
    do {
      iVar2 = FUN_0055ff03();
      if (iVar2 == 0) {
        FUN_0055ff3f();
        while( true ) {
          if (local_11c <= local_120) {
            return;
          }
          if (local_110 == (LPCSTR)0x0) {
            return;
          }
          DVar1 = GetFileAttributesA(local_110);
          if ((DVar1 & 1) != 0) break;
          FUN_0055ff81();
        }
        break;
      }
      pCVar3 = (LPCSTR)FUN_0055ff03();
      DVar1 = GetFileAttributesA(pCVar3);
    } while ((DVar1 & 1) == 0);
  }
  DVar1 = GetFileAttributesA(local_22c);
  SetFileAttributesA(local_22c,DVar1 & 0xfffffffe);
  FUN_0054b752(1);
  while (iVar2 = FUN_0055ff03(), iVar2 != 0) {
    pCVar3 = (LPCSTR)FUN_0055ff03();
    DVar1 = GetFileAttributesA(pCVar3);
    SetFileAttributesA(pCVar3,DVar1 & 0xfffffffe);
  }
  FUN_0055ff3f();
  while (iVar2 = FUN_00558715(), iVar2 != 0) {
    pCVar3 = (LPCSTR)FUN_00558715();
    DVar1 = GetFileAttributesA(pCVar3);
    SetFileAttributesA(pCVar3,DVar1 & 0xfffffffe);
    FUN_0055ff81();
  }
  return;
}

