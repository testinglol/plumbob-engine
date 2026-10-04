
int FUN_0064a65e(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  
  if (DAT_00703bec == 0) {
    do {
      uVar1 = *param_1;
      if ((uVar1 < 0x5b) && (0x40 < uVar1)) {
        uVar1 = uVar1 + 0x20;
      }
      uVar2 = *param_2;
      if ((uVar2 < 0x5b) && (0x40 < uVar2)) {
        uVar2 = uVar2 + 0x20;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while ((uVar1 != 0) && (uVar1 == uVar2));
  }
  else {
    InterlockedIncrement(&DAT_00705360);
    bVar3 = DAT_0070535c == 0;
    if (!bVar3) {
      InterlockedDecrement(&DAT_00705360);
      FUN_0063d88b(0x13);
    }
    do {
      uVar1 = *param_1;
      param_1 = param_1 + 1;
      uVar1 = FUN_00638a7e(uVar1);
      uVar2 = *param_2;
      param_2 = param_2 + 1;
      uVar2 = FUN_00638a7e(uVar2);
      if (uVar1 == 0) break;
    } while (uVar1 == uVar2);
    if (bVar3) {
      InterlockedDecrement(&DAT_00705360);
    }
    else {
      FUN_0063d8ec(0x13);
    }
  }
  return (uint)uVar1 - (uint)uVar2;
}

