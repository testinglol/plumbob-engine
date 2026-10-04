
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00416847(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)*(int *)(*(int *)(*DAT_006e486c + 0x20) + 0xa0);
  fVar2 = _DAT_0066674c;
  if (fVar1 != _DAT_0066657c) {
    fVar2 = (float)*(int *)(*(int *)(*DAT_006e486c + 0x20) + 0xa4) / fVar1;
  }
  FUN_004167d4(fVar2);
  __ftol();
  return;
}

