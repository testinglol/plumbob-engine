
undefined4 FUN_00639f2c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_006375b5(param_1,0x2e);
  iVar2 = FUN_0063903a(iVar1 + 1,0,0x20);
  if (iVar2 + 1U < 0x7fff) {
    uVar3 = FUN_0063b31d(iVar2 + 1U,&param_1,0x20);
    FUN_006358b0(iVar1 + 1,uVar3);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

