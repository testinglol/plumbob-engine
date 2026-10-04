
int __thiscall FUN_00419931(int *param_1,short param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar3 = 0xffffffcf;
  }
  else {
    uVar3 = 0;
  }
  FUN_004659fc(uVar3);
  iVar2 = FUN_00401f6f();
  if (iVar2 == 0) {
    iVar2 = FUN_00418f0b((int)param_2);
    if (iVar2 == 0) {
      FUN_004659fc(0xffffff9c);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

