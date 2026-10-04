
void FUN_004e9c34(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  undefined ***pppuVar4;
  undefined **local_110;
  char *local_10c;
  undefined1 local_104 [256];
  
  if ((-1 < param_1) && (param_1 < (DAT_006f264c - DAT_006f2648) / 0x44)) {
    iVar1 = FUN_004e8a7a();
    FUN_00406466(0,DAT_00666580);
    if (iVar1 != 0) {
      uVar2 = thunk_FUN_00457ea7();
      FUN_005d499c(uVar2);
    }
    iVar1 = FUN_004ea79e(param_1);
    if (*(short *)(iVar1 + 0x40) != 0) {
      iVar1 = FUN_004ea79e(param_1);
      if (*(short *)(iVar1 + 0x40) != 4) {
        iVar1 = FUN_004ea79e(param_1);
        if (*(short *)(iVar1 + 0x7a) != 0) {
          FUN_004015e4(0x20);
          FUN_0046f824(local_104,0,0x100);
          local_110 = &PTR_FUN_00666524;
          pppuVar4 = &local_110;
          iVar1 = FUN_004ea79e(param_1,pppuVar4);
          FUN_00425db3((int)*(short *)(iVar1 + 0x7a));
          FUN_004102d4(pppuVar4);
          sVar3 = _strlen(local_10c);
          FUN_00412d8a(local_10c,local_10c + sVar3);
        }
      }
    }
  }
  return;
}

