
undefined4 FUN_004eec4f(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  DVar1 = GetVersion();
  if (((DVar1 & 0x80000000) == 0) && (4 < (byte)DVar1)) {
    uVar2 = 1;
  }
  return uVar2;
}

