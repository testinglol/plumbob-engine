
int FUN_00649531(byte param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  if (param_2 == 1) {
    return (-(uint)((*(byte *)((int)&DAT_00705240 + uVar2 + 1) & 8) != 0) & 3) - 1;
  }
  bVar1 = *(byte *)((int)&DAT_00705240 + uVar2 + 1);
  if ((bVar1 & 4) != 0) {
    return 1;
  }
  if (((*(ushort *)(&DAT_006dac22 + uVar2 * 2) & 0x157) == 0) && ((bVar1 & 3) == 0)) {
    return -1;
  }
  return 0;
}

