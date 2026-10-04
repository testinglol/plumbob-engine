
void __thiscall FUN_0041cd48(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  iVar3 = 0;
  if (cVar1 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
  iVar2 = FUN_00401f6f();
  if (iVar2 == 0) {
    FUN_0046f824(local_44,0,0x40);
    local_50[0] = &PTR_FUN_0066651c;
    FUN_0046f8e4(param_3);
    while( true ) {
      iVar2 = FUN_0041bb41(param_2,param_3);
      if (iVar2 == 0) break;
      FUN_0046f8e4(local_50);
      FUN_0046fa40(iVar3);
      iVar3 = iVar3 + 1;
    }
  }
  return;
}

