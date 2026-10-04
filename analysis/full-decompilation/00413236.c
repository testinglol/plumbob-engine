
int __thiscall FUN_00413236(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined **local_110 [3];
  undefined1 local_104 [256];
  
  FUN_0046f824(local_104,0,0x100);
  local_110[0] = &PTR_FUN_00666524;
  FUN_0046f847(param_2,0xffffffff);
  iVar2 = *param_1;
  if (iVar2 != param_1[1]) {
    do {
      iVar1 = FUN_0046f973(local_110);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 0x15c;
    } while (iVar2 != param_1[1]);
  }
  return 0;
}

