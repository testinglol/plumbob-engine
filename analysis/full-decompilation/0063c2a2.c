
size_t FUN_0063c2a2(byte *param_1)

{
  size_t sVar1;
  
  if (DAT_0070513c == 0) {
    sVar1 = _strlen((char *)param_1);
    return sVar1;
  }
  FUN_0063d88b(0x19);
  sVar1 = 0;
  for (; (*param_1 != 0 &&
         (((*(byte *)((int)&DAT_00705240 + *param_1 + 1) & 4) == 0 ||
          (param_1 = param_1 + 1, *param_1 != 0)))); param_1 = param_1 + 1) {
    sVar1 = sVar1 + 1;
  }
  FUN_0063d8ec(0x19);
  return sVar1;
}

