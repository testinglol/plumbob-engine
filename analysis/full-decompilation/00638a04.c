
uint FUN_00638a04(uint param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 extraout_var;
  LONG LVar3;
  undefined2 uVar4;
  ushort uVar5;
  bool bVar6;
  
  uVar2 = 0xffff;
  uVar5 = (ushort)param_1;
  if (uVar5 != 0xffff) {
    if (DAT_00703bec == 0) {
      if ((0x40 < uVar5) && (uVar5 < 0x5b)) {
        param_1 = param_1 + 0x20;
      }
      uVar2 = param_1 & 0xffff;
    }
    else {
      InterlockedIncrement(&DAT_00705360);
      bVar6 = DAT_0070535c != 0;
      if (bVar6) {
        InterlockedDecrement(&DAT_00705360);
        FUN_0063d88b(0x13);
      }
      uVar1 = FUN_00638a7e(param_1);
      if (bVar6) {
        FUN_0063d8ec(0x13);
        uVar4 = extraout_var;
      }
      else {
        LVar3 = InterlockedDecrement(&DAT_00705360);
        uVar4 = (short)((uint)LVar3 >> 0x10);
      }
      uVar2 = CONCAT22(uVar4,uVar1);
    }
  }
  return uVar2;
}

