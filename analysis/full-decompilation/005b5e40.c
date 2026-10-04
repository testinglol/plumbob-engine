
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005b5e40(float param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  float local_10;
  
  local_10 = 50.0;
  iVar3 = ((int)param_1 + 500000) / 1000000;
  if (iVar3 < 0x125) {
    local_10 = 75.0;
  }
  iVar1 = (int)ROUND((float)(int)ROUND((float)iVar3 * _DAT_00672344 + _DAT_00672340) * _DAT_0067233c
                    );
  iVar5 = (int)ROUND((float)(int)ROUND((float)iVar3 * _DAT_00672338 + _DAT_00672340) * _DAT_00672334
                    );
  iVar2 = (int)ROUND((float)(int)ROUND((float)iVar3 / local_10 + _DAT_00672340) * local_10);
  local_10 = (float)(iVar1 - iVar3) * _DAT_00672330;
  if (local_10 < (float)_DAT_00672328) {
    local_10 = local_10 * (float)_DAT_00672320;
  }
  param_1 = _DAT_00672294;
  if (0x188 < iVar3) {
    param_1 = _DAT_00672330;
  }
  param_1 = (float)(iVar5 - iVar3) * param_1;
  if (param_1 < (float)_DAT_00672328) {
    param_1 = param_1 * (float)_DAT_00672320;
  }
  fVar4 = _DAT_00672330;
  if (0x188 < iVar3) {
    fVar4 = _DAT_00672294;
  }
  fVar4 = fVar4 * (float)(iVar2 - iVar3);
  if (fVar4 < (float)_DAT_00672328) {
    fVar4 = fVar4 * (float)_DAT_00672320;
  }
  if (((local_10 < param_1) && (0x34 < iVar3)) && (iVar3 < 0xbc)) {
    iVar5 = iVar1;
    param_1 = local_10;
  }
  if (fVar4 < param_1) {
    iVar5 = iVar2;
  }
  return iVar5 * 1000000;
}

