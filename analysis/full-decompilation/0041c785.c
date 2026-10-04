
undefined4 __thiscall FUN_0041c785(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar2 = FUN_00413047(param_2);
  }
  else {
    uVar2 = 0xffffffd1;
  }
  return uVar2;
}

