
undefined4 FUN_004cff80(void)

{
  char cVar1;
  
  cVar1 = *(char *)(DAT_006e486c + 100);
  if ((((cVar1 != '\x0f') && (cVar1 != '\x11')) && (cVar1 != '\x12')) &&
     ((cVar1 != '\x14' && (cVar1 != '\x13')))) {
    return 0;
  }
  return 1;
}

