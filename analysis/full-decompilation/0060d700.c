
int FUN_0060d700(byte *param_1,int param_2,uint param_3,short param_4,int param_5,uint param_6,
                short param_7,int param_8,int param_9,ushort param_10,int param_11)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  ushort uVar16;
  int iVar17;
  int iVar18;
  undefined1 *puVar19;
  int local_20;
  int local_1c;
  int local_18;
  
  pbVar5 = param_1;
  param_3 = param_3 & 0xffff;
  iVar6 = (int)param_4 * param_3;
  uVar16 = param_10 >> 1;
  iVar7 = iVar6 - param_3;
  if ((((param_10 < 0x80) || (param_8 < 2)) || (param_9 < 0x40)) || ((param_4 < 2 || (param_7 < 2)))
     ) {
    iVar10 = 0;
  }
  else {
    uVar8 = (uint)param_10;
    iVar9 = (int)(uVar8 << 10) / (param_9 * 2);
    if (param_8 < 0x400) {
      iVar9 = (int)(iVar9 * param_8 + (iVar9 * param_8 >> 0x1f & 0x3ffU)) >> 10;
    }
    iVar10 = (param_4 + -1) * param_8;
    iVar10 = ((int)(iVar10 + (iVar10 >> 0x1f & 0x3ffU)) >> 10) + 1;
    if (param_7 < iVar10) {
      iVar10 = (int)param_7;
    }
    local_20 = 0;
    if (0 < iVar10) {
      local_1c = 0;
      do {
        uVar11 = (local_1c + (iVar10 * 0x200 + -0x200) * -0x400) / param_8 + param_2;
        uVar13 = uVar11 & 0x3ff;
        iVar17 = (int)uVar11 >> 10;
        if (uVar13 < 0x201) {
          iVar15 = -((int)(uVar13 * iVar9) >> 10);
        }
        else {
          iVar15 = (int)((0x400 - uVar13) * iVar9) >> 10;
          iVar17 = iVar17 + 1;
        }
        iVar15 = (uint)uVar16 + iVar15;
        iVar17 = param_3 * iVar17;
        iVar12 = 0;
        param_9 = 0;
        _param_4 = 0;
        _param_10 = 0;
        _param_7 = 0;
        if (-1 < iVar15) {
          param_1 = (byte *)(param_11 + iVar15 * 2);
          iVar18 = iVar17;
          local_18 = iVar15;
          do {
            iVar14 = (int)*(short *)param_1;
            param_9 = param_9 + iVar14;
            if (iVar18 < 0) {
              bVar1 = *pbVar5;
              bVar2 = pbVar5[1];
              bVar3 = pbVar5[2];
              bVar4 = pbVar5[3];
            }
            else {
              bVar1 = pbVar5[iVar18];
              bVar2 = pbVar5[iVar18 + 1];
              bVar3 = pbVar5[iVar18 + 2];
              bVar4 = pbVar5[iVar18 + 3];
            }
            _param_10 = _param_10 + (uint)bVar2 * iVar14;
            _param_7 = _param_7 + (uint)bVar3 * iVar14;
            iVar12 = iVar12 + (uint)bVar1 * iVar14;
            _param_4 = _param_4 + (uint)bVar4 * iVar14;
            local_18 = local_18 - iVar9;
            param_1 = (byte *)((int)param_1 + -iVar9 * 2);
            iVar18 = iVar18 - param_3;
          } while (-1 < local_18);
        }
        iVar15 = iVar9 + iVar15;
        if (iVar15 < (int)uVar8) {
          param_1 = (byte *)(param_11 + iVar15 * 2);
          do {
            iVar17 = param_3 + iVar17;
            iVar18 = (int)*(short *)param_1;
            param_9 = param_9 + iVar18;
            if (iVar17 < iVar6) {
              bVar1 = pbVar5[iVar17];
              bVar2 = pbVar5[iVar17 + 1];
              bVar3 = pbVar5[iVar17 + 2];
              bVar4 = pbVar5[iVar17 + 3];
            }
            else {
              bVar1 = pbVar5[iVar7];
              bVar2 = pbVar5[iVar7 + 1];
              bVar3 = pbVar5[iVar7 + 2];
              bVar4 = pbVar5[iVar7 + 3];
            }
            _param_10 = _param_10 + (uint)bVar2 * iVar18;
            _param_7 = _param_7 + (uint)bVar3 * iVar18;
            iVar12 = iVar12 + (uint)bVar1 * iVar18;
            _param_4 = _param_4 + (uint)bVar4 * iVar18;
            iVar15 = iVar15 + iVar9;
            param_1 = (byte *)((int)param_1 + iVar9 * 2);
          } while (iVar15 < (int)uVar8);
        }
        iVar12 = iVar12 + 0x200;
        if (param_9 != 0) {
          iVar12 = iVar12 / param_9;
        }
        if (iVar12 < 0) {
          iVar12 = 0;
        }
        else if (0xff < iVar12) {
          iVar12 = 0xff;
        }
        puVar19 = (undefined1 *)(param_5 + (param_6 & 0xffff) * local_20);
        _param_10 = _param_10 + 0x200;
        *puVar19 = (char)iVar12;
        if (param_9 != 0) {
          _param_10 = _param_10 / param_9;
        }
        if (_param_10 < 0) {
          _param_10 = 0;
        }
        else if (0xff < _param_10) {
          _param_10 = 0xff;
        }
        _param_7 = _param_7 + 0x200;
        puVar19[1] = (char)_param_10;
        if (param_9 != 0) {
          _param_7 = _param_7 / param_9;
        }
        if (_param_7 < 0) {
          _param_7 = 0;
        }
        else if (0xff < _param_7) {
          _param_7 = 0xff;
        }
        _param_4 = _param_4 + 0x200;
        puVar19[2] = (char)_param_7;
        if (param_9 != 0) {
          _param_4 = _param_4 / param_9;
        }
        if (_param_4 < 0) {
          _param_4 = 0;
        }
        else if (0xff < _param_4) {
          _param_4 = 0xff;
        }
        local_20 = local_20 + 1;
        local_1c = local_1c + 0x100000;
        puVar19[3] = (char)_param_4;
      } while (local_20 < iVar10);
      return iVar10;
    }
  }
  return iVar10;
}

