
int FUN_0063c58c(byte *param_1,int param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  
  FUN_0063d88b(0x19);
  pbVar2 = param_1;
  while (((param_2 != 0 && (*pbVar2 != 0)) &&
         ((pbVar1 = pbVar2, (*(byte *)((int)&DAT_00705240 + *pbVar2 + 1) & 4) == 0 ||
          (pbVar1 = pbVar2 + 1, *pbVar1 != 0))))) {
    param_2 = param_2 + -1;
    pbVar2 = pbVar1 + 1;
  }
  FUN_0063d8ec(0x19);
  return (int)pbVar2 - (int)param_1;
}

