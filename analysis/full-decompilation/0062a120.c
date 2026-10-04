
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0062a120(int param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  float10 fVar8;
  float10 fVar9;
  undefined4 uVar10;
  int local_210;
  byte abStack_200 [512];
  
  bVar2 = *param_2;
  if ((0x40 < bVar2) && (*(int *)(param_1 + 0x200) < 0xb)) goto LAB_0062a4ce;
  pbVar5 = param_2 + 1;
  if (param_2[1] == 0) {
    bVar1 = bVar2 - 0x30;
    if (9 < bVar1) {
      bVar1 = (bVar2 | 0x20) + 0xa9;
    }
    if (bVar1 < *(byte *)(param_1 + 0x200)) {
      *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
      *(undefined4 *)(param_1 + 0x210) = 0;
      return (float10)bVar1;
    }
    if (*param_2 == 0x2a) {
      *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(param_1 + 0x238);
      *(undefined4 *)(param_1 + 0x210) = 0;
      return (float10)*(int *)(param_1 + 0x23c);
    }
    goto LAB_0062a4ce;
  }
  pbVar6 = pbVar5;
  if (bVar2 < 0x30) {
    local_210 = 0x10;
    if (bVar2 != 0x24) {
      switch(bVar2) {
      case 0:
        FUN_0061cf50(param_1,param_3,7);
        fVar8 = (float10)_DAT_006669e8;
        *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
        *(undefined4 *)(param_1 + 0x210) = 0;
        return fVar8;
      default:
        local_210 = 0;
        break;
      case 0x22:
      case 0x27:
        iVar4 = FUN_0062a780(param_1,abStack_200,param_2,param_3);
        if ((*(char *)(iVar4 + -1) == '\"') || (*(char *)(iVar4 + -1) == '\'')) {
          iVar4 = *(int *)(param_1 + 0x22c);
          if (8 < iVar4) {
            uVar10 = 10;
            goto LAB_0062a1cc;
          }
          pbVar5 = abStack_200;
          *(int *)(param_1 + 0x22c) = iVar4 + -1;
          if (iVar4 != 0) {
            fVar8 = (float10)0.0;
            iVar4 = iVar4 + -1;
            do {
              bVar2 = *pbVar5;
              pbVar5 = pbVar5 + 1;
              bVar7 = iVar4 != 0;
              fVar8 = (float10)bVar2 + fVar8 * (float10)_DAT_00677c88;
              *(int *)(param_1 + 0x22c) = iVar4 + -1;
              iVar4 = iVar4 + -1;
            } while (bVar7);
            goto LAB_0062a1da;
          }
        }
        else {
          uVar10 = 0x1b;
LAB_0062a1cc:
          FUN_0061cf50(param_1,param_3,uVar10);
        }
        fVar8 = (float10)0.0;
LAB_0062a1da:
        *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
        *(undefined4 *)(param_1 + 0x210) = 0;
        return fVar8;
      case 0x25:
        local_210 = 2;
        break;
      case 0x26:
        local_210 = 0x10;
        break;
      case 0x2e:
        local_210 = 10;
        pbVar6 = param_2;
      }
    }
  }
  else {
    local_210 = *(int *)(param_1 + 0x200);
    if (bVar2 == 0x30) {
      pbVar6 = param_2;
      if ((*pbVar5 == 0x78) && (local_210 < 0x22)) {
        local_210 = 0x10;
        pbVar6 = param_2 + 2;
      }
    }
    else {
      pbVar6 = param_2;
      if (bVar2 == 0x40) {
        local_210 = 8;
        pbVar6 = pbVar5;
      }
    }
  }
  fVar8 = (float10)_DAT_006669e8;
  bVar2 = *pbVar6;
  while (bVar2 != 0) {
    pbVar5 = pbVar6 + 1;
    if (bVar2 == 0x2e) {
      fVar9 = (float10)_DAT_00667280;
      bVar2 = *pbVar5;
      while (bVar2 != 0) {
        bVar1 = bVar2 - 0x30;
        if (9 < bVar1) {
          bVar1 = (bVar2 | 0x20) + 0xa9;
        }
        if (bVar1 < (byte)local_210) {
          fVar9 = ((float10)_DAT_00666748 / (float10)local_210) * fVar9;
          fVar8 = (float10)bVar1 * fVar9 + fVar8;
        }
        else if (*pbVar5 != 0x5f) break;
        bVar2 = pbVar5[1];
        pbVar5 = pbVar5 + 1;
      }
    }
    else {
      bVar1 = bVar2 - 0x30;
      if (9 < bVar1) {
        bVar1 = (bVar2 | 0x20) + 0xa9;
      }
      if (bVar1 < (byte)local_210) {
        fVar8 = (float10)bVar1 + fVar8 * (float10)local_210;
      }
      else if (*pbVar6 != 0x5f) break;
    }
    pbVar6 = pbVar5;
    bVar2 = *pbVar5;
  }
  if (*pbVar6 == 0) {
    *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
    *(undefined4 *)(param_1 + 0x210) = 0;
    return fVar8;
  }
  if (DAT_006dae24 < 2) {
    bVar2 = *param_2;
    uVar3 = (byte)PTR_DAT_006dac18[(uint)bVar2 * 2] & 4;
  }
  else {
    bVar2 = *param_2;
    uVar3 = FUN_0063cdac(bVar2,4);
  }
  pbVar5 = param_2;
  if (uVar3 != 0) {
    while (bVar2 != 0) {
      bVar2 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
    }
    bVar2 = pbVar5[-1];
    pbVar5[-1] = 0;
    switch(bVar2 | 0x20) {
    case 0x62:
      local_210 = *(undefined4 *)(param_1 + 0x200);
      *(undefined4 *)(param_1 + 0x200) = 2;
      break;
    default:
      pbVar5[-1] = bVar2;
      goto LAB_0062a4ce;
    case 100:
      local_210 = *(undefined4 *)(param_1 + 0x200);
      *(undefined4 *)(param_1 + 0x200) = 10;
      break;
    case 0x68:
      local_210 = *(undefined4 *)(param_1 + 0x200);
      *(undefined4 *)(param_1 + 0x200) = 0x10;
      break;
    case 0x6f:
    case 0x71:
      local_210 = *(undefined4 *)(param_1 + 0x200);
      *(undefined4 *)(param_1 + 0x200) = 8;
    }
    fVar8 = (float10)FUN_0062a120(param_1,param_2,param_3);
    *(int *)(param_1 + 0x200) = local_210;
    pbVar5[-1] = bVar2;
    return fVar8;
  }
LAB_0062a4ce:
  if (*param_2 != 0) {
    if (((*param_2 == 0x5e) && (param_2[2] == 0)) &&
       (bVar2 = (param_2[1] | 0x20) + 0xa0, bVar2 < 0x1b)) {
      *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
      *(undefined4 *)(param_1 + 0x210) = 0;
      return (float10)bVar2;
    }
    iVar4 = FUN_0062ac30(param_1,param_2);
    if (iVar4 != 0) {
      FUN_0061ce00(param_1,*(undefined4 *)(param_1 + 0x240));
      if ((*(int *)(param_1 + 0x234) != 0) &&
         (*(int *)(*(int *)(param_1 + 0x254) + 0x18) == 0x7ffffffb)) {
        if (*(int *)(param_1 + 0x244) == 0) {
          FUN_0061cf50(param_1,param_3,5);
          return (float10)*(double *)(param_1 + 0x102a8);
        }
        fVar8 = (float10)_DAT_006669e8;
        *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
        *(undefined4 *)(param_1 + 0x210) = 0;
        return fVar8;
      }
      if ((*(byte *)(*(int *)(param_1 + 0x254) + 0x1c) & 0x60) != 0) {
        FUN_0061cf50(param_1,param_3,9);
      }
      return (float10)*(double *)(param_1 + 0x102a8);
    }
    iVar4 = FUN_00646330(param_2,&DAT_00677c90);
    if (iVar4 == 0) {
      fVar8 = (float10)**(int **)(param_1 + 0x220);
      if (fVar8 == (float10)_DAT_00671740) {
        fVar8 = (float10)_DAT_006669e8;
      }
      *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
      *(undefined4 *)(param_1 + 0x210) = 0;
      return fVar8;
    }
  }
  if (*(int *)(param_1 + 0x244) == 0) {
    FUN_0061cf50(param_1,param_3,5);
    return (float10)_DAT_006669e8;
  }
  fVar8 = (float10)_DAT_006669e8;
  *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
  *(undefined4 *)(param_1 + 0x210) = 0;
  return fVar8;
}

