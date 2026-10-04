
int __fastcall FUN_004131cb(int param_1)

{
  char cVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    return -0x31;
  }
  cVar1 = FUN_005b9034();
  return (-(uint)(cVar1 != '\0') & 0x32) - 0x32;
}

