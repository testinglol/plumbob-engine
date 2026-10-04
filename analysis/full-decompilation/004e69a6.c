
void FUN_004e69a6(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int unaff_EDI;
  undefined **ppuVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 uVar12;
  
  cVar1 = FUN_005d6516(s_factory_006c9dc0,0,1);
  if (cVar1 != '\0') {
    FUN_004e7045();
    return;
  }
  iVar2 = (**(code **)(*param_1 + 0x10))(&PTR_LAB_006c9dbc);
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar11 = &DAT_006c7110;
      pcVar4 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar4,pcVar11);
      if (iVar3 == 0) {
        uVar12 = 1;
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar4 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar4,(char *)ppuVar6);
        if (iVar2 != 0) goto LAB_004e6a35;
        uVar12 = 0;
      }
      FUN_004e60c8(uVar12);
    }
  }
LAB_004e6a35:
  iVar2 = (**(code **)(*param_1 + 0x10))(s__shadows_006c9db0);
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar11 = &DAT_006c7110;
      pcVar4 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar4,pcVar11);
      if (iVar3 == 0) {
        DAT_006f0138 = 1;
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar4 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar4,(char *)ppuVar6);
        if (iVar2 != 0) goto LAB_004e6a9d;
        DAT_006f0138 = 0;
      }
      if (*(int **)(DAT_006e486c + 4) != (int *)0x0) {
        (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
      }
    }
  }
LAB_004e6a9d:
  iVar2 = (**(code **)(*param_1 + 0x10))(s__lighting_006c9da4);
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar11 = &DAT_006c7110;
      pcVar4 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar4,pcVar11);
      if (iVar3 == 0) {
        DAT_006f013a = 1;
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar4 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar4,(char *)ppuVar6);
        if (iVar2 != 0) goto LAB_004e6b05;
        DAT_006f013a = 0;
      }
      if (*(int **)(DAT_006e486c + 4) != (int *)0x0) {
        (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
      }
    }
  }
LAB_004e6b05:
  iVar2 = (**(code **)(*param_1 + 0x10))(s__transui_006c9d98);
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar11 = &DAT_006c7110;
      pcVar4 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar4,pcVar11);
      if (iVar3 == 0) {
        *(undefined1 *)(unaff_EDI + 1) = 1;
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar4 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar4,(char *)ppuVar6);
        if (iVar2 == 0) {
          *(undefined1 *)(unaff_EDI + 1) = 0;
        }
      }
    }
  }
  pcVar4 = s__autocenter_006c9d8c;
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar10 = &DAT_006c7110;
      pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar11,pcVar10);
      if (iVar3 == 0) {
        DAT_006c2971 = 1;
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar11,(char *)ppuVar6);
        if (iVar2 == 0) {
          DAT_006c2971 = 0;
        }
      }
    }
  }
  pcVar11 = s__freewill_006c9d80;
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar9 = &DAT_006c7110;
      pcVar10 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar10,pcVar9);
      if (iVar3 == 0) {
        uVar12 = 1;
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar10 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar10,(char *)ppuVar6);
        if (iVar2 != 0) goto LAB_004e6c09;
        uVar12 = 0;
      }
      FUN_004322cf(uVar12);
    }
  }
LAB_004e6c09:
  pcVar10 = s__edgescroll_006c9d74;
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar8 = &DAT_006c7110;
      pcVar9 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar9,pcVar8);
      if (iVar3 == 0) {
        uVar12 = 1;
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar9 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar9,(char *)ppuVar6);
        if (iVar2 != 0) goto LAB_004e6c5f;
        uVar12 = 0;
      }
      FUN_004e6387(uVar12);
    }
  }
