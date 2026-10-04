
undefined1 __fastcall FUN_0053d679(byte *param_1)

{
  byte bVar1;
  
  bVar1 = *param_1;
  if ((((((bVar1 & 0x10) == 0) || ((bVar1 & 3) == 0)) &&
       (((bVar1 & 0x20) == 0 || ((bVar1 & 6) == 0)))) &&
      (((bVar1 & 0x40) == 0 || ((bVar1 & 4) == 0)))) &&
     (((bVar1 & 0x80) == 0 || ((bVar1 & 9) == 0)))) {
    return 1;
  }
  return 0;
}

