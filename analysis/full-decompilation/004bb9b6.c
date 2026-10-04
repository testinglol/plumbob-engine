
int __fastcall FUN_004bb9b6(int param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = (byte)*(undefined4 *)(param_1 + 0xc);
  bVar2 = bVar1 - 1;
  return ((0x3a << (bVar2 & 0x1f)) + (8 << (bVar1 & 0x1f))) * (*(int *)(param_1 + 4) * 2 + 1) *
         (0x10 << (bVar2 & 0x1f));
}

