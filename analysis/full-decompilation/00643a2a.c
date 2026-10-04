
void FUN_00643a2a(void)

{
  size_t sVar1;
  
  sVar1 = _strlen(DAT_00703c38);
  DAT_00703c34 = (uint)(sVar1 == 3);
  if (sVar1 == 3) {
    DAT_00703c30 = 2;
  }
  else {
    DAT_00703c30 = FUN_00643e50(DAT_00703c38);
  }
  EnumSystemLocalesA(FUN_00643a80,1);
  if ((DAT_00703c40 & 4) == 0) {
    DAT_00703c40 = 0;
  }
  return;
}

