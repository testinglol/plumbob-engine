
int __fastcall FUN_0042c217(int param_1)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)DAT_006e486c >> 8);
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) == 0) {
    return (uint)uVar1 << 8;
  }
  return CONCAT31(uVar1,*(undefined1 *)(param_1 + 0x1aa));
}

