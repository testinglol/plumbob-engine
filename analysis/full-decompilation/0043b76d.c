
void FUN_0043b76d(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  size_t sVar3;
  int iVar4;
  undefined **local_114;
  char *local_110;
  undefined1 local_108 [260];
  
  uVar1 = param_1[1];
  uVar2 = (**(code **)*param_1)();
  FUN_0046fb9b(local_108,0x104);
  local_114 = &PTR_LAB_00666cdc;
  FUN_0046f847(uVar1,uVar2);
  sVar3 = _strlen(local_110);
  iVar4 = 0;
  if (0 < (int)sVar3) {
    do {
      if (local_110[iVar4] == '/') {
        local_110[iVar4] = '\\';
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)sVar3);
  }
  FUN_0046f8e4(&local_114);
  return;
}

