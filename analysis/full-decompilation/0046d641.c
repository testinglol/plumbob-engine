
char __fastcall FUN_0046d641(int param_1)

{
  short sVar1;
  char cVar2;
  
  sVar1 = *(short *)(param_1 + 0x10);
  if (sVar1 < 6) {
    cVar2 = '\x02';
  }
  else {
    if (6 < sVar1) {
      if (sVar1 < 0x12) {
        return '\0';
      }
      return (0x12 < sVar1) + '\x01';
    }
    cVar2 = '\x03';
  }
  return cVar2;
}

