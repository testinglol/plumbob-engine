
void __thiscall FUN_0041ce03(int *param_1,undefined4 param_2)

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
    iVar2 = FUN_0041bb9f(param_2,&local_8);
    if (iVar2 == 0) {
      uVar3 = 0xffffff9d;
    }
    else {
      if (*(int *)(iVar2 + 0xc) == -1) {
        (**(code **)(*param_1 + 0x7c))(param_2);
      }
      *(undefined4 *)(iVar2 + 8) = 0;
      uVar3 = 0;
      *(ushort *)(iVar2 + 2) =
           *(ushort *)(iVar2 + 2) ^ (ushort)(*(byte *)(iVar2 + 4) ^ *(byte *)(iVar2 + 2));
    }
    FUN_004659fc(uVar3);
  }
  return;
}

