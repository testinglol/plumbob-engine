
uint __thiscall FUN_004cc832(int param_1,int param_2)

{
  char cVar1;
  uint in_EAX;
  uint uVar2;
  
  if ((param_2 == 2) || (param_2 == 3)) {
    cVar1 = FUN_005a5e72();
    if (cVar1 == '\0') {
      FUN_004cc548();
    }
    FUN_005a5e1c(param_1 + 0x28 + param_2 * 4);
    uVar2 = FUN_005a5e72();
  }
  else {
    uVar2 = in_EAX & 0xffffff00;
  }
  return uVar2;
}

