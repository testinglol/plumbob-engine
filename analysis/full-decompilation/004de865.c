
int __thiscall FUN_004de865(int param_1,undefined4 *param_2,char *param_3)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  undefined **local_118;
  char *local_114;
  undefined1 local_10c [260];
  undefined4 local_8;
  
  FUN_0046f824(param_1 + 0x154,0,0x104);
  *(undefined ***)(param_1 + 0x148) = &PTR_FUN_006664e8;
  FUN_0046f824(param_1 + 0x268,0,0x104);
  *(undefined ***)(param_1 + 0x25c) = &PTR_FUN_006664e8;
  *(undefined4 *)(param_1 + 0x140) = 0;
  local_8 = param_2[1];
  uVar1 = (**(code **)*param_2)();
  FUN_0046fb9b(local_10c,0x104);
  local_118 = &PTR_LAB_00666cdc;
  FUN_0046f847(local_8,uVar1);
  iVar2 = (**(code **)*param_2)();
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      if (local_114[iVar4] == '/') {
        local_114[iVar4] = '\\';
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  sVar3 = _strlen(local_114);
  if (local_114[sVar3 - 1] != '\\') {
    FUN_0046fa24(0x5c);
  }
  FUN_0046f8e4(&local_118);
  if (param_3 == (char *)0x0) {
    *(undefined1 *)(param_1 + 600) = 0;
  }
  else {
    _strncpy((char *)(param_1 + 600),param_3,4);
  }
  *(undefined1 *)(param_1 + 0x144) = 0;
  FUN_004de998();
  return param_1;
}

