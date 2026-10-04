
void __thiscall FUN_0041d01e(int *param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  undefined4 local_5c;
  int local_58;
  undefined2 local_54;
  undefined2 local_52;
  char local_50 [63];
  undefined1 local_11;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 == '\0') {
    uVar5 = 0xffffffcf;
  }
  else {
    uVar5 = 0;
  }
  FUN_004659fc(uVar5);
  iVar3 = FUN_00401f6f();
  if (iVar3 != 0) {
    return;
  }
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 == '\0') {
    iVar3 = -0x31;
    goto LAB_0041d159;
  }
  cVar2 = (**(code **)(*param_1 + 0x20))();
  if (cVar2 == '\0') {
    iVar3 = -0x2d;
    goto LAB_0041d159;
  }
  puVar4 = (undefined2 *)FUN_0041bb9f(param_2,&local_10);
  if (puVar4 == (undefined2 *)0x0) {
    iVar3 = -99;
    goto LAB_0041d159;
  }
  FUN_004659fc(0);
  local_8 = FUN_00420096(param_2);
  piVar1 = (int *)(puVar4 + 6);
  if (*piVar1 == -1) {
LAB_0041d0cd:
    FUN_0041d43f(&local_5c,local_8,piVar1);
  }
  else {
    FUN_0041a545(&local_5c,*piVar1);
    if (local_58 != local_8 + 0x4c) {
      FUN_0041d3ff(*piVar1);
      goto LAB_0041d0cd;
    }
  }
  local_5c = local_10;
  local_54 = *puVar4;
  local_52 = puVar4[1];
  _strncpy(local_50,*(char **)(puVar4 + 10),0x3f);
  local_11 = 0;
  iVar3 = FUN_0041d5fe(&local_5c,*piVar1);
  if ((iVar3 == 0) && (iVar3 = FUN_004131a0(*piVar1 + 0x4c), iVar3 == 0)) {
    uVar5 = FUN_00420048(param_2);
    local_c = FUN_00412f9f(uVar5,&local_8);
    FUN_0042004f(param_2);
    iVar3 = local_c;
    if (local_c == 0) {
      puVar4[2] = puVar4[1];
      FUN_004131cb();
      return;
    }
  }
LAB_0041d159:
  FUN_004659fc(iVar3);
  return;
}

