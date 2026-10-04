
undefined1 FUN_0048b777(void)

{
  SHORT SVar1;
  SHORT SVar2;
  
  SVar1 = GetKeyState(0x10);
  SVar2 = GetKeyState(0x11);
  if (SVar1 < 0) {
    return 2;
  }
  return SVar2 < 0;
}

