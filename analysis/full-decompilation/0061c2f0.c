
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * FUN_0061c2f0(int param_1,byte *param_2,byte *param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  char *pcVar13;
  byte *pbVar14;
  float10 fVar15;
  byte local_208 [516];
  
  bVar6 = *param_3;
  pbVar9 = param_3;
  pbVar11 = param_2;
  if (bVar6 == 0x22) {
LAB_0061c319:
    pbVar12 = pbVar9 + 1;
LAB_0061c31a:
    do {
      bVar6 = *pbVar12;
      pbVar9 = pbVar12 + 1;
      if (bVar6 == 0x5c) {
        bVar6 = *pbVar9;
        pbVar9 = pbVar12 + 2;
        switch(bVar6) {
        case 0x22:
          *pbVar11 = 0x22;
          pbVar11 = pbVar11 + 1;
          break;
        default:
          bVar6 = bVar6 - 0x30;
          bVar2 = bVar6;
          if (bVar6 < 8) {
            bVar2 = *pbVar9 - 0x30;
            pbVar9 = pbVar12 + 3;
            if (bVar2 < 8) {
              bVar6 = bVar6 * '\b' + bVar2;
              bVar2 = *pbVar9 - 0x30;
              pbVar9 = pbVar12 + 4;
              if (bVar2 < 8) {
                if (0x1f < bVar6) {
                  FUN_0061cf50(param_1,pbVar9 + (param_4 - (int)param_3),10);
                }
                bVar6 = bVar6 * '\b' + bVar2;
                pbVar9 = pbVar12 + 5;
              }
            }
            *pbVar11 = bVar6;
            pbVar11 = pbVar11 + 1;
          }
          if ((bVar2 == 8) || (bVar2 == 9)) {
            FUN_0061cf50(param_1,pbVar9 + (param_4 - (int)param_3),0x1d);
          }
          pbVar12 = pbVar9 + -1;
          goto LAB_0061c31a;
        case 0x27:
          *pbVar11 = 0x27;
          pbVar11 = pbVar11 + 1;
          break;
        case 0x3c:
          *pbVar11 = 0x3c;
          pbVar11 = pbVar11 + 1;
          break;
        case 0x5c:
          *pbVar11 = 0x5c;
          pbVar11 = pbVar11 + 1;
          break;
        case 0x62:
          *pbVar11 = 8;
          pbVar11 = pbVar11 + 1;
          break;
        case 0x66:
          *pbVar11 = 0xc;
          pbVar11 = pbVar11 + 1;
          break;
        case 0x6e:
          *pbVar11 = 10;
          pbVar11 = pbVar11 + 1;
          break;
        case 0x72:
          *pbVar11 = 0xd;
          pbVar11 = pbVar11 + 1;
          break;
        case 0x74:
          *pbVar11 = 9;
          pbVar11 = pbVar11 + 1;
        }
      }
      else if (bVar6 == 0x3c) {
        pbVar12 = local_208;
        do {
          pbVar14 = pbVar12;
          bVar6 = *pbVar9;
          pbVar10 = pbVar9 + 1;
          *pbVar14 = bVar6;
          if (bVar6 == 0) goto LAB_0061c462;
          pbVar12 = pbVar14 + 1;
          pbVar9 = pbVar10;
        } while (bVar6 != 0x3e);
        *pbVar14 = 0;
LAB_0061c462:
        *pbVar11 = 0;
        iVar3 = FUN_0061c7a0(param_1,local_208);
        if (iVar3 == 0) {
          pbVar12 = pbVar9 + (param_4 - (int)param_3);
          fVar15 = (float10)FUN_0061a0e0(param_1,local_208,pbVar12);
          iVar3 = *(int *)(param_1 + 0x20c);
joined_r0x0061c568:
          if (iVar3 != 0x7fff) {
            FUN_0061cf50(param_1,pbVar12,0xe);
          }
          FUN_00635858(pbVar11,&DAT_006c8db0,(double)fVar15);
        }
        else {
          uVar7 = *(uint *)(*(int *)(param_1 + 0x254) + 0x1c);
          if (uVar7 == 0x100) {
            pcVar4 = (char *)__ftol();
            uVar7 = 0xffffffff;
            do {
              pcVar13 = pcVar4;
              if (uVar7 == 0) break;
              uVar7 = uVar7 - 1;
              pcVar13 = pcVar4 + 1;
              cVar1 = *pcVar4;
              pcVar4 = pcVar13;
            } while (cVar1 != '\0');
            uVar7 = ~uVar7;
            pbVar12 = (byte *)(pcVar13 + -uVar7);
            pbVar14 = pbVar11;
            for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *(undefined4 *)pbVar14 = *(undefined4 *)pbVar12;
              pbVar12 = pbVar12 + 4;
              pbVar14 = pbVar14 + 4;
            }
            for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
              *pbVar14 = *pbVar12;
              pbVar12 = pbVar12 + 1;
              pbVar14 = pbVar14 + 1;
            }
          }
          else {
            if ((uVar7 & 0x20) == 0) {
              pbVar12 = pbVar9 + (param_4 - (int)param_3);
              fVar15 = (float10)FUN_0061a0e0(param_1,local_208,pbVar12);
              iVar3 = *(int *)(param_1 + 0x20c);
              goto joined_r0x0061c568;
            }
            if (*(double *)(*(int *)(param_1 + 0x254) + 8) <= _DAT_0066f3c0) {
              uVar5 = __ftol();
              FUN_00635858(pbVar11,&PTR_DAT_00677c98,uVar5);
            }
            else {
              iVar3 = __ftol();
              FUN_00635858(pbVar11,&PTR_DAT_00677c9c,iVar3 + -8);
            }
          }
        }
        bVar2 = *pbVar11;
        while (bVar2 != 0) {
          pbVar12 = pbVar11 + 1;
          pbVar11 = pbVar11 + 1;
          bVar2 = *pbVar12;
        }
      }
      else {
        *pbVar11 = bVar6;
        pbVar11 = pbVar11 + 1;
      }
      if ((bVar6 == 0) || (pbVar12 = pbVar9, bVar6 == 0x22)) goto LAB_0061c5bf;
    } while( true );
  }
  if (bVar6 != 0x27) {
    pbVar11 = param_3;
    pbVar12 = param_2;
    if (bVar6 == 0x5c) {
      pbVar11 = param_3 + 1;
    }
    do {
      pbVar14 = pbVar12;
      pbVar9 = pbVar11;
      bVar2 = *pbVar9;
      pbVar11 = pbVar9 + 1;
      *pbVar14 = bVar2;
      pbVar12 = pbVar14 + 1;
      if ((bVar2 < 0x21) || (bVar2 == 0x3b)) break;
    } while (bVar2 != 0x2c);
    if ((bVar2 != 0) && (*pbVar14 = 0, pbVar9 = pbVar11, pbVar12 = pbVar14, pbVar14[-1] == 0x5c)) {
      pbVar12 = pbVar14 + -1;
      *pbVar12 = 0;
    }
    iVar3 = FUN_0061c7a0(param_1,param_2);
    if (iVar3 == 0) {
      if (bVar6 != 0x5c) goto LAB_0061c6fa;
      uVar5 = 5;
    }
    else {
      if ((*(uint *)(*(int *)(param_1 + 0x254) + 0x1c) & 0x100) != 0) {
        pcVar4 = (char *)__ftol();
        uVar7 = 0xffffffff;
        do {
          pcVar13 = pcVar4;
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          pcVar13 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar13;
        } while (cVar1 != '\0');
        uVar7 = ~uVar7;
        pbVar11 = (byte *)(pcVar13 + -uVar7);
        pbVar12 = param_2;
        for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)pbVar12 = *(undefined4 *)pbVar11;
          pbVar11 = pbVar11 + 4;
          pbVar12 = pbVar12 + 4;
        }
        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *pbVar12 = *pbVar11;
          pbVar11 = pbVar11 + 1;
          pbVar12 = pbVar12 + 1;
        }
        uVar7 = 0xffffffff;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar6 = *param_2;
          param_2 = param_2 + 1;
        } while (bVar6 != 0);
        *(uint *)(param_1 + 0x22c) = ~uVar7 - 1;
        uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x254) + 0x18);
        *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(*(int *)(param_1 + 0x254) + 0x10);
        *(undefined4 *)(param_1 + 0x210) = uVar5;
        return pbVar9;
      }
      if (bVar6 != 0x5c) goto LAB_0061c6fa;
      uVar5 = 7;
    }
    FUN_0061cf50(param_1,pbVar9 + (param_4 - (int)param_3),uVar5);
    goto LAB_0061c6fa;
  }
  do {
    pbVar9 = pbVar9 + 1;
    do {
      pbVar12 = pbVar11;
      bVar6 = *pbVar9;
      pbVar9 = pbVar9 + 1;
      *pbVar12 = bVar6;
      pbVar11 = pbVar12 + 1;
      if (bVar6 == 0) break;
    } while (bVar6 != 0x27);
  } while (*pbVar9 == 0x27);
  if (bVar6 == 0x27) {
    *pbVar12 = 0;
    goto LAB_0061c6fa;
  }
LAB_0061c5dd:
  pbVar12 = pbVar11;
  pbVar9 = pbVar9 + -1;
LAB_0061c6fa:
  *(int *)(param_1 + 0x22c) = (int)pbVar12 - (int)param_2;
  *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
  *(undefined4 *)(param_1 + 0x210) = 0;
  return pbVar9;
LAB_0061c5bf:
  if (*pbVar9 != 0x22) goto code_r0x0061c5c8;
  goto LAB_0061c319;
code_r0x0061c5c8:
  if (bVar6 == 0x22) {
    pbVar12 = pbVar11 + -1;
    *pbVar12 = 0;
    goto LAB_0061c6fa;
  }
  goto LAB_0061c5dd;
}

