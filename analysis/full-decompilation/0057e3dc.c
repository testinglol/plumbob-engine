
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0057e3dc(byte *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 *puVar3;
  char cVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint *puVar16;
  bool bVar17;
  bool bVar18;
  byte **ppbVar19;
  char *pcVar20;
  byte *pbStack_c;
  byte *pbStack_8;
  
  puVar3 = *(undefined1 **)(param_1 + 0x19c);
  pbVar13 = param_1 + 0x19c;
  *(undefined1 **)(param_1 + 0x1a4) = puVar3;
  uVar1 = *puVar3;
  pbVar5 = puVar3 + 1;
  *(byte **)pbVar13 = pbVar5;
  pbStack_c = param_1;
  pbStack_8 = param_1;
  switch(uVar1) {
  case 1:
    uVar6 = FUN_0057f85a();
    uVar8 = (**(code **)(*(int *)param_1 + 0x88))(uVar6);
    uVar6 = FUN_0057f85a();
    iVar9 = (**(code **)(*(int *)param_1 + 0x88))(uVar6);
    *(int *)(param_1 + 0x194) = *(int *)(DAT_006f6a78 + 0x58) + iVar9;
    goto LAB_0057e47f;
  case 2:
    uVar8 = (uint)*pbVar5;
    *(undefined1 **)pbVar13 = puVar3 + 2;
LAB_0057e47f:
    FUN_0057f88e(uVar8);
    return 1;
  case 3:
    bVar2 = *pbVar5;
    *(undefined1 **)pbVar13 = puVar3 + 2;
    if (*(int **)(param_1 + 0x1d0) == (int *)0x0) {
      return 1;
    }
    (**(code **)(**(int **)(param_1 + 0x1d0) + 0x98))(bVar2);
    return 1;
  case 4:
    iVar9 = FUN_0057f85a();
    if ((iVar9 == 0) || (0x7f < iVar9)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdLoadb_006d0140;
    }
    else {
      uVar8 = (uint)**(byte **)pbVar13;
      puVar16 = (uint *)(*(byte **)pbVar13 + 1);
LAB_0057e4c3:
      *(uint **)pbVar13 = puVar16;
      cVar4 = (**(code **)(*(int *)param_1 + 0x84))(iVar9,uVar8,0);
LAB_0057e4d3:
      if (cVar4 != '\0') {
        return 1;
      }
      pcVar20 = s_Could_not_set_register_006d015c;
    }
    break;
  case 5:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      uVar8 = **(uint **)pbVar13;
      puVar16 = *(uint **)pbVar13 + 1;
      goto LAB_0057e4c3;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdLoadl_006d0124;
    break;
  case 6:
    iVar9 = FUN_0057f85a();
    if ((iVar9 == 0) || (0x7f < iVar9)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdSet_Dest_006d00e4;
    }
    else {
      iVar7 = FUN_0057f85a();
      if ((iVar7 != 0) && (iVar7 < 0x80)) {
        uVar6 = (**(code **)(*(int *)param_1 + 0x88))(iVar7);
LAB_0057e5cb:
        cVar4 = (**(code **)(*(int *)param_1 + 0x84))(iVar9,uVar6,0);
        goto LAB_0057e4d3;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdSet_Src_006d0104;
    }
    break;
  case 7:
    uVar6 = *(undefined4 *)pbVar5;
    *(undefined1 **)pbVar13 = puVar3 + 5;
    iVar9 = FUN_0057d0a9(uVar6);
    FUN_00580875(pbVar13);
    *(int *)pbVar13 = iVar9;
    return 1;
  case 8:
  case 0xc:
    pbStack_8 = (byte *)0x0;
    FUN_00576b0a(**(undefined4 **)(param_1 + 0x1a8),*(undefined4 **)(param_1 + 0x1a8),&pbStack_8);
    if (pbStack_8 != (byte *)0x0) {
      iVar9 = *(int *)(**(int **)(param_1 + 0x1a8) + 8);
      FUN_005807f5();
      *(int *)pbVar13 = iVar9;
      return 1;
    }
  case 0x1b:
LAB_0057f0c1:
    (**(code **)(*(int *)param_1 + 0x34))();
    return 1;
  case 9:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      *(int *)(param_1 + 0x198) = iVar9 + *(int *)(DAT_006f6a78 + 0x58);
      return 1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdWait_006cff84;
    break;
  default:
    pcVar20 = s_Illegal_Instruction_006cf608;
    goto LAB_0057f6f2;
  case 0xb:
    if (*(int **)(param_1 + 0x1d0) == (int *)0x0) {
      return 1;
    }
    cVar4 = (**(code **)(**(int **)(param_1 + 0x1d0) + 0x70))();
    if (cVar4 == '\0') {
      return 1;
    }
    *(int *)pbVar13 = *(int *)pbVar13 + -1;
    goto LAB_0057e9b6;
  case 0xd:
    uVar6 = *(undefined4 *)pbVar5;
    *(undefined1 **)pbVar13 = puVar3 + 5;
    goto LAB_0057e6ae;
  case 0xe:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      param_1[0x1cc] = iVar9 == 0;
      param_1[0x1cd] = 0 < iVar9;
      bVar17 = false;
LAB_0057ea72:
      param_1[0x1ce] = bVar17 != iVar9 < 0;
      return 1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdTest_006cfd98;
    break;
  case 0xf:
  case 0x1d:
  case 0x1e:
  case 0x46:
    goto LAB_0057f701;
  case 0x10:
    pbVar13 = (byte *)FUN_0057f85a();
    pbStack_8 = pbVar13;
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdAdd_lDestR_006cfd10;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        iVar7 = (**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        pbVar13 = (byte *)(iVar7 + iVar9);
        iVar9 = *(int *)param_1;
LAB_0057f647:
        (**(code **)(iVar9 + 0x84))(pbStack_8,pbVar13,0);
        return 1;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdAdd_lSrcRe_006cfd34;
    }
    break;
  case 0x11:
    pbVar13 = (byte *)FUN_0057f85a();
    pbStack_8 = pbVar13;
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdSub_lDestR_006cfcc8;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        iVar7 = (**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        pbVar13 = (byte *)(iVar7 - iVar9);
        iVar9 = *(int *)param_1;
        goto LAB_0057f647;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdSub_lSrcRe_006cfcec;
    }
    break;
  case 0x12:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdDiv_lDestR_006cfc80;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        uVar8 = (int)pbStack_8 / iVar9;
        goto LAB_0057f10f;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdDiv_lSrcRe_006cfca4;
    }
    break;
  case 0x13:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdMul_lDestR_006cfc38;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        uVar8 = iVar9 * (int)pbStack_8;
        goto LAB_0057f10f;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdMul_lSrcRe_006cfc5c;
    }
    break;
  case 0x14:
    iVar9 = FUN_0057f85a();
    if ((iVar9 == 0) || (0x7f < iVar9)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdCmp_Dest_006cfd58;
    }
    else {
      iVar7 = FUN_0057f85a();
      if ((iVar7 != 0) && (iVar7 < 0x80)) {
        iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        iVar7 = (**(code **)(*(int *)param_1 + 0x88))(iVar7);
        param_1[0x1cc] = iVar9 == iVar7;
        param_1[0x1cd] = iVar7 < iVar9;
        bVar17 = SBORROW4(iVar9,iVar7);
        iVar9 = iVar9 - iVar7;
        goto LAB_0057ea72;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdCmp_Src_006cfd78;
    }
    break;
  case 0x15:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdLess_lDest_006cfbf0;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        bVar17 = (int)pbStack_8 < iVar9;
LAB_0057ecd3:
        uVar8 = (uint)bVar17;
        goto LAB_0057f10f;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdLess_lSrcR_006cfc14;
    }
    break;
  case 0x16:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdGreater_lD_006cfba0;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        pbVar5 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(iVar9);
        bVar18 = SBORROW4((int)pbStack_8,(int)pbVar5);
        iVar9 = (int)pbStack_8 - (int)pbVar5;
        bVar17 = pbStack_8 == pbVar5;
LAB_0057ed88:
        bVar17 = !bVar17 && bVar18 == iVar9 < 0;
        goto LAB_0057ecd3;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdGreater_lS_006cfbc8;
    }
    break;
  case 0x17:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 != (byte *)0x0) && ((int)pbVar13 < 0x80)) {
      iVar9 = (**(code **)(*(int *)param_1 + 0x88))(pbVar13);
      uVar8 = (uint)(iVar9 == 0);
      goto LAB_0057f10f;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdNot_lDestR_006cfa14;
    break;
  case 0x18:
    pbStack_8 = (byte *)FUN_0057f85a();
    if ((pbStack_8 == (byte *)0x0) || (0x7f < (int)pbStack_8)) {
LAB_0057efe4:
      pcVar20 = s_TRACK_ERROR__kTrackCmdRand_lDest_006cf9a8;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 == 0) || (0x7f < iVar9)) {
        pcVar20 = s_TRACK_ERROR__kTrackCmdRand_lMinR_006cf9cc;
      }
      else {
        iVar7 = FUN_0057f85a();
        if ((iVar7 != 0) && (iVar7 < 0x80)) {
          iVar11 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
          iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar7);
          iVar7 = FUN_005bc722(iVar9 - iVar11);
          iVar9 = *(int *)param_1;
          uVar8 = iVar7 + iVar11;
          pbVar13 = pbStack_8;
          goto LAB_0057f4ad;
        }
        pcVar20 = s_TRACK_ERROR__kTrackCmdRand_lMaxR_006cf9f0;
      }
    }
    break;
  case 0x19:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) goto LAB_0057efe4;
    uVar8 = (**(code **)(*(int *)param_1 + 0x88))(pbVar13);
    if ((int)uVar8 < 0) {
      uVar8 = -uVar8;
    }
