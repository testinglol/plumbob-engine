
byte __thiscall FUN_00419df2(int *param_1,undefined4 param_2)

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
    iVar2 = FUN_00418e2d(param_2,&local_8,0);
    if (iVar2 != 0) {
      FUN_004659fc(0);
      return *(byte *)(iVar2 + 8) >> 4 & 1;
    }
    FUN_004659fc(0xffffff9d);
  }
  return 1;
}

