
char FUN_005bc272(void)

{
  DWORD DVar1;
  
  DVar1 = GetVersion();
  return (DVar1 < 0x80000000) + '\x03';
}

