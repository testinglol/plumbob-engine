
undefined4 __thiscall FUN_005d4dcd(undefined4 param_1,char *param_2,int *param_3)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  size_t sVar7;
  int *piVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = param_3;
  local_c = 0;
  piVar8 = param_3;
  pcVar3 = param_2;
  local_14 = param_1;
  do {
    if (*pcVar3 == '\0') {
      pcVar3 = operator_new(local_c + 1);
      (*(code *)PTR_FUN_006d6ff0)(pcVar3,param_2,piVar1);
      if (pcVar3 != (char *)0x0) {
        sVar7 = _strlen(pcVar3);
        FUN_00431779(pcVar3,pcVar3 + sVar7);
      }
      FUN_006321f0(pcVar3);
      return local_14;
    }
    if (*pcVar3 == '%') {
      pcVar3 = (char *)(*(code *)PTR_FUN_006d70b8)(pcVar3);
      cVar2 = *pcVar3;
      if (cVar2 == '%') goto LAB_005d50f8;
      param_3 = (int *)0x0;
      local_8 = 0;
      if (cVar2 == '\0') {
LAB_005d4e54:
        local_8 = (*(code *)PTR_FUN_006d7014)(pcVar3);
        while ((*pcVar3 != '\0' && (iVar4 = (*(code *)PTR_FUN_006d70e0)((int)*pcVar3), iVar4 != 0)))
        {
          pcVar3 = (char *)(*(code *)PTR_FUN_006d70b8)(pcVar3);
        }
      }
      else {
        do {
          if (cVar2 == '#') {
            local_c = local_c + 2;
          }
          else if (cVar2 == '*') {
            local_8 = *piVar8;
            piVar8 = piVar8 + 1;
          }
          else if ((((cVar2 != '-') && (cVar2 != '+')) && (cVar2 != '0')) && (cVar2 != ' ')) break;
          pcVar3 = (char *)(*(code *)PTR_FUN_006d70b8)(pcVar3);
          cVar2 = *pcVar3;
        } while (cVar2 != '\0');
        if (local_8 == 0) goto LAB_005d4e54;
      }
      local_10 = 0;
      if (*pcVar3 == '.') {
        pcVar3 = (char *)(*(code *)PTR_FUN_006d70b8)(pcVar3);
        if (*pcVar3 == '*') {
          local_10 = *piVar8;
          piVar8 = piVar8 + 1;
          pcVar3 = (char *)(*(code *)PTR_FUN_006d70b8)(pcVar3);
        }
        else {
          local_10 = (*(code *)PTR_FUN_006d7014)(pcVar3);
          while ((*pcVar3 != '\0' && (iVar4 = (*(code *)PTR_FUN_006d70e0)((int)*pcVar3), iVar4 != 0)
                 )) {
            pcVar3 = (char *)(*(code *)PTR_FUN_006d70b8)(pcVar3);
          }
        }
      }
      cVar2 = *pcVar3;
      uVar9 = 0;
      if (cVar2 == 'F') {
LAB_005d4f07:
        pcVar3 = (char *)(*(code *)PTR_FUN_006d70b8)(pcVar3);
      }
      else {
        if (cVar2 != 'I') {
          if ((cVar2 != 'L') && (cVar2 != 'N')) {
            if (cVar2 == 'h') {
              uVar9 = 0x10000;
            }
            else {
              if (cVar2 != 'l') goto LAB_005d4f11;
              uVar9 = 0x20000;
            }
          }
          goto LAB_005d4f07;
        }
        uVar5 = (*(code *)PTR_FUN_006d70b8)(pcVar3);
        uVar5 = (*(code *)PTR_FUN_006d70b8)(uVar5);
        pcVar3 = (char *)(*(code *)PTR_FUN_006d70b8)(uVar5);
        piVar8 = piVar8 + 2;
        param_3 = (int *)0x80;
      }
LAB_005d4f11:
      uVar9 = (int)*pcVar3 | uVar9;
      if ((int)uVar9 < 0x10064) {
        if ((uVar9 == 0x10063) || (uVar9 == 0x43)) goto LAB_005d500a;
        if (uVar9 != 0x53) {
          if (uVar9 != 99) {
            if (uVar9 == 0x73) {
              iVar4 = (*(code *)PTR__strlen_006d7028)(*piVar8);
              local_18 = 1;
              param_3 = (int *)&param_3;
              if (iVar4 < 2) {
                param_3 = &local_18;
              }
              goto LAB_005d5034;
            }
            if (uVar9 != 0x10043) {
              if (uVar9 != 0x10053) goto LAB_005d5039;
              goto LAB_005d5015;
            }
          }
          goto LAB_005d500a;
        }
        iVar4 = (*(code *)PTR_FUN_006d7108)(*piVar8);
        local_18 = 1;
        param_3 = (int *)&param_3;
        if (iVar4 < 2) {
          param_3 = &local_18;
        }
LAB_005d5034:
        local_18 = 1;
        piVar8 = piVar8 + 1;
        param_3 = (int *)*param_3;
LAB_005d5039:
        if (param_3 != (int *)0x0) goto LAB_005d5040;
        cVar2 = *pcVar3;
        iVar4 = 0;
        if ('n' < cVar2) {
          if (cVar2 != 'o') {
            if (cVar2 == 'p') {
              local_18 = local_10 + local_8;
              piVar8 = piVar8 + 1;
              bVar12 = SBORROW4(local_18,0x20);
              bVar11 = local_18 + -0x20 < 0;
              bVar10 = local_18 == 0x20;
              param_3 = (int *)0x20;
              goto LAB_005d50ea;
            }
            if (cVar2 != 'u') {
              bVar10 = cVar2 == 'x';
LAB_005d50b2:
              if (!bVar10) goto LAB_005d50f1;
            }
          }
LAB_005d50d1:
          local_18 = local_10 + local_8;
          piVar8 = piVar8 + 1;
          bVar12 = SBORROW4(local_18,0x20);
          bVar11 = local_18 + -0x20 < 0;
          bVar10 = local_18 == 0x20;
          param_3 = (int *)0x20;
LAB_005d50ea:
          piVar6 = &local_18;
          if (bVar10 || bVar12 != bVar11) goto LAB_005d50ec;
          goto LAB_005d50ef;
        }
        if (cVar2 != 'n') {
          if (cVar2 != 'G') {
            if ((cVar2 == 'X') || (cVar2 == 'd')) goto LAB_005d50d1;
            if (cVar2 < 'e') goto LAB_005d50f1;
            if ('g' < cVar2) {
              bVar10 = cVar2 == 'i';
              goto LAB_005d50b2;
            }
          }
          local_18 = local_10 + local_8;
          piVar8 = piVar8 + 2;
          bVar12 = SBORROW4(local_18,0x80);
          bVar11 = local_18 + -0x80 < 0;
          bVar10 = local_18 == 0x80;
          param_3 = (int *)0x80;
          goto LAB_005d50ea;
        }
        piVar8 = piVar8 + 1;
      }
      else {
        if (uVar9 == 0x10073) {
LAB_005d5015:
          iVar4 = (*(code *)PTR__strlen_006d7110)(*piVar8);
          local_18 = 1;
          param_3 = (int *)&param_3;
          if (iVar4 < 2) {
            param_3 = &local_18;
          }
          goto LAB_005d5034;
        }
        if (uVar9 != 0x20043) {
          if (uVar9 == 0x20053) {
LAB_005d4fe9:
            iVar4 = (*(code *)PTR_FUN_006d710c)(*piVar8);
            local_18 = 1;
            param_3 = (int *)&param_3;
            if (iVar4 < 2) {
              param_3 = &local_18;
            }
            goto LAB_005d5034;
          }
          if (uVar9 != 0x20063) {
            if (uVar9 == 0x20073) goto LAB_005d4fe9;
            goto LAB_005d5039;
          }
        }
LAB_005d500a:
        piVar8 = piVar8 + 1;
        param_3 = (int *)0x2;
LAB_005d5040:
        local_18 = local_10 + local_8;
        piVar6 = &local_18;
        if (local_10 + local_8 <= (int)param_3) {
LAB_005d50ec:
          piVar6 = (int *)&param_3;
        }
LAB_005d50ef:
        iVar4 = *piVar6;
      }
LAB_005d50f1:
      local_c = local_c + iVar4;
    }
    else {
LAB_005d50f8:
      iVar4 = (*(code *)PTR__strlen_006d7028)(pcVar3);
      local_c = local_c + iVar4;
    }
    pcVar3 = (char *)(*(code *)PTR_FUN_006d70b8)(pcVar3);
  } while( true );
}