LAB_0057f10f:
    iVar9 = *(int *)param_1;
LAB_0057f4ad:
    (**(code **)(iVar9 + 0x84))(pbVar13,uVar8,0);
    return 1;
  case 0x1c:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      goto LAB_0057f0c1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdAssert_lDe_006cf938;
    break;
  case 0x1f:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdGetVar_lMa_006cf8e8;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        uVar6 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        uVar8 = (**(code **)(*(int *)param_1 + 0x88))(uVar6);
        goto LAB_0057f10f;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdGetVar_lSr_006cf910;
    }
    break;
  case 0x20:
    iVar9 = *(int *)(param_1 + 0x1a0);
    goto LAB_0057f132;
  case 0x21:
    *(byte **)(param_1 + 0x1a0) = pbVar5;
    return 1;
  case 0x22:
    iVar9 = FUN_0057f85a();
    if ((iVar9 == 0) || (0x7f < iVar9)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdCallback_l_006cf898;
    }
    else {
      iVar7 = FUN_0057f85a();
      if ((iVar7 != 0) && (iVar7 < 0x80)) {
        (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        (**(code **)(*(int *)param_1 + 0x88))(iVar7);
        return 1;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdCallback_l_006cf8c0;
    }
    break;
  case 0x23:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      uVar6 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      FUN_005806fe(uVar6);
      return 1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdSmartAdd_l_006cf7a8;
    break;
  case 0x24:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      uVar6 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      FUN_005806a8(uVar6);
      return 1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdSmartRemov_006cf77c;
    break;
  case 0x25:
    FUN_00602b9f();
    FUN_00602b9f();
    return 1;
  case 0x26:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      uVar6 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      iVar9 = *(int *)(param_1 + 0x1c0);
      *(undefined4 *)(iVar9 + 0xc) = uVar6;
      *(undefined1 *)(iVar9 + 0x10) = 1;
      return 1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdSmartSetCr_006cf750;
    break;
  case 0x27:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdSmartChoos_006cf700;
    }
    else {
      pbStack_c = (byte *)FUN_0060783f();
      iVar9 = FUN_0060783f();
      if (pbStack_c + iVar9 != (byte *)0x0) {
        uVar8 = (**(code **)**(undefined4 **)(param_1 + 0x1c0))();
LAB_0057f4a7:
        iVar9 = *(int *)param_1;
        goto LAB_0057f4ad;
      }
      pcVar20 = s_Attempt_to_choose_from_empty_tra_006cf728;
    }
    break;
  case 0x28:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdAnd_lDestR_006cfb58;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        pbVar5 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(iVar9);
        bVar18 = SBORROW4((int)pbStack_8,(int)pbVar5);
        iVar9 = (int)pbStack_8 - (int)pbVar5;
        bVar17 = pbStack_8 == pbVar5;
        goto LAB_0057ed88;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdAnd_lSrcRe_006cfb7c;
    }
    break;
  case 0x29:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdNand_lDest_006cfb10;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        iVar7 = (**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        if ((iVar7 == 0) || (iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9), iVar9 == 0))
        goto LAB_0057eeb3;
