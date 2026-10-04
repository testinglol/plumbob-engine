
undefined4 FUN_005a93b0(size_t param_1)

{
  undefined4 uVar1;
  
  FUN_005b66f0(FUN_005a9410);
  DAT_006f779c = _malloc(param_1);
  if (DAT_006f779c != (void *)0x0) {
    uVar1 = FUN_005a9360(DAT_006f779c,param_1);
    *(void **)(DAT_00703ea0 + 0x40) = DAT_006f779c;
    return uVar1;
  }
  return 0;
}

