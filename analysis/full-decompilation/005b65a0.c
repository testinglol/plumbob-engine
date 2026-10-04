
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005b65a0(void)

{
  float fVar1;
  int iVar2;
  int local_14;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  local_14 = 0;
  do {
    FUN_005b6e50(1);
    FUN_005b6db0();
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
    } while (0 < DAT_006d21f0 >> 2);
    if (local_14 != 0) {
      if ((iVar2 < local_c) || (local_c == 0)) {
        local_8 = local_c;
        local_c = iVar2;
      }
      else if ((iVar2 < local_8) || (local_8 == 0)) {
        local_8 = iVar2;
      }
    }
    local_14 = local_14 + 1;
  } while (local_14 < 5);
  if (local_8 == 0) {
    local_8 = local_c;
  }
  fVar1 = (float)(local_8 << 2);
  if (DAT_006d21e0 == 0) {
    if (DAT_006d21b4 == 0) {
      if (DAT_006d21cc == 0) {
        if (DAT_006d21dc == 0) {
          fVar1 = fVar1 * _DAT_006723b4;
        }
        else {
          fVar1 = fVar1 * _DAT_006723b8;
        }
      }
      else {
        fVar1 = fVar1 * _DAT_006723bc;
      }
    }
    else {
      fVar1 = fVar1 * _DAT_006723c0;
    }
  }
  else {
    fVar1 = fVar1 * _DAT_006723c4;
  }
  return (int)ROUND(fVar1 * _DAT_006723b0);
}

