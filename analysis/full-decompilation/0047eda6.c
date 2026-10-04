
byte __fastcall FUN_0047eda6(int param_1)

{
  byte bVar1;
  
  bVar1 = (*(byte *)(param_1 + 5) & 1) != 0;
  if ((*(byte *)(param_1 + 5) & 0x10) != 0) {
    bVar1 = bVar1 | 2;
  }
  return bVar1;
}

