
int FUN_00649fe4(ushort *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = 0;
  if (param_3 != 0) {
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
        param_3 = param_3 + -1;
      } while (((param_3 != 0) && (uVar1 != 0)) && (uVar1 == uVar2));
    }
    else {
      InterlockedIncrement(&DAT_00705360);
      bVar4 = DAT_0070535c == 0;
      if (!bVar4) {
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
        param_3 = param_3 + -1;
        if ((param_3 == 0) || (uVar1 == 0)) break;
      } while (uVar1 == uVar2);
      if (bVar4) {
        InterlockedDecrement(&DAT_00705360);
      }
      else {
        FUN_0063d8ec(0x13);
      }
    }
    iVar3 = (uint)uVar1 - (uint)uVar2;
  }
  return iVar3;
}

