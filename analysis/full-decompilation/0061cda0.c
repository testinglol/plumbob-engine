
int FUN_0061cda0(int param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = 0xfbea;
  bVar2 = *param_2;
  while (bVar2 != 0) {
    pbVar1 = param_2 + 1;
    uVar3 = (uint)(ushort)(*(ushort *)(&DAT_006da280 + ((uint)bVar2 ^ uVar3 & 0xff) * 2) ^
                          (ushort)(uVar3 >> 8));
    param_2 = param_2 + 1;
    bVar2 = *pbVar1;
  }
  return *(int *)(param_1 + 0x260) + (uVar3 & 0x7ff) * 4;
}

