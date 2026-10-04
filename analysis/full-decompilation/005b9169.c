
uint __thiscall FUN_005b9169(size_t param_1,char *param_2)

{
  uint uVar1;
  size_t sVar2;
  size_t sVar3;
  bool bVar4;
  size_t local_c;
  undefined4 uStack_8;
  
  sVar3 = 0;
  local_c = param_1;
  uStack_8 = param_1;
  if ((param_2 == (char *)0x0) || (sVar3 = _strlen(param_2), (int)sVar3 < 0xff)) {
    uStack_8 = CONCAT13((char)sVar3,(undefined3)uStack_8);
    uVar1 = FUN_005b8f0f((int)&uStack_8 + 3,1);
    bVar4 = uVar1 == 1;
  }
  else {
    uStack_8 = CONCAT13(0xff,(undefined3)uStack_8);
    uVar1 = FUN_005b8f0f((int)&uStack_8 + 3,1);
    if (uVar1 != 1) goto LAB_005b91cc;
    local_c = sVar3;
    uVar1 = FUN_005b8f0f(&local_c,4);
    bVar4 = uVar1 == 4;
  }
  if (bVar4) {
    sVar2 = FUN_005b8f0f(param_2,sVar3);
    return (uint)(sVar2 == sVar3);
  }
LAB_005b91cc:
  return uVar1 & 0xffffff00;
}

