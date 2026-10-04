
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0049bd68(uint param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  float *pfVar6;
  int iVar7;
  float local_1c [4];
  float local_c;
  undefined4 uStack_8;
  
  fVar1 = (float)(param_1 >> 0x10 & 0xff) * _DAT_00667664;
  uStack_8 = 0;
  fVar2 = (float)(param_1 >> 8 & 0xff) * _DAT_00667664;
  fVar3 = _DAT_00667664 * (float)(param_1 & 0xff);
  local_1c[3] = fVar3 * (float)_DAT_00668378 +
                fVar1 * (float)_DAT_00668380 + fVar2 * (float)_DAT_00668388;
  local_c = fVar3 * (float)_DAT_00668370 -
            (fVar2 * (float)_DAT_00668360 + fVar1 * (float)_DAT_00668368);
  fVar1 = (fVar1 * (float)_DAT_00668358 - fVar2 * (float)_DAT_00668350) -
          fVar3 * (float)_DAT_00668348;
  param_3 = local_1c[3] * param_2 + param_3;
  local_1c[0] = fVar1 * (float)_DAT_00668340 + (param_3 - local_c * (float)_DAT_006678a0);
  local_1c[1] = (param_3 - local_c * (float)_DAT_00668338) - fVar1 * (float)_DAT_00668330;
  local_1c[2] = (param_3 + local_c * (float)_DAT_00668328) - fVar1 * (float)_DAT_00668320;
  pfVar6 = local_1c;
  iVar7 = 3;
  do {
    if (*pfVar6 < _DAT_0066657c) {
      *pfVar6 = 0.0;
    }
    if (_DAT_00666748 < *pfVar6) {
      *pfVar6 = 1.0;
    }
    pfVar6 = pfVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = __ftol();
  uVar4 = __ftol();
  uVar5 = __ftol();
  return uVar5 | (iVar7 << 8 | uVar4) << 8;
}

