
undefined4 FUN_00587b7b(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  FUN_0047034e(param_1,param_2,0x53545223,0,0);
  uVar1 = FUN_0046ffa4(0,1);
  iVar2 = FUN_0046fbe5(0xffffffff);
  if (iVar2 < 0x23) {
    do {
      uVar4 = 0xffffffff;
      puVar3 = &DAT_006de560;
      iVar2 = FUN_0046fbe5(0xffffffff);
      FUN_0047057a(iVar2 + 1,puVar3,uVar4);
      iVar2 = FUN_0046fbe5(0xffffffff);
    } while (iVar2 < 0x23);
    FUN_0046fd3b(param_1,param_2);
  }
  return uVar1;
}

