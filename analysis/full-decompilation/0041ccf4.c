
void __thiscall FUN_0041ccf4(int *param_1,undefined4 param_2,undefined2 *param_3)

{
  char cVar1;
  int iVar2;
  undefined2 *puVar3;
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
  if (iVar2 == 0) {
    puVar3 = (undefined2 *)FUN_0041bb9f(param_2,&local_8);
    if (puVar3 == (undefined2 *)0x0) {
      FUN_004659fc(0xffffff9e);
    }
    else {
      *param_3 = *puVar3;
    }
  }
  return;
}

