
uint FUN_005b8420(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = 0xffffffff;
  iVar4 = 0;
  uVar3 = 0;
  do {
    if ((&PTR_PTR_006d2298)[uVar3 * 2] != (undefined *)0x0) {
      iVar1 = FUN_005b81e0((&PTR_PTR_006d2298)[uVar3 * 2],param_1);
      if (iVar4 < iVar1) {
        uVar2 = uVar3;
        iVar4 = iVar1;
      }
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x40);
  return uVar2;
}

