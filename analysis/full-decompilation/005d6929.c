
uint FUN_005d6929(byte param_1)

{
  SHORT SVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((param_1 & 1) != 0) {
    uVar2 = 0x10;
  }
  if ((param_1 & 2) != 0) {
    uVar2 = uVar2 | 0x20;
  }
  if ((param_1 & 4) != 0) {
    uVar2 = uVar2 | 1;
  }
  if ((param_1 & 8) != 0) {
    uVar2 = uVar2 | 2;
  }
  SVar1 = GetKeyState(0x12);
  if (SVar1 < 0) {
    uVar2 = uVar2 | 4;
  }
  return uVar2;
}

