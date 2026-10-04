
byte FUN_005cdecb(int *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  bVar1 = 0;
  if (DAT_006d6184 == 0) {
    bVar1 = 0;
  }
  else {
    for (iVar3 = *param_1; iVar3 != param_1[1]; iVar3 = iVar3 + 0x10) {
      bVar2 = FUN_005cddcf(iVar3);
      bVar1 = bVar1 | bVar2;
    }
  }
  return bVar1;
}

