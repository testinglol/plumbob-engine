
uint __fastcall FUN_00417496(int *param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
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
    uVar2 = 0;
    for (puVar3 = (undefined4 *)param_1[6]; puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      uVar2 = uVar2 + 1;
    }
  }
  else {
    uVar2 = uVar2 & 0xffff0000;
  }
  return uVar2;
}

