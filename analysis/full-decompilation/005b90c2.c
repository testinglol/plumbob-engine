
undefined4 FUN_005b90c2(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint local_c;
  byte local_5;
  
  iVar2 = FUN_005b8e6a(&local_5,1);
  if (iVar2 == 1) {
    if (local_5 == 0xff) {
      FUN_005b8e6a(&local_c,4);
    }
    else {
      local_c = (uint)local_5;
    }
    uVar1 = local_c;
    uVar3 = FUN_005b8e6a(param_1,local_c);
    if (uVar3 == uVar1) {
      *(undefined1 *)(local_c + param_1) = 0;
      return 1;
    }
  }
  return 0;
}

