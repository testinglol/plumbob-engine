
void FUN_00627c40(int param_1,int param_2,int param_3,byte *param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = 7;
  if (0 < param_2) {
    pbVar2 = (byte *)(param_1 + 3);
    do {
      if (param_3 == 1) {
        *pbVar2 = -((*param_4 >> ((byte)iVar3 & 0x1f) & 1) != 0);
      }
      else {
        if ((*pbVar2 & 0x80) == 0) {
          bVar1 = 0;
        }
        else {
          bVar1 = (byte)(1 << ((byte)iVar3 & 0x1f));
        }
        *param_4 = *param_4 | bVar1;
      }
      pbVar2 = pbVar2 + 4;
      iVar3 = iVar3 + -1;
      if (iVar3 < 0) {
        iVar3 = 7;
        param_4 = param_4 + 1;
      }
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

