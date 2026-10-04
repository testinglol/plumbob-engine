
uint FUN_004ec5aa(int param_1,undefined4 param_2)

{
  uint in_EAX;
  int iVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_0043acf5(param_1);
    in_EAX = 0;
    if ((iVar1 != 0) && (in_EAX = 0, *(int *)(iVar1 + 0x84) != 0)) {
      FUN_004ccc2f(param_2);
      uVar2 = FUN_005a5e72();
      return uVar2;
    }
  }
  return in_EAX & 0xffffff00;
}

