
void FUN_0064379f(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_00703c38);
  DAT_00703c34 = (uint)(sVar1 == 3);
  sVar1 = _strlen(DAT_00703c3c);
  DAT_00703c2c = (uint)(sVar1 == 3);
  DAT_00703c28 = 0;
  if (DAT_00703c34 == 0) {
    DAT_00703c30 = FUN_00643e50(DAT_00703c38);
  }
  else {
    DAT_00703c30 = 2;
  }
  EnumSystemLocalesA(FUN_00643826,1);
  if ((((DAT_00703c40 & 0x100) == 0) || ((DAT_00703c40 & 0x200) == 0)) || ((DAT_00703c40 & 7) == 0))
  {
    DAT_00703c40 = 0;
  }
  return;
}

