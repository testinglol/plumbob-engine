
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short __fastcall FUN_0045ef31(int param_1)

{
  float fVar1;
  byte bVar2;
  
  fVar1 = *(float *)(param_1 + 0x7b8);
  bVar2 = fVar1 < _DAT_0066657c |
          (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_0066657c)) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar1 == _DAT_0066657c) << 0xe) >> 8);
  if (fVar1 < _DAT_0066657c) {
    return CONCAT11(bVar2,1);
  }
  return (ushort)bVar2 << 8;
}