LAB_004e6c5f:
  pcVar9 = s__simbkg_006c9d6c;
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar7 = &DAT_006c7110;
      pcVar8 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar8,pcVar7);
      if (iVar3 == 0) {
        DAT_006c9f91 = 0;
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar8 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar8,(char *)ppuVar6);
        if (iVar2 == 0) {
          DAT_006c9f91 = 1;
        }
      }
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x10))(s__quicktips_006c9d60);
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar7 = &DAT_006c7110;
      pcVar8 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar8,pcVar7);
      if (iVar3 == 0) {
        pcVar4[2] = '\x01';
        DAT_006d7444 = 0;
        DAT_006d74f0 = 0xfa;
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar8 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar8,(char *)ppuVar6);
        if (iVar2 == 0) {
          pcVar4[2] = '\0';
          DAT_006d7444 = 0x2ee;
          DAT_006d74f0 = 0x14d;
        }
      }
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x10))(s__snapshots_006c9d54);
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar8 = &DAT_006c7110;
      pcVar4 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar4,pcVar8);
      if (iVar3 == 0) {
        pcVar11[3] = '\x01';
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar4 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar4,(char *)ppuVar6);
        if (iVar2 == 0) {
          pcVar11[3] = '\0';
        }
      }
    }
  }
  pcVar4 = s__livepip_006c9d48;
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar8 = &DAT_006c7110;
      pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar11,pcVar8);
      if (iVar3 == 0) {
        pcVar10[4] = '\x01';
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar11,(char *)ppuVar6);
        if (iVar2 == 0) {
          pcVar10[4] = '\0';
        }
      }
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x10))(s__exporthtml_006c9d3c);
  if (-1 < iVar2) {
    iVar2 = iVar2 + 1;
    iVar3 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 < iVar3) {
      pcVar10 = &DAT_006c7110;
      pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar11,pcVar10);
      if (iVar3 == 0) {
        pcVar9[5] = '\x01';
      }
      else {
        ppuVar6 = &PTR_DAT_006c710c;
        pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar11,(char *)ppuVar6);
        if (iVar2 == 0) {
          pcVar9[5] = '\0';
        }
      }
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x10))(s__terrdtl_006c9d30);
  if (((-1 < iVar2) && (iVar2 = iVar2 + 1, -1 < iVar2)) &&
     (iVar3 = (**(code **)(*param_1 + 0xc))(), iVar2 < iVar3)) {
    pcVar10 = &DAT_006c3a18;
    pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
    iVar3 = _strcmp(pcVar11,pcVar10);
    if (iVar3 == 0) {
      uVar12 = 0;
    }
    else {
      pcVar10 = &DAT_006c100c;
      pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar11,pcVar10);
      if (iVar3 == 0) {
        uVar12 = 1;
      }
      else {
        pcVar10 = &DAT_006c3a24;
        pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar11,pcVar10);
        if (iVar2 != 0) goto LAB_004e6ec2;
        uVar12 = 2;
      }
    }
    FUN_004e6166(uVar12);
  }
LAB_004e6ec2:
  iVar2 = (**(code **)(*param_1 + 0x10))(s__chardtl_006c9d24);
  if (((-1 < iVar2) && (iVar2 = iVar2 + 1, -1 < iVar2)) &&
     (iVar3 = (**(code **)(*param_1 + 0xc))(), iVar2 < iVar3)) {
    pcVar10 = &DAT_006c3a18;
    pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
    iVar3 = _strcmp(pcVar11,pcVar10);
    if (iVar3 == 0) {
      uVar12 = 0;
    }
    else {
      pcVar10 = &DAT_006c100c;
      pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
      iVar3 = _strcmp(pcVar11,pcVar10);
      if (iVar3 == 0) {
        uVar12 = 1;
      }
      else {
        pcVar10 = &DAT_006c3a24;
        pcVar11 = (char *)(**(code **)(*param_1 + 8))(iVar2);
        iVar2 = _strcmp(pcVar11,pcVar10);
        if (iVar2 != 0) goto LAB_004e6f37;
        uVar12 = 2;
      }
    }
    FUN_004e61c6(uVar12);
  }
LAB_004e6f37:
  iVar3 = (**(code **)(*param_1 + 0x10))(s__soundfx_006c9d18);
  iVar2 = 10;
  if (((-1 < iVar3) && (iVar3 = iVar3 + 1, -1 < iVar3)) &&
     (iVar5 = (**(code **)(*param_1 + 0xc))(), iVar3 < iVar5)) {
    uVar12 = (**(code **)(*param_1 + 8))(iVar3);
    iVar3 = FUN_00635f62(uVar12);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (10 < iVar3) {
      iVar3 = iVar2;
    }
    *(int *)(pcVar4 + 0x14) = iVar3;
    if (*(int *)(DAT_006e486c + 0x10) != 0) {
      FUN_0057afae(iVar3);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x10))(s__soundmusic_006c9d0c);
  if (((-1 < iVar3) && (iVar3 = iVar3 + 1, -1 < iVar3)) &&
     (iVar5 = (**(code **)(*param_1 + 0xc))(), iVar3 < iVar5)) {
    uVar12 = (**(code **)(*param_1 + 8))(iVar3);
    iVar3 = FUN_00635f62(uVar12);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (10 < iVar3) {
      iVar3 = iVar2;
    }
    *(int *)(pcVar4 + 0x18) = iVar3;
    if (*(int *)(DAT_006e486c + 0x10) != 0) {
      FUN_0057b015(iVar3);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x10))(s__soundvox_006c9d00);
  if (((-1 < iVar3) && (iVar3 = iVar3 + 1, -1 < iVar3)) &&
     (iVar5 = (**(code **)(*param_1 + 0xc))(), iVar3 < iVar5)) {
    uVar12 = (**(code **)(*param_1 + 8))(iVar3);
    iVar3 = FUN_00635f62(uVar12);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (10 < iVar3) {
      iVar3 = iVar2;
    }
    *(int *)(pcVar4 + 0x1c) = iVar3;
    if (*(int *)(DAT_006e486c + 0x10) != 0) {
      FUN_0057b07c(iVar3);
    }
  }
  return;
}

