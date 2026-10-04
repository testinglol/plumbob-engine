
void FUN_004b8b89(int param_1,uint param_2,byte *param_3,byte param_4)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint local_14;
  uint local_c;
  uint local_8;
  
  pbVar1 = param_3;
  uVar8 = 0x10 << (param_4 & 0x1f);
  local_c = uVar8;
  if ((int)DAT_006f0bc6 < (int)(uVar8 + param_1)) {
    local_c = DAT_006f0bc6 - param_1 & 0xfffc;
  }
  if (param_1 < DAT_006f0bc2) {
    local_8 = (DAT_006f0bc2 - param_1) + 3U & 0xfffc;
  }
  else {
    local_8 = 0;
  }
  iVar2 = ((uint)param_3[1] - (uint)param_3[3]) + 4;
  uVar10 = (uint)*param_3;
  iVar5 = (param_3[1] - uVar10) + 2;
  param_3 = (byte *)(((local_8 / 4) * iVar2 - (uint)param_3[3]) + 2 + uVar10);
  bVar4 = param_4 + 1;
  local_14 = local_c;
  uVar3 = 8 << (param_4 & 0x1f);
  iVar11 = (((int)local_8 / -4) * iVar5 - (uVar10 << (bVar4 & 0x1f))) + param_2;
  uVar10 = local_8;
  if ((int)uVar3 < (int)local_c) {
    local_14 = uVar3;
  }
  for (; (int)uVar10 < (int)local_14; uVar10 = uVar10 + 4) {
    iVar6 = (int)DAT_006f0bc0;
    iVar7 = (int)param_3;
    _param_4 = iVar11;
    if (iVar11 < iVar6) {
      iVar7 = (iVar11 - iVar6) + (int)param_3;
      _param_4 = iVar6;
    }
    if ((int)DAT_006f0bc4 < _param_4 + iVar7) {
      iVar7 = DAT_006f0bc4 - _param_4;
    }
    FUN_004b8af8(param_1 + uVar10,_param_4,iVar7,_param_4 - iVar11);
    iVar11 = iVar11 - iVar5;
    param_3 = (byte *)((int)param_3 + iVar2);
  }
  uVar10 = (uint)pbVar1[2];
  iVar11 = (pbVar1[1] - uVar10) + 2;
  iVar5 = (((int)(uVar8 - local_c) / 4) * iVar2 - (uint)pbVar1[3]) + 2 + uVar10;
  _param_4 = (param_2 - ((int)(uVar8 - local_c) / 4) * iVar11) - (uVar10 << (bVar4 & 0x1f));
  if ((int)local_8 < (int)uVar3) {
    local_8 = uVar3;
  }
  iVar7 = local_c - 4;
  if ((int)local_8 <= iVar7) {
    param_1 = param_1 + iVar7;
    param_2 = (iVar7 - local_8) + 4 >> 2;
    do {
      iVar9 = (int)DAT_006f0bc0;
      iVar7 = iVar5;
      iVar6 = _param_4;
      if (_param_4 < iVar9) {
        iVar7 = (_param_4 - iVar9) + iVar5;
        iVar6 = iVar9;
      }
      if ((int)DAT_006f0bc4 < iVar7 + iVar6) {
        iVar7 = DAT_006f0bc4 - iVar6;
      }
      FUN_004b8af8(param_1,iVar6,iVar7,iVar6 - _param_4);
      _param_4 = _param_4 - iVar11;
      iVar5 = iVar5 + iVar2;
      param_1 = param_1 + -4;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return;
}

