
uint FUN_005bc285(void)

{
  byte bVar1;
  uint uStack_8;
  
  uStack_8 = FUN_005bddff();
  uStack_8 = uStack_8 & 0x7fff;
  if (uStack_8 == 6) {
    bVar1 = FUN_005bdeb6();
    bVar1 = bVar1 >> 4 & 7;
    if (1 < bVar1) {
      if (bVar1 < 4) {
        uStack_8 = 7;
      }
      else if (bVar1 < 6) {
        uStack_8 = 8;
      }
      else if (bVar1 < 7) {
        uStack_8 = 9;
      }
    }
  }
  else if (6 < uStack_8) {
    uStack_8 = uStack_8 + 3;
  }
  return uStack_8;
}

