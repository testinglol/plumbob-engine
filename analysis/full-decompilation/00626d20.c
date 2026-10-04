
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00626d20(uint param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,uint param_7,int param_8,int param_9)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte bVar9;
  uint uVar11;
  int iVar12;
  byte bVar13;
  uint uVar14;
  undefined1 local_24;
  uint uVar10;
  
  uVar2 = param_1;
  bVar9 = param_1._2_1_;
  uVar10 = (uint)param_1._2_1_;
  uVar11 = param_1 >> 8 & 0xff;
  uVar3 = param_1 & 0xff;
  uVar14 = param_1 >> 0x18;
  uVar4 = __ftol();
  iVar5 = __ftol();
  iVar6 = __ftol();
  uVar7 = __ftol();
  if (*(int *)(param_8 + 0x18) != 0x20) {
    switch(param_4) {
    case 1:
      if (param_3 == 0) {
        return param_1;
      }
      break;
    case 2:
      return param_1 - param_2 & 0xff;
    case 3:
      return param_1 + param_2 & 0xff;
    case 4:
      return param_1 - param_2 & ((int)(param_1 - param_2) < 0) - 1;
    default:
      if (param_3 == 0) {
        return param_1;
      }
      if (*(byte *)(param_9 + 0x2b + (param_2 & 0xff) * 4) < *(byte *)(param_8 + 0x2b + uVar3 * 4))
      {
        return param_1;
      }
    }
    return param_2;
  }
  bVar1 = (byte)(param_1 >> 8);
  bVar13 = bVar1;
  param_1 = uVar14;
  param_2._0_1_ = bVar9;
  switch(param_4) {
  case 1:
    if (param_3 != 0) {
      param_2._0_1_ = (byte)iVar5;
      uVar3 = uVar7;
      bVar13 = (byte)iVar6;
      param_1 = uVar4;
    }
    break;
  case 2:
    goto LAB_00626f7e;
  case 3:
    param_2 = 0xff;
    if ((int)(iVar5 + uVar10) < 0x100) {
      param_2 = iVar5 + uVar10;
    }
    iVar5 = 0xff;
    if ((int)(iVar6 + uVar11) < 0x100) {
      iVar5 = iVar6 + uVar11;
    }
    uVar3 = uVar7 + uVar3;
    bVar13 = (byte)iVar5;
    if (0xff < (int)uVar3) {
      uVar3 = 0xff;
    }
    break;
  case 4:
    param_1 = ((int)(uVar14 - uVar4) < 0) - 1 & uVar14 - uVar4;
LAB_00626f7e:
    param_2._0_1_ = ((int)(uVar10 - iVar5) < 0) - 1U & (byte)(uVar10 - iVar5);
    uVar3 = ((int)(uVar3 - uVar7) < 0) - 1 & uVar3 - uVar7;
    bVar13 = ((int)(uVar11 - iVar6) < 0) - 1U & (byte)(uVar11 - iVar6);
    break;
  case 5:
    iVar12 = uVar14 - uVar4;
    if (iVar12 < 0) {
      param_1 = 0x80 - iVar12 * iVar12;
      if ((int)param_1 < 0x100) {
        if (-1 < (int)param_1) goto joined_r0x00627071;
        param_1 = 0;
        goto LAB_00627078;
      }
LAB_00627073:
      param_1 = 0xff;
    }
    else {
      param_1 = iVar12 * iVar12 + 0x80;
      if (0xff < (int)param_1) goto LAB_00627073;
      if ((int)param_1 < 0) {
        param_1 = 0;
      }
      else {
joined_r0x00627071:
        if (0xff < (int)param_1) goto LAB_00627073;
      }
    }
LAB_00627078:
    iVar5 = uVar10 - iVar5;
    if (iVar5 < 0) {
      iVar8 = 0x80 - iVar5 * iVar5;
      if (iVar8 < 0x100) {
        if (-1 < iVar8) goto joined_r0x006270c6;
        param_2._0_1_ = 0;
        goto LAB_006270cd;
      }
LAB_006270c8:
      param_2._0_1_ = 0xff;
    }
    else {
      iVar8 = iVar5 * iVar5 + 0x80;
      if (0xff < iVar8) goto LAB_006270c8;
      if (iVar8 < 0) {
        param_2._0_1_ = 0;
      }
      else {
joined_r0x006270c6:
        param_2._0_1_ = (byte)iVar8;
        if (0xff < iVar8) goto LAB_006270c8;
      }
    }
LAB_006270cd:
    iVar6 = uVar11 - iVar6;
    if (iVar6 < 0) {
      iVar8 = 0x80 - iVar6 * iVar6;
      if (iVar8 < 0x100) {
        if (-1 < iVar8) goto joined_r0x0062711b;
        bVar13 = 0;
        goto LAB_00627122;
      }
LAB_0062711d:
      bVar13 = 0xff;
    }
    else {
      iVar8 = iVar6 * iVar6 + 0x80;
      if (0xff < iVar8) goto LAB_0062711d;
      if (iVar8 < 0) {
        bVar13 = 0;
      }
      else {
joined_r0x0062711b:
        bVar13 = (byte)iVar8;
        if (0xff < iVar8) goto LAB_0062711d;
      }
    }
LAB_00627122:
    iVar8 = uVar3 - uVar7;
    if (iVar8 < 0) {
      uVar3 = 0x80 - iVar8 * iVar8;
      if ((int)uVar3 < 0x100) {
        if (-1 < (int)uVar3) goto joined_r0x00627170;
        uVar3 = 0;
        goto LAB_00627177;
      }
LAB_00627172:
      uVar3 = 0xff;
    }
    else {
      uVar3 = iVar8 * iVar8 + 0x80;
      if (0xff < (int)uVar3) goto LAB_00627172;
      if ((int)uVar3 < 0) {
        uVar3 = 0;
      }
      else {
joined_r0x00627170:
        if (0xff < (int)uVar3) goto LAB_00627172;
      }
    }
LAB_00627177:
    _DAT_00703fd0 =
         (double)(iVar12 * iVar12 + iVar8 * iVar8 + iVar6 * iVar6 + iVar5 * iVar5) + _DAT_00703fd0;
    break;
  case 6:
    param_1 = uVar4;
    if ((int)uVar4 <= (int)uVar14) {
      param_1 = uVar14;
    }
    iVar12 = 0xff - uVar4;
    iVar5 = iVar5 + (int)(iVar12 * uVar10) / 0xff;
    param_2 = 0xff;
    if (iVar5 < 0x100) {
      param_2 = iVar5;
    }
    iVar6 = iVar6 + (int)(iVar12 * uVar11) / 0xff;
    iVar5 = 0xff;
    if (iVar6 < 0x100) {
      iVar5 = iVar6;
    }
    uVar3 = (int)(iVar12 * uVar3) / 0xff + uVar7;
    bVar13 = (byte)iVar5;
    if (0xff < (int)uVar3) {
      uVar3 = 0xff;
    }
    break;
  case 7:
    if (param_3 == 0) break;
    param_1 = uVar4;
    if ((int)uVar4 <= (int)uVar14) {
      param_1 = uVar14;
    }
    iVar12 = 0xff - uVar4;
    param_2._0_1_ =
         (char)((int)(iVar12 * uVar10) / 0xff) +
         (char)((int)(((int)(iVar5 * uVar10) / 0xff) * uVar4) / 0xff);
    bVar13 = (char)((int)(iVar12 * uVar11) / 0xff) +
             (char)((int)(((int)(iVar6 * uVar11) / 0xff) * uVar4) / 0xff);
    iVar5 = (int)(uVar7 * uVar3) / 0xff;
    goto code_r0x00627506;
  case 8:
    if (param_3 == 0) break;
    param_1 = uVar4;
    if ((int)uVar4 <= (int)uVar14) {
      param_1 = uVar14;
    }
    iVar12 = 0xff - uVar4;
    param_2._0_1_ =
         (char)((int)(iVar12 * uVar10) / 0xff) +
         (char)((int)((0xff - (int)((0xff - iVar5) * (0xff - uVar10)) / 0xff) * uVar4) / 0xff);
    bVar13 = (char)((int)(iVar12 * uVar11) / 0xff) +
             (char)((int)((0xff - (int)((0xff - iVar6) * (0xff - uVar11)) / 0xff) * uVar4) / 0xff);
    iVar5 = 0xff - (int)((0xff - uVar7) * (0xff - uVar3)) / 0xff;
    goto code_r0x00627506;
  case 9:
    if (param_3 == 0) break;
    param_1 = uVar4;
    if ((int)uVar4 <= (int)uVar14) {
      param_1 = uVar14;
    }
    iVar12 = 0xff - uVar4;
    iVar5 = func_0x00627730(iVar5,uVar10);
    param_2._0_1_ = (char)((int)(iVar12 * uVar10) / 0xff) + (char)((int)(iVar5 * uVar4) / 0xff);
    iVar5 = func_0x00627730(iVar6,uVar11);
    bVar13 = (char)((int)(iVar12 * uVar11) / 0xff) + (char)((int)(iVar5 * uVar4) / 0xff);
    iVar5 = func_0x00627730(uVar7,uVar3);
code_r0x00627506:
    uVar3 = (int)(iVar12 * uVar3) / 0xff + (int)(iVar5 * uVar4) / 0xff;
    break;
  default:
    param_1 = uVar4;
    if ((int)uVar4 <= (int)uVar14) {
      param_1 = uVar14;
    }
    iVar12 = 0xff - uVar4;
    iVar5 = (int)(iVar12 * uVar10 + iVar5 * uVar4) / 0xff;
    param_2 = 0xff;
    if (iVar5 < 0x100) {
      param_2 = iVar5;
    }
    iVar5 = (int)(iVar12 * uVar11 + iVar6 * uVar4) / 0xff;
    iVar6 = 0xff;
    if (iVar5 < 0x100) {
      iVar6 = iVar5;
    }
    uVar3 = (int)(iVar12 * uVar3 + uVar7 * uVar4) / 0xff;
    bVar13 = (byte)iVar6;
    if (0xff < (int)uVar3) {
      uVar3 = 0xff;
    }
  }
  local_24 = (undefined1)uVar3;
  if (param_7 >> 0x18 == 0) {
    param_1._0_1_ = (undefined1)(uVar2 >> 0x18);
  }
  if ((param_7 >> 0x10 & 0xff) != 0) {
    bVar9 = (byte)param_2;
  }
  if ((param_7 >> 8 & 0xff) != 0) {
    bVar1 = bVar13;
  }
  if ((param_7 & 0xff) == 0) {
    local_24 = (undefined1)uVar2;
  }
  return CONCAT31(CONCAT21(CONCAT11((undefined1)param_1,bVar9),bVar1),local_24);
}

