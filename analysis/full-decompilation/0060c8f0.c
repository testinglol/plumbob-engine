
int FUN_0060c8f0(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  bVar1 = false;
  iVar5 = 0;
  iVar2 = FUN_0060c980();
  if (0 < iVar2) {
    do {
      if (bVar1) break;
      FUN_0060c950(iVar5);
      iVar2 = FUN_0060c7f0();
      iVar3 = FUN_00646330(iVar2 + 0x48,param_1);
      if (iVar3 == 0) {
        bVar1 = true;
        iVar4 = iVar5;
      }
      FUN_005a9340(iVar2);
      iVar5 = iVar5 + 1;
      iVar2 = FUN_0060c980();
    } while (iVar5 < iVar2);
  }
  FUN_0060c950(iVar4);
  return iVar4;
}

