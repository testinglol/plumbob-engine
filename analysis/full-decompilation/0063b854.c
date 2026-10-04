
byte * FUN_0063b854(int param_1,undefined4 param_2)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  iVar1 = FUN_0063e1d3();
  if (DAT_0070513c == 0) {
    pbVar2 = (byte *)FUN_0063864b(param_1,param_2);
  }
  else {
    if (((param_1 != 0) || (param_1 = *(int *)(iVar1 + 0x20), param_1 != 0)) &&
       (pbVar2 = (byte *)FUN_0063c63c(param_1,param_2), pbVar2 != (byte *)0x0)) {
      FUN_0063d88b(0x19);
      if ((*pbVar2 == 0) ||
         (((*(byte *)((int)&DAT_00705240 + *pbVar2 + 1) & 4) != 0 && (pbVar2[1] == 0)))) {
        pbVar2 = (byte *)0x0;
      }
      else {
        pbVar3 = (byte *)FUN_0063b6ba(pbVar2,param_2);
        if ((pbVar3 == (byte *)0x0) || (*pbVar3 == 0)) {
          pbVar3 = (byte *)0x0;
        }
        else {
          if ((*(byte *)((int)&DAT_00705240 + *pbVar3 + 1) & 4) != 0) {
            *pbVar3 = 0;
            pbVar3 = pbVar3 + 1;
          }
          *pbVar3 = 0;
          pbVar3 = pbVar3 + 1;
        }
        *(byte **)(iVar1 + 0x20) = pbVar3;
      }
      FUN_0063d8ec(0x19);
      return pbVar2;
    }
    pbVar2 = (byte *)0x0;
  }
  return pbVar2;
}

