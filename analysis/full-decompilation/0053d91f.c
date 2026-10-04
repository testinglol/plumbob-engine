
void __thiscall FUN_0053d91f(int param_1,undefined4 param_2)

{
  char cVar1;
  byte *pbVar2;
  
  for (pbVar2 = *(byte **)(param_1 + 0x30); pbVar2 != *(byte **)(param_1 + 0x34);
      pbVar2 = pbVar2 + 6) {
    *pbVar2 = 0;
    if ((char)param_2 != '\0') {
      cVar1 = FUN_0053d968(pbVar2[1]);
      if (cVar1 != '\0') {
        *pbVar2 = *pbVar2 | 1;
      }
    }
    cVar1 = FUN_0053d98e(pbVar2[1],param_2);
    if (cVar1 != '\0') {
      *pbVar2 = *pbVar2 | 8;
    }
  }
  return;
}

