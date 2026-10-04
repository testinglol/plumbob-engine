
undefined4 __fastcall FUN_005998b7(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_005b9095(param_1);
  if ((((cVar1 != '\0') && (cVar1 = FUN_005b9095(param_1 + 4), cVar1 != '\0')) &&
      (cVar1 = FUN_005b9095(param_1 + 8), cVar1 != '\0')) &&
     ((cVar1 = FUN_005b9095(param_1 + 0xc), cVar1 != '\0' &&
      (cVar1 = FUN_005b9095(param_1 + 0x10), cVar1 != '\0')))) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    return 1;
  }
  return 0;
}

