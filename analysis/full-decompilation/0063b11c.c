
size_t FUN_0063b11c(char *param_1,char *param_2,size_t param_3)

{
  size_t sVar1;
  bool bVar2;
  size_t local_c;
  
  local_c = 0x7fffffff;
  if ((DAT_00703be8 != 0) || (DAT_00703bfc != 0)) {
    InterlockedIncrement(&DAT_00705360);
    bVar2 = DAT_0070535c == 0;
    if (!bVar2) {
      InterlockedDecrement(&DAT_00705360);
      FUN_0063d88b(0x13);
    }
    if ((DAT_00703be8 != 0) || (DAT_00703bfc != 0)) {
      sVar1 = FUN_0064439a(DAT_00703be8,0x400,param_2,0xffffffff,0,0,DAT_00703c00,1);
      if ((sVar1 != 0) && (local_c = sVar1, (int)sVar1 <= (int)param_3)) {
        FUN_0064439a(DAT_00703be8,0x400,param_2,0xffffffff,param_1,param_3,DAT_00703c00,1);
      }
      if (!bVar2) {
        FUN_0063d8ec(0x13);
        return local_c;
      }
      InterlockedDecrement(&DAT_00705360);
      return local_c;
    }
    if (bVar2) {
      InterlockedDecrement(&DAT_00705360);
    }
    else {
      FUN_0063d8ec(0x13);
    }
  }
  _strncpy(param_1,param_2,param_3);
  sVar1 = _strlen(param_2);
  return sVar1;
}

