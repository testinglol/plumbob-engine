
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_00403515(int param_1)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  fVar1 = (float)param_1;
  if (_DAT_00666528 <= fVar1) {
    if (_DAT_0066652c <= fVar1) {
      if (_DAT_00666530 <= fVar1) {
        if (_DAT_00666534 <= fVar1) {
          iVar4 = 5;
        }
        else {
          iVar4 = 4;
        }
      }
      else {
        iVar4 = 3;
      }
    }
    else {
      iVar4 = 2;
    }
  }
  else {
    iVar4 = 1;
  }
  iVar2 = FUN_0046fbe5(0xffffffff);
  if (iVar2 < iVar4) {
    puVar3 = &DAT_006de560;
  }
  else {
    puVar3 = (undefined1 *)FUN_004705f2(iVar4,0xffffffff);
  }
  return puVar3;
}

