
int __fastcall FUN_004e63de(int param_1)

{
  int iVar1;
  uint3 uVar2;
  
  iVar1 = *(int *)(DAT_006e486c + 0x1c);
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if ((iVar1 != 0) && (*(short *)(iVar1 + 0x44) != 0)) {
    return (uint)uVar2 << 8;
  }
  return CONCAT31(uVar2,*(undefined1 *)(param_1 + 2));
}

