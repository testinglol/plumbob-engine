
void FUN_004c941c(ushort *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1[1] != 0) {
    do {
      pbVar1 = param_2;
      if ((ushort)*param_2 == param_1[5]) {
        do {
          *pbVar1 = 0xff;
          pbVar1 = pbVar1 + 1;
        } while ((ushort)*pbVar1 == param_1[5]);
      }
      for (pbVar1 = param_2 + (*param_1 - 1); (ushort)*pbVar1 == param_1[5]; pbVar1 = pbVar1 + -1) {
        *pbVar1 = 0xff;
      }
      param_2 = param_2 + param_3;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)param_1[1]);
  }
  return;
}

