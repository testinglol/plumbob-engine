
int FUN_00648f3a(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    if (DAT_00703be8 != 0) {
      InterlockedIncrement(&DAT_00705360);
      bVar3 = DAT_0070535c == 0;
      if (!bVar3) {
        InterlockedDecrement(&DAT_00705360);
        FUN_0063d88b(0x13);
      }
      if (DAT_00703be8 != 0) {
        iVar1 = FUN_00649d99(DAT_00703be8,0x1001,param_1,param_3,param_2,param_3,DAT_00703c00);
        if (iVar1 == 0) {
          if (bVar3) {
            InterlockedDecrement(&DAT_00705360);
          }
          else {
            FUN_0063d8ec(0x13);
          }
          puVar2 = (undefined4 *)FUN_0063d796();
          *puVar2 = 0x16;
          return 0x7fffffff;
        }
        if (bVar3) {
          InterlockedDecrement(&DAT_00705360);
        }
        else {
          FUN_0063d8ec(0x13);
        }
        return iVar1 + -2;
      }
      if (bVar3) {
        InterlockedDecrement(&DAT_00705360);
      }
      else {
        FUN_0063d8ec(0x13);
      }
    }
    iVar1 = FUN_00649fe4(param_1,param_2,param_3);
  }
  return iVar1;
}

