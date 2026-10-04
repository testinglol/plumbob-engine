
ushort __fastcall FUN_00438f12(uint param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = (uint)(param_2 >> 3) * 0x20;
  return (&DAT_006eef18)
         [(byte)(&DAT_006ee2f8)
                [(uint)(param_2 >> 3) * 0x40 + ((param_1 >> 8 & 0xff) >> (DAT_006c66ec & 0x1f))]] |
         (&DAT_006eef98)[(byte)(&DAT_006eeaf8)[iVar1 + (param_1 >> 0x13 & 0x1f)]] |
         (ushort)(byte)(&DAT_006eeef8)[(byte)(&DAT_006edef8)[iVar1 + (param_1 >> 3 & 0x1f)]];
}

