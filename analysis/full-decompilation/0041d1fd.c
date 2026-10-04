
void __thiscall FUN_0041d1fd(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  undefined1 local_94 [64];
  undefined1 local_54 [8];
  undefined2 local_4c;
  char local_48 [63];
  undefined1 local_9;
  undefined1 local_8 [4];
  
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
  puVar3 = (undefined2 *)FUN_0041bb9f(param_2,local_8);
  if (puVar3 == (undefined2 *)0x0) {
    iVar2 = -99;
  }
  else {
    FUN_0046f824(local_94,0,0x40);
    iVar2 = FUN_0046f93d(puVar3 + 8);
    if (iVar2 == 0) goto LAB_0041d2d2;
    FUN_0046f8e4(param_4);
    if (*(int *)(puVar3 + 6) == -1) goto LAB_0041d2d2;
    iVar2 = FUN_0041a545(local_54,*(int *)(puVar3 + 6));
    if (iVar2 == 0) {
      local_4c = *puVar3;
      _strncpy(local_48,*(char **)(puVar3 + 10),0x3f);
      local_9 = 0;
      FUN_0041d5fe(local_54,*(undefined4 *)(puVar3 + 6));
    }
  }
  FUN_004659fc(iVar2);
LAB_0041d2d2:
  FUN_004131cb();
  return;
}

