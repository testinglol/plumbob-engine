
int FUN_0046f556(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_006e545c;
  uVar2 = DAT_006e545c & 0xffff;
  DAT_006e545c = DAT_006e545c * 0x41c64e6d + 0x3039;
  return (uVar2 * 0x4e6d + 0x3039 >> 0x10) + uVar2 * 0x41c6 + (uVar1 >> 0x10) * 0x41c64e6d;
}