LAB_0057eeab:
        uVar8 = 1;
        goto LAB_0057f4a7;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdNand_lSrcR_006cfb34;
    }
    break;
  case 0x2a:
    pbVar13 = (byte *)FUN_0057f85a();
    pbStack_8 = pbVar13;
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdOr_lDestRe_006cfac8;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        uVar8 = (**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        uVar10 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        pbVar13 = (byte *)(uVar8 | uVar10);
        iVar9 = *(int *)param_1;
        goto LAB_0057f647;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdOr_lSrcReg_006cfaec;
    }
    break;
  case 0x2b:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdNor_lDestR_006cfa80;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        iVar7 = (**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        if ((iVar7 == 0) && (iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9), iVar9 == 0))
        goto LAB_0057eeab;
LAB_0057eeb3:
        uVar8 = 0;
        goto LAB_0057f4a7;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdNor_lSrcRe_006cfaa4;
    }
    break;
  case 0x2c:
    pbVar13 = (byte *)FUN_0057f85a();
    pbStack_8 = pbVar13;
    if ((pbVar13 == (byte *)0x0) || (0x7f < (int)pbVar13)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdXor_lDestR_006cfa38;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        uVar8 = (**(code **)(*(int *)param_1 + 0x88))(pbVar13);
        uVar10 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        pbVar13 = (byte *)(uVar8 ^ uVar10);
        iVar9 = *(int *)param_1;
        goto LAB_0057f647;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdXor_lSrcRe_006cfa5c;
    }
    break;
  case 0x2d:
    pbStack_8 = (byte *)FUN_0057f85a();
    if ((pbStack_8 != (byte *)0x0) && ((int)pbStack_8 < 0x80)) {
      uVar10 = **(uint **)pbVar13;
      *(uint **)pbVar13 = *(uint **)pbVar13 + 1;
      uVar8 = (**(code **)(*(int *)param_1 + 0x88))(pbStack_8);
      if ((int)uVar10 <= (int)uVar8) {
        uVar8 = uVar10;
      }
      iVar9 = *(int *)param_1;
      pbVar13 = pbStack_8;
      goto LAB_0057f4ad;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdMin_lDestR_006cf960;
    break;
  case 0x2e:
    pbStack_8 = (byte *)FUN_0057f85a();
    if ((pbStack_8 != (byte *)0x0) && ((int)pbStack_8 < 0x80)) {
      uVar10 = **(uint **)pbVar13;
      *(uint **)pbVar13 = *(uint **)pbVar13 + 1;
      uVar8 = (**(code **)(*(int *)param_1 + 0x88))(pbStack_8);
      if ((int)uVar8 <= (int)uVar10) {
        uVar8 = uVar10;
      }
      iVar9 = *(int *)param_1;
      pbVar13 = pbStack_8;
      goto LAB_0057f4ad;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdMax_lDestR_006cf984;
    break;
  case 0x2f:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 != (byte *)0x0) && ((int)pbVar13 < 0x80)) {
      iVar7 = (**(code **)(*(int *)param_1 + 0x88))(pbVar13);
      iVar9 = *(int *)param_1;
      uVar8 = iVar7 + 1;
      goto LAB_0057f4ad;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdInc_Dest_006cffc0;
    break;
  case 0x30:
    pbVar13 = (byte *)FUN_0057f85a();
    if ((pbVar13 != (byte *)0x0) && ((int)pbVar13 < 0x80)) {
      iVar7 = (**(code **)(*(int *)param_1 + 0x88))(pbVar13);
      iVar9 = *(int *)param_1;
      uVar8 = iVar7 - 1;
      goto LAB_0057f4ad;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdDec_Dest_006cffa0;
    break;
  case 0x31:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      return 1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdPrintReg_l_006cf6d8;
    break;
  case 0x32:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      uVar6 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      piVar12 = (int *)FUN_00573466(uVar6);
      iVar9 = *piVar12;
      uVar6 = FUN_005805ba(3);
      uVar15 = FUN_005805ba(2);
      uVar14 = FUN_005805ba(1);
      (**(code **)(iVar9 + 0x2c))(uVar14,uVar15,uVar6);
      iVar9 = *piVar12;
      uVar6 = (**(code **)(*(int *)param_1 + 0x88))(0x2f,0);
      (**(code **)(iVar9 + 0x84))(0x2f,uVar6);
      return 1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdPlayTrack_S_006cf6b4;
    break;
  case 0x33:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      uVar6 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      FUN_0057f854(uVar6);
      piVar12 = (int *)FUN_00573466(uVar6);
      (**(code **)(*piVar12 + 0x38))();
      return 1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdKillTrack_S_006cf690;
    goto LAB_0057f6fc;
  case 0x3a:
    if (DAT_006f6a80 == (int *)0x0) {
      uVar6 = DAT_006cf470;
      FUN_0057f854(DAT_006cf470);
      _DAT_006f6a7c = (int *)FUN_00573466(uVar6);
      DAT_006f6a80 = (int *)(**(code **)(*_DAT_006f6a7c + 0xa0))();
    }
    (**(code **)(*DAT_006f6a80 + 0x94))(0);
    return 1;
  case 0x3b:
    if (DAT_006f6a80 == (int *)0x0) {
      return 1;
    }
    iVar9 = *DAT_006f6a80;
    uVar6 = 0xe10;
    goto LAB_0057f6e8;
  case 0x3c:
    if (DAT_006f6a80 == (int *)0x0) {
      return 1;
    }
    iVar9 = *DAT_006f6a80;
    uVar6 = 0x1004;
    goto LAB_0057f6e8;
  case 0x3d:
    if (DAT_006f6a80 == (int *)0x0) {
      return 1;
    }
    iVar9 = *DAT_006f6a80;
    uVar6 = 0x1210;
LAB_0057f6e8:
    (**(code **)(iVar9 + 0x44))(uVar6);
    return 1;
  case 0x3e:
    uVar6 = *(undefined4 *)pbVar5;
    *(undefined1 **)pbVar13 = puVar3 + 5;
    goto LAB_0057eb00;
  case 0x3f:
    uVar6 = *(undefined4 *)pbVar5;
    *(undefined1 **)pbVar13 = puVar3 + 5;
    goto LAB_0057eaca;
  case 0x40:
    uVar6 = *(undefined4 *)pbVar5;
    bVar2 = param_1[0x1cd];
    *(undefined1 **)pbVar13 = puVar3 + 5;
    goto LAB_0057eac4;
  case 0x41:
    uVar6 = *(undefined4 *)pbVar5;
    bVar2 = param_1[0x1ce];
    *(undefined1 **)pbVar13 = puVar3 + 5;
LAB_0057eac4:
    if (bVar2 == 0) {
      return 1;
    }
LAB_0057eaca:
    if (param_1[0x1cc] != 0) {
      return 1;
    }
LAB_0057e6ae:
    iVar9 = FUN_0057d0a9(uVar6);
LAB_0057f132:
    *(int *)pbVar13 = iVar9;
    return 1;
  case 0x42:
    uVar6 = *(undefined4 *)pbVar5;
    bVar2 = param_1[0x1cd];
    *(undefined1 **)pbVar13 = puVar3 + 5;
    goto LAB_0057eafa;
  case 0x43:
    uVar6 = *(undefined4 *)pbVar5;
    bVar2 = param_1[0x1ce];
    *(undefined1 **)pbVar13 = puVar3 + 5;
LAB_0057eafa:
    if (bVar2 == 0) {
LAB_0057eb00:
      if (param_1[0x1cc] == 0) {
        return 1;
      }
    }
    goto LAB_0057e6ae;
  case 0x44:
    iVar9 = FUN_0057f85a();
    if ((iVar9 == 0) || (0x7f < iVar9)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdSmartSetLi_006cf858;
    }
    else {
      iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      if (iVar9 == 0) {
        pbVar13 = param_1 + 0x1ac;
      }
      else {
        pbVar13 = (byte *)FUN_0057d4e4(iVar9);
      }
      *(byte **)(param_1 + 0x1c0) = pbVar13;
      if (pbVar13 != (byte *)0x0) {
        return 1;
      }
      pcVar20 = s_Undefined_Hit_List_006cf884;
    }
    break;
  case 0x45:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      pbStack_c = (byte *)(iVar9 * 4 + 0x1a4);
      pbVar5 = *(byte **)(pbStack_c + DAT_006f6a78);
      pbStack_8 = (byte *)(**(code **)(**(int **)(param_1 + 0xc4) + 0x14))();
      if ((pbVar5 != (byte *)0x0) && (pbVar5 != pbStack_8)) {
        piVar12 = (int *)FUN_00573466(pbVar5);
        iVar9 = (**(code **)(*piVar12 + 0x88))(0x13);
        if (iVar9 == 0) {
          (**(code **)(*piVar12 + 0x38))();
        }
        else {
          iVar9 = (**(code **)(*piVar12 + 0x88))(0x2d);
          if ((iVar9 == 0) || (iVar9 = (**(code **)(*piVar12 + 0x88))(0x29), iVar9 != 0x13)) {
            (**(code **)(*piVar12 + 0x84))(0x2a,200,0);
            (**(code **)(*piVar12 + 0x84))(0x29,0x13,0);
            (**(code **)(*piVar12 + 0x84))(0x2d,1,0);
          }
          *(int *)pbVar13 = *(int *)(param_1 + 0x1a4);
          *(int *)(param_1 + 0x198) = *(int *)(DAT_006f6a78 + 0x58) + 2;
        }
      }
      *(byte **)(pbStack_c + DAT_006f6a78) = pbStack_8;
      return 1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdSeqGroupKi_006cf830;
    break;
  case 0x47:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      iVar9 = iVar9 * 4 + 0x1a4;
      pbVar13 = *(byte **)(DAT_006f6a78 + iVar9);
      pbStack_c = (byte *)(**(code **)(**(int **)(param_1 + 0xc4) + 0x14))();
      if ((pbVar13 != (byte *)0x0) && (pbVar13 != pbStack_c)) {
        FUN_00573466(pbVar13);
        (**(code **)(*(int *)param_1 + 0x38))();
      }
      *(byte **)(DAT_006f6a78 + iVar9) = pbStack_c;
      return 1;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdSeqGroupRe_006cf800;
    break;
  case 0x48:
    pbStack_8 = (byte *)FUN_0057f85a();
    if ((pbStack_8 == (byte *)0x0) || (0x7f < (int)pbStack_8)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdKillTrack_D_006cf61c;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 == 0) || (0x7f < iVar9)) {
        pcVar20 = s_TRACK_ERROR__kTrackCmdKillTrack_S_006cf690;
      }
      else {
        iVar7 = FUN_0057f85a();
        if ((iVar7 == 0) || (0x7f < iVar7)) {
          pcVar20 = s_TRACK_ERROR__kTrackCmdKillTrack_P_006cf644;
        }
        else {
          uVar6 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
          uVar15 = (**(code **)(*(int *)param_1 + 0x88))(iVar7);
          ppbVar19 = &pbStack_c;
          FUN_0057f854(uVar6,uVar15,ppbVar19);
          cVar4 = FUN_0057c0e7(uVar6,uVar15,ppbVar19);
          if (cVar4 != '\0') {
            iVar9 = *(int *)param_1;
            pbVar13 = pbStack_c;
            goto LAB_0057f647;
          }
          pcVar20 = s_Illegal_source_parameter_request_006cf66c;
        }
      }
    }
