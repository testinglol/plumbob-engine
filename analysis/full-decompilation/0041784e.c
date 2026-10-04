
void __thiscall FUN_0041784e(int *param_1,undefined4 param_2,undefined2 *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_8;
  
  local_8 = param_1;
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
    iVar2 = FUN_00418360(param_1[6],param_2,&local_8,0);
    if (iVar2 == 0) {
      FUN_004659fc(0xffffff9e);
    }
    else {
      *param_3 = *(undefined2 *)(iVar2 + 4);
    }
  }
  return;
}

