
bool FUN_004eab60(uint param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_006f2630 != 0) {
    cVar1 = FUN_005a5e72();
    if (cVar1 != '\0') {
      if (param_1 < (uint)((DAT_006f264c - DAT_006f2648) / 0x44)) {
        iVar2 = FUN_004e8a7a();
        iVar3 = FUN_004096c2();
        return iVar2 == iVar3;
      }
    }
  }
  return false;
}

