
int __fastcall FUN_005d1318(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_c;
  char local_5;
  
  local_5 = (*(byte *)(param_1 + 0x31) & 1) == 0;
  if ((bool)local_5) {
    param_1[0x31] = param_1[0x31] | 1;
  }
  uVar1 = FUN_005c5910();
  if (uVar1 == 0) {
    iVar3 = FUN_005cfd67(&local_c,s_default_006c0a4c);
    if (iVar3 != 0) {
      return iVar3;
    }
    FUN_005d13cd(0,local_c);
  }
  else {
    uVar4 = 0;
    if (uVar1 != 0) {
      do {
        uVar2 = FUN_005c5920(uVar4);
        iVar3 = FUN_005cfd67(&local_c,uVar2);
        if ((iVar3 != 0) && (iVar3 = FUN_005cfd67(&local_c,s_Flesh_006d638c), iVar3 != 0)) {
          return iVar3;
        }
        FUN_005d13cd(uVar4,local_c);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
  }
  if (local_5 == '\0') {
    iVar3 = 0;
  }
  else {
    iVar3 = (**(code **)(*param_1 + 0x28))(0);
  }
  return iVar3;
}