LAB_0057f6f2:
    FUN_0057f854(param_1,pcVar20);
LAB_0057f6fc:
    FUN_0057c0c5(param_1,pcVar20);
    return 1;
  case 0x49:
    iVar9 = FUN_0057f85a();
    if ((iVar9 != 0) && (iVar9 < 0x80)) {
      pbVar13 = (byte *)FUN_0057f85a();
      iVar7 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
      iVar9 = *(int *)param_1;
      uVar8 = *(uint *)(DAT_006f6a78 + iVar7 * 4 + 0x1a4);
      goto LAB_0057f4ad;
    }
    pcVar20 = s_TRACK_ERROR__kTrackCmdSeqGroupTr_006cf7d0;
    break;
  case 0x4a:
    iVar9 = FUN_0057f85a();
    if ((iVar9 == 0) || (0x7f < iVar9)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdSetLocalLo_006d0090;
    }
    else {
      iVar7 = FUN_0057f85a();
      if ((iVar7 != 0) && (iVar7 < 0x80)) {
        uVar6 = (**(code **)(*(int *)param_1 + 0x98))(iVar7);
LAB_0057e61f:
        cVar4 = (**(code **)(*(int *)param_1 + 0x94))(iVar9,uVar6,0);
        goto LAB_0057e4d3;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdSetLocalLo_006d00bc;
    }
    break;
  case 0x4b:
    iVar9 = FUN_0057f85a();
    if ((iVar9 == 0) || (0x7f < iVar9)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdSetLocalTa_006d0038;
    }
    else {
      iVar7 = FUN_0057f85a();
      if ((iVar7 != 0) && (iVar7 < 0x80)) {
        uVar6 = (**(code **)(*(int *)param_1 + 0x98))(iVar7);
        goto LAB_0057e5cb;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdSetLocalTa_006d0064;
    }
    break;
  case 0x4c:
    iVar9 = FUN_0057f85a();
    if ((iVar9 == 0) || (0x7f < iVar9)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdSetTargetL_006cffe0;
    }
    else {
      iVar7 = FUN_0057f85a();
      if ((iVar7 != 0) && (iVar7 < 0x80)) {
        uVar6 = (**(code **)(*(int *)param_1 + 0x88))(iVar7);
        goto LAB_0057e61f;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdSetTargetL_006d000c;
    }
    break;
  case 0x4d:
    pbStack_8 = (byte *)FUN_0057f85a();
    if ((pbStack_8 == (byte *)0x0) || (0x7f < (int)pbStack_8)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitEq_Src_006cff3c;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbStack_8);
        pbVar5 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(iVar9);
        if (pbStack_8 == pbVar5) {
          return 1;
        }
LAB_0057e9b3:
        *(int *)pbVar13 = *(int *)pbVar13 + -3;
LAB_0057e9b6:
        *(int *)(param_1 + 0x198) = *(int *)(DAT_006f6a78 + 0x58) + 2;
        return 1;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitEq_Des_006cff60;
    }
    break;
  case 0x4e:
    pbStack_8 = (byte *)FUN_0057f85a();
    if ((pbStack_8 == (byte *)0x0) || (0x7f < (int)pbStack_8)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitNe_Des_006cfef4;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbStack_8);
        pbVar5 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(iVar9);
        if (pbStack_8 != pbVar5) {
          return 1;
        }
        goto LAB_0057e9b3;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitNe_Src_006cff18;
    }
    break;
  case 0x4f:
    pbStack_8 = (byte *)FUN_0057f85a();
    if ((pbStack_8 == (byte *)0x0) || (0x7f < (int)pbStack_8)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitGt_Des_006cfea4;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbStack_8);
        iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        if (iVar9 < (int)pbStack_8) {
          return 1;
        }
        goto LAB_0057e9b3;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitGt_lDe_006cfec8;
    }
    break;
  case 0x50:
    pbStack_8 = (byte *)FUN_0057f85a();
    if ((pbStack_8 == (byte *)0x0) || (0x7f < (int)pbStack_8)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitLt_Des_006cfe54;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbStack_8);
        iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        if ((int)pbStack_8 < iVar9) {
          return 1;
        }
        goto LAB_0057e9b3;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitLt_lDe_006cfe78;
    }
    break;
  case 0x51:
    pbStack_8 = (byte *)FUN_0057f85a();
    if ((pbStack_8 == (byte *)0x0) || (0x7f < (int)pbStack_8)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitGe_Des_006cfe04;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbStack_8);
        iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        if (iVar9 <= (int)pbStack_8) {
          return 1;
        }
        goto LAB_0057e9b3;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitGe_lDe_006cfe28;
    }
    break;
  case 0x52:
    pbStack_8 = (byte *)FUN_0057f85a();
    if ((pbStack_8 == (byte *)0x0) || (0x7f < (int)pbStack_8)) {
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitLe_Des_006cfdb4;
    }
    else {
      iVar9 = FUN_0057f85a();
      if ((iVar9 != 0) && (iVar9 < 0x80)) {
        pbStack_8 = (byte *)(**(code **)(*(int *)param_1 + 0x88))(pbStack_8);
        iVar9 = (**(code **)(*(int *)param_1 + 0x88))(iVar9);
        if ((int)pbStack_8 <= iVar9) {
          return 1;
        }
        goto LAB_0057e9b3;
      }
      pcVar20 = s_TRACK_ERROR__kTrackCmdWaitLe_lDe_006cfdd8;
    }
    break;
  case 0x53:
    uVar6 = FUN_0057f85a();
    uVar6 = (**(code **)(*(int *)param_1 + 0x88))(uVar6);
    cVar4 = (**(code **)(*(int *)param_1 + 0xa8))(uVar6);
    if (cVar4 != '\0') {
      return 1;
    }
    pcVar20 = s_Could_not_chain_patch_006d0174;
  }
  (**(code **)(DAT_006f6a78 + 200))(param_1,pcVar20);
LAB_0057f701:
  return 1;
}

