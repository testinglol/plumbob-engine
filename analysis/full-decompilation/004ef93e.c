
void FUN_004ef93e(undefined4 param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  
  puVar2 = param_3;
  puVar1 = param_2;
  uVar5 = 0;
  *param_2 = 0x280;
  *param_3 = 0x1e0;
  FUN_005b8e25(param_1,0);
  iVar4 = FUN_005b936f(param_1,uVar5);
  if (iVar4 != 0) {
    cVar3 = FUN_005b8f4a(0x30);
    if (cVar3 != '\0') {
      cVar3 = FUN_005b904f((int)&param_2 + 2,2);
      if (cVar3 != '\0') {
        cVar3 = FUN_005b904f((int)&param_3 + 2,2);
        if (cVar3 != '\0') {
          *puVar1 = (uint)param_2 >> 0x10;
          *puVar2 = (uint)param_3 >> 0x10;
        }
      }
    }
    FUN_005b8e25(iVar4);
    FUN_005b95c0(iVar4);
  }
  return;
}

