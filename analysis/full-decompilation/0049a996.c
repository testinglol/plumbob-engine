
uint __fastcall FUN_0049a996(uint param_1,uint param_2,byte param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (uint)param_3 * 0x20;
  iVar1 = ((param_2 >> 10 & 0x1f) + iVar3) * 0x20;
  iVar2 = ((param_2 >> 5 & 0x1f) + iVar3) * 0x20;
  return (CONCAT22((short)((uint)iVar1 >> 0x10),
                   (ushort)(byte)(&DAT_006e5e5c)[(param_1 >> 10 & 0x1f) + iVar1]) << 5 |
         CONCAT22((short)((uint)iVar2 >> 0x10),
                  (ushort)(byte)(&DAT_006e5e5c)[(param_1 >> 5 & 0x1f) + iVar2])) << 5 |
         (uint)(byte)(&DAT_006e5e5c)[(param_1 & 0x1f) + ((param_2 & 0x1f) + iVar3) * 0x20];
}

