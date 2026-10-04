
void __thiscall FUN_00419cc3(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  uVar1 = param_3;
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
  iVar3 = FUN_00401f6f();
  if (iVar3 == 0) {
    FUN_0046f824(local_44,0,0x40);
    local_50[0] = &PTR_FUN_0066651c;
    FUN_0046f8e4(param_3);
    param_3 = 0;
    while( true ) {
      iVar3 = FUN_00418dda(param_2,uVar1,0);
      if (iVar3 == 0) break;
      FUN_0046f8e4(local_50);
      FUN_0046fa40(param_3);
      param_3 = param_3 + 1;
    }
  }
  return;
}

