
uint FUN_004726f7(void)

{
  DWORD DVar1;
  uint uVar2;
  
  DVar1 = timeGetTime();
  uVar2 = _rand();
  return uVar2 ^ DVar1 << 0x10;
}

