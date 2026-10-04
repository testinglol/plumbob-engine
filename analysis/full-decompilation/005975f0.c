
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005975f0(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_8;
  
  if (DAT_006f75f0 == 0) {
    DAT_006f75f0 = 1;
    puVar4 = &DAT_006f6d44;
    for (iVar3 = 0xfd; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    _DAT_006f75f8 = 0x3727c5ac;
    _DAT_006f75fc = 0x358637bd;
    local_8 = 0;
    do {
      fVar1 = ((float)local_8 * _DAT_006720e4 + (float)local_8 * _DAT_006720e4) -
              (float)_DAT_00667280;
      if ((float)_DAT_006669e8 <= fVar1) {
        fVar2 = 1.0;
      }
      else {
        fVar2 = (float)_DAT_00671740;
      }
      iVar3 = local_8 + 1;
      *(float *)(&DAT_006f7138 + local_8 * 4) =
           fVar2 * fVar1 * fVar1 * fVar1 * fVar1 * _DAT_00666a38;
      local_8 = iVar3;
    } while (iVar3 < 0xfd);
    _DAT_006f75f4 = 0;
    _DAT_006f7600 = 0;
    _DAT_006f7604 = 0;
    _DAT_006f7608 = 0;
    _DAT_006f760c = 0;
    _DAT_006f7610 = 0;
    _DAT_006f7614 = 0;
    _DAT_006f7618 = 0;
    _DAT_006f761c = 0;
    _DAT_006f7620 = 0;
    _DAT_006f7624 = 0;
    _DAT_006f7628 = 0;
  }
  return;
}

