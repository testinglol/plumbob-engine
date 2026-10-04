
undefined4 FUN_00646993(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  bool bVar2;
  
  InterlockedIncrement(&DAT_00705360);
  bVar2 = DAT_0070535c != 0;
  if (bVar2) {
    InterlockedDecrement(&DAT_00705360);
    FUN_0063d88b(0x13);
  }
  uVar1 = FUN_006469ec(param_1,param_2);
  if (bVar2) {
    FUN_0063d8ec(0x13);
  }
  else {
    InterlockedDecrement(&DAT_00705360);
  }
  return uVar1;
}

