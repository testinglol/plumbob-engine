
byte FUN_005d68de(void)

{
  SHORT SVar1;
  byte bVar2;
  
  SVar1 = GetKeyState(0x10);
  bVar2 = SVar1 < 0;
  SVar1 = GetKeyState(0x11);
  if (SVar1 < 0) {
    bVar2 = bVar2 | 2;
  }
  SVar1 = GetKeyState(1);
  if (SVar1 < 0) {
    bVar2 = bVar2 | 0x10;
  }
  SVar1 = GetKeyState(2);
  if (SVar1 < 0) {
    bVar2 = bVar2 | 0x20;
  }
  SVar1 = GetKeyState(0x12);
  if (SVar1 < 0) {
    bVar2 = bVar2 | 4;
  }
  return bVar2;
}

