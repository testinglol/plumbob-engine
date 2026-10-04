
uint __thiscall FUN_0041997e(int *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar3 = 0xffffffcf;
  }
  else {
    uVar3 = 0;
  }
  FUN_004659fc(uVar3);
  uVar2 = FUN_00401f6f();
  if (uVar2 == 0) {
    uVar2 = FUN_00418f37(param_2);
  }
  else {
    uVar2 = uVar2 & 0xffff0000;
  }
  return uVar2;
}

