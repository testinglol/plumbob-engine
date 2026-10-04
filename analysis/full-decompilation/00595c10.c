
void __fastcall FUN_00595c10(undefined4 *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  bool bVar7;
  
  FUN_00595d81(param_1[0x1e]);
  param_1[0x4c] = param_1[0x4c] + 1;
  pbVar3 = (byte *)*param_1;
  pbVar5 = &DAT_006c4518;
  do {
    bVar1 = *pbVar3;
    bVar7 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) {
LAB_00595c55:
      iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_00595c5a;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar7 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) goto LAB_00595c55;
    pbVar3 = pbVar3 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_00595c5a:
  if (iVar4 != 0) {
    pbVar3 = (byte *)*param_1;
    pcVar6 = s_PELVIS_006c459c;
    do {
      bVar1 = *pbVar3;
      bVar7 = bVar1 < (byte)*pcVar6;
      if (bVar1 != *pcVar6) {
LAB_00595c8b:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_00595c90;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar7 = bVar1 < (byte)pcVar6[1];
      if (bVar1 != pcVar6[1]) goto LAB_00595c8b;
      pbVar3 = pbVar3 + 2;
      pcVar6 = pcVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_00595c90:
    if (iVar4 != 0) {
      pbVar3 = (byte *)*param_1;
      pcVar6 = s_R_FOOT_006d1cec;
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < (byte)*pcVar6;
        if (bVar1 != *pcVar6) {
LAB_00595cc1:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_00595cc6;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < (byte)pcVar6[1];
        if (bVar1 != pcVar6[1]) goto LAB_00595cc1;
        pbVar3 = pbVar3 + 2;
        pcVar6 = pcVar6 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00595cc6:
      if (iVar4 != 0) {
        pbVar3 = (byte *)*param_1;
        pbVar5 = &DAT_006d1cbc;
        do {
          bVar1 = *pbVar3;
          bVar7 = bVar1 < *pbVar5;
          if (bVar1 != *pbVar5) {
LAB_00595cf7:
            iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_00595cfc;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar7 = bVar1 < pbVar5[1];
          if (bVar1 != pbVar5[1]) goto LAB_00595cf7;
          pbVar3 = pbVar3 + 2;
          pbVar5 = pbVar5 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_00595cfc:
        if (iVar4 != 0) {
          pbVar3 = (byte *)*param_1;
          pcVar6 = s_R_HAND_006d1c5c;
          do {
            bVar1 = *pbVar3;
            bVar7 = bVar1 < (byte)*pcVar6;
            if (bVar1 != *pcVar6) {
LAB_00595d29:
              iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
              goto LAB_00595d2e;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar7 = bVar1 < (byte)pcVar6[1];
            if (bVar1 != pcVar6[1]) goto LAB_00595d29;
            pbVar3 = pbVar3 + 2;
            pcVar6 = pcVar6 + 2;
          } while (bVar1 != 0);
          iVar4 = 0;
LAB_00595d2e:
          if (iVar4 != 0) {
            pbVar3 = (byte *)*param_1;
            pcVar6 = s_L_HAND_006d1c24;
            do {
              bVar1 = *pbVar3;
              bVar7 = bVar1 < (byte)*pcVar6;
              if (bVar1 != *pcVar6) {
LAB_00595d5b:
                iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
                goto LAB_00595d60;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar3[1];
              bVar7 = bVar1 < (byte)pcVar6[1];
              if (bVar1 != pcVar6[1]) goto LAB_00595d5b;
              pbVar3 = pbVar3 + 2;
              pcVar6 = pcVar6 + 2;
            } while (bVar1 != 0);
            iVar4 = 0;
LAB_00595d60:
            if (iVar4 != 0) {
              uVar2 = 0;
              goto LAB_00595d6a;
            }
          }
        }
      }
    }
  }
  uVar2 = 1;
LAB_00595d6a:
  *(undefined1 *)(param_1 + 0x4b) = uVar2;
  param_1[0x4c] = param_1[0x4c] + 1;
  return;
}

