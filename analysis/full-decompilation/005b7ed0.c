
void FUN_005b7ed0(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  
  if (DAT_006fd8ec == 0) {
    DAT_006fd8ec = 1;
    puVar3 = &DAT_006d24b0;
    do {
      puVar1 = puVar3 + 3;
      *puVar3 = *puVar3 & 0xfffffffe;
      puVar3 = puVar1;
    } while ((int)puVar1 < 0x6d2510);
    puVar3 = &DAT_006d229c;
    do {
      puVar1 = puVar3 + 2;
      *puVar3 = *puVar3 & 0xfffffffe;
      puVar3 = puVar1;
    } while ((int)puVar1 < 0x6d249c);
    puVar2 = &DAT_006d24dc;
    do {
      puVar2[-1] = 0;
      *puVar2 = 0;
      puVar2 = puVar2 + 3;
    } while ((int)puVar2 < 0x6d250c);
    puVar3 = &DAT_006d231c;
    do {
      puVar3[-1] = 0;
      *puVar3 = *puVar3 & 0xfffffffd;
      puVar3 = puVar3 + 2;
    } while ((int)puVar3 < 0x6d249c);
    FUN_005b82c0(2,1);
    FUN_005b8000(1,1);
  }
  return;
}

