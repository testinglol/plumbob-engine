
uint __thiscall FUN_0041cdc4(int *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
  uVar2 = FUN_00401f6f();
  if (uVar2 == 0) {
    iVar3 = FUN_0041be24(param_2,0x80);
    uVar2 = iVar3 + 1;
  }
  else {
    uVar2 = uVar2 & 0xffff0000;
  }
  return uVar2;
}

