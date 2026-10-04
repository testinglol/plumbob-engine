
undefined4 __thiscall FUN_005b89c0(undefined4 param_1,char *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  size_t *psVar6;
  size_t sVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  size_t local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  size_t local_8;
  
  piVar1 = param_3;
  local_10 = 0;
  cVar3 = *param_2;
  local_14 = param_1;
  pcVar4 = param_2;
  do {
    if (cVar3 == '\0') {
      pcVar4 = operator_new(local_10 + 1);
      FUN_006385fa(pcVar4,param_2,piVar1);
      if (pcVar4 != (char *)0x0) {
        sVar7 = _strlen(pcVar4);
        FUN_00431779(pcVar4,pcVar4 + sVar7);
      }
      FUN_006321f0(pcVar4);
      return local_14;
    }
    if (*pcVar4 == '%') {
      pcVar4 = (char *)FUN_006386ef(pcVar4);
      cVar3 = *pcVar4;
      if (cVar3 == '%') goto LAB_005b8cb0;
      iVar8 = 0;
      local_8 = 0;
      local_c = 0;
      if (cVar3 == '\0') {
LAB_005b8a4b:
        local_c = FUN_00635f62(pcVar4);
        while ((*pcVar4 != '\0' && (iVar5 = FUN_006368c3((int)*pcVar4), iVar5 != 0))) {
          pcVar4 = (char *)FUN_006386ef(pcVar4);
        }
      }
      else {
        do {
          if (cVar3 == '#') {
            local_10 = local_10 + 2;
          }
          else if (cVar3 == '*') {
            local_c = *param_3;
            param_3 = param_3 + 1;
          }
          else if ((((cVar3 != '-') && (cVar3 != '+')) && (cVar3 != '0')) && (cVar3 != ' ')) break;
          pcVar4 = (char *)FUN_006386ef(pcVar4);
          cVar3 = *pcVar4;
        } while (cVar3 != '\0');
        if (local_c == 0) goto LAB_005b8a4b;
      }
      if (*pcVar4 == '.') {
        pcVar4 = (char *)FUN_006386ef(pcVar4);
        if (*pcVar4 == '*') {
          iVar8 = *param_3;
          pcVar4 = (char *)FUN_006386ef(pcVar4);
          param_3 = param_3 + 1;
        }
        else {
          iVar8 = FUN_00635f62(pcVar4);
          while ((*pcVar4 != '\0' && (iVar5 = FUN_006368c3((int)*pcVar4), iVar5 != 0))) {
            pcVar4 = (char *)FUN_006386ef(pcVar4);
          }
        }
      }
      piVar2 = param_3;
      cVar3 = *pcVar4;
      uVar9 = 0;
      if (((cVar3 == 'F') || (cVar3 == 'L')) || (cVar3 == 'N')) {
LAB_005b8aeb:
        pcVar4 = (char *)FUN_006386ef(pcVar4);
      }
      else {
        if (cVar3 == 'h') {
          uVar9 = 0x10000;
          goto LAB_005b8aeb;
        }
        if (cVar3 == 'l') {
          uVar9 = 0x20000;
          goto LAB_005b8aeb;
        }
      }
      uVar9 = (int)*pcVar4 | uVar9;
      if ((int)uVar9 < 0x10054) {
        if (uVar9 == 0x10053) {
LAB_005b8bee:
          local_8 = _strlen((char *)*param_3);
          local_18 = 1;
          psVar6 = &local_8;
          if ((int)local_8 < 2) {
            psVar6 = &local_18;
          }
LAB_005b8c11:
          local_18 = 1;
          local_8 = *psVar6;
LAB_005b8c23:
          param_3 = param_3 + 1;
          if (local_8 == 0) goto LAB_005b8b37;
        }
        else {
          if (uVar9 != 0x43) {
            if (uVar9 == 0x53) {
              local_8 = _strlen((char *)*param_3);
              local_18 = 1;
              psVar6 = &local_8;
              if ((int)local_8 < 2) {
                psVar6 = &local_18;
              }
            }
            else {
              if (uVar9 == 99) goto LAB_005b8be1;
              if (uVar9 != 0x73) {
                if (uVar9 != 0x10043) goto LAB_005b8b37;
                goto LAB_005b8c18;
              }
              local_8 = _strlen((char *)*param_3);
              local_18 = 1;
              psVar6 = &local_8;
              if ((int)local_8 < 2) {
                psVar6 = &local_18;
              }
            }
            goto LAB_005b8c11;
          }
LAB_005b8be1:
          local_8 = 2;
        }
        param_3 = piVar2 + 1;
        local_18 = local_c + iVar8;
        psVar6 = &local_18;
        if (local_c + iVar8 <= (int)local_8) {
LAB_005b8ca9:
          psVar6 = &local_8;
        }
LAB_005b8cac:
        sVar7 = *psVar6;
      }
      else {
        if (uVar9 == 0x10063) {
LAB_005b8c18:
          local_8 = 2;
          goto LAB_005b8c23;
        }
        if (uVar9 == 0x10073) goto LAB_005b8bee;
        if ((uVar9 == 0x20043) || (uVar9 == 0x20063)) goto LAB_005b8be1;
LAB_005b8b37:
        cVar3 = *pcVar4;
        sVar7 = local_8;
        if ('n' < cVar3) {
          if (cVar3 != 'o') {
            if (cVar3 == 'p') {
              param_3 = param_3 + 1;
              local_18 = local_c + iVar8;
              bVar12 = SBORROW4(local_18,0x20);
              bVar11 = (int)(local_18 - 0x20) < 0;
              bVar10 = local_18 == 0x20;
              local_8 = 0x20;
              goto LAB_005b8ca7;
            }
            if (cVar3 != 'u') {
              bVar10 = cVar3 == 'x';
LAB_005b8c73:
              if (!bVar10) goto LAB_005b8cb7;
            }
          }
LAB_005b8c90:
          param_3 = param_3 + 1;
          local_18 = local_c + iVar8;
          bVar12 = SBORROW4(local_18,0x20);
          bVar11 = (int)(local_18 - 0x20) < 0;
          bVar10 = local_18 == 0x20;
          local_8 = 0x20;
LAB_005b8ca7:
          psVar6 = &local_18;
          if (bVar10 || bVar12 != bVar11) goto LAB_005b8ca9;
          goto LAB_005b8cac;
        }
        if (cVar3 != 'n') {
          if (cVar3 != 'G') {
            if ((cVar3 == 'X') || (cVar3 == 'd')) goto LAB_005b8c90;
            if (cVar3 < 'e') goto LAB_005b8cb7;
            if ('g' < cVar3) {
              bVar10 = cVar3 == 'i';
              goto LAB_005b8c73;
            }
          }
          param_3 = param_3 + 2;
          local_18 = local_c + iVar8;
          bVar12 = SBORROW4(local_18,0x80);
          bVar11 = (int)(local_18 - 0x80) < 0;
          bVar10 = local_18 == 0x80;
          local_8 = 0x80;
          goto LAB_005b8ca7;
        }
        param_3 = param_3 + 1;
      }
    }
    else {
LAB_005b8cb0:
      sVar7 = _strlen(pcVar4);
    }
LAB_005b8cb7:
    local_10 = local_10 + sVar7;
    pcVar4 = (char *)FUN_006386ef(pcVar4);
    cVar3 = *pcVar4;
  } while( true );
}

