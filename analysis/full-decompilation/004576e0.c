
byte FUN_004576e0(void)

{
  int iVar1;
  
  iVar1 = FUN_004573f9();
  return ~*(byte *)(*(int *)(iVar1 + 0x60) + 0x98) & 1;
}

