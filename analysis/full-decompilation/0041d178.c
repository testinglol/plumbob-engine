
void __thiscall FUN_0041d178(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *local_8;
  
  local_8 = param_1;
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
  iVar2 = FUN_00401f6f();
  if (iVar2 != 0) {
    return;
  }
  cVar1 = (**(code **)(*param_1 + 0x20))();
  if (cVar1 == '\0') {
    FUN_004659fc(0xffffffd3);
    return;
  }
  iVar2 = FUN_0041bb9f(param_2,&local_8);
  if (iVar2 == 0) {
    iVar3 = -99;
  }
  else {
    iVar3 = FUN_0041d3d0(iVar2);
    if (iVar3 == 0) {
      FUN_0041bcbb(iVar2);
      goto LAB_0041d1ef;
    }
  }
  FUN_004659fc(iVar3);
LAB_0041d1ef:
  FUN_004131cb();
  return;
}

