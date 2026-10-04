
undefined4 __thiscall FUN_00470d9f(int param_1,char param_2,char param_3)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  int iVar8;
  size_t sVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  int *piVar12;
  uint uVar13;
  char *pcVar14;
  short *psVar15;
  uint uVar16;
  byte *pbVar17;
  undefined4 *puVar18;
  byte *pbVar19;
  undefined4 *puVar20;
  int iVar21;
  int iVar22;
  int local_10;
  byte *local_c;
  char local_5;
  
  if ((*(int **)(param_1 + 4) == (int *)0x0) ||
     (cVar4 = (**(code **)(**(int **)(param_1 + 4) + 0x28))(), cVar4 == '\0')) {
    uVar6 = 0xffffffff;
  }
  else {
    *(undefined2 *)(param_1 + 0x10) = 0;
    **(undefined1 **)(param_1 + 0xc) = 0;
    FUN_0047123b();
    uVar13 = ~-(uint)(*(char *)(param_1 + 0x5c) != '\0') & 0x470449;
    iVar5 = (**(code **)(**(int **)(param_1 + 4) + 0x38))
                      (*(undefined4 *)(param_1 + 0x58),
                       CONCAT22((short)(uVar13 >> 0x10),*(undefined2 *)(param_1 + 0x54)),uVar13);
    if (iVar5 == 0) {
      uVar6 = FUN_00401f6f();
    }
    else {
      (**(code **)(**(int **)(param_1 + 4) + 0x48))(iVar5,param_1 + 8);
      psVar7 = (short *)FUN_00420048(iVar5);
      if (*(char *)(param_1 + 0x5c) == '\0') {
        iVar8 = (int)*psVar7;
        if (iVar8 == -1) {
          sVar2 = psVar7[1];
          psVar7 = psVar7 + 2;
          if (0 < sVar2) {
            iVar8 = 1;
            do {
              sVar9 = _strlen((char *)psVar7);
              FUN_0047143b(iVar8,psVar7,*(undefined1 *)(param_1 + 0x5d));
              if (*(char *)(param_1 + 0x5d) != '\0') {
                FUN_0047143b(iVar8,psVar7,0);
              }
              psVar7 = (short *)((int)psVar7 + sVar9 + 1);
              bVar3 = iVar8 < sVar2;
              iVar8 = iVar8 + 1;
            } while (bVar3);
          }
        }
        else if (iVar8 == -2) {
          sVar2 = psVar7[1];
          psVar7 = psVar7 + 2;
          if (0 < sVar2) {
            iVar8 = 1;
            do {
              sVar9 = _strlen((char *)psVar7);
              FUN_0047143b(iVar8,psVar7,*(undefined1 *)(param_1 + 0x5d));
              if (*(char *)(param_1 + 0x5d) != '\0') {
                FUN_0047143b(iVar8,psVar7,0);
              }
              pcVar14 = (char *)((int)psVar7 + sVar9 + 1);
              FUN_004715d3(iVar8,pcVar14,*(undefined1 *)(param_1 + 0x5d));
              if (*(char *)(param_1 + 0x5d) != '\0') {
                FUN_004715d3(iVar8,pcVar14,0);
              }
              sVar9 = _strlen(pcVar14);
              psVar7 = (short *)(pcVar14 + sVar9 + 1);
              bVar3 = iVar8 < sVar2;
              iVar8 = iVar8 + 1;
            } while (bVar3);
          }
        }
        else if (iVar8 == -3) {
          iVar8 = (int)psVar7[1];
          local_5 = -1;
          iVar21 = 0;
          psVar15 = psVar7 + 2;
          local_10 = iVar8;
          if (0 < iVar8) {
            do {
              cVar4 = (char)*psVar15 + -1;
              if (cVar4 == -1) {
                cVar4 = *(char *)(param_1 + 0x5d);
              }
              if (local_5 != cVar4) {
                iVar21 = 0;
                local_5 = cVar4;
              }
              pcVar14 = (char *)((int)psVar15 + 1);
              if ((cVar4 == *(char *)(param_1 + 0x5d)) || (param_2 != '\0')) {
                sVar9 = _strlen(pcVar14);
                iVar21 = iVar21 + 1;
                FUN_0047143b(iVar21,pcVar14,cVar4);
                pcVar14 = (char *)((int)psVar15 + sVar9 + 2);
                FUN_004715d3(iVar21,pcVar14,cVar4);
                sVar9 = _strlen(pcVar14);
              }
              else {
                sVar9 = _strlen(pcVar14);
                pcVar14 = (char *)((int)psVar15 + sVar9 + 2);
                sVar9 = _strlen(pcVar14);
              }
              local_10 = local_10 + -1;
              psVar15 = (short *)(pcVar14 + sVar9 + 1);
            } while (local_10 != 0);
          }
          iVar21 = FUN_0046fc11(0xffffffff);
          if (((iVar21 == 0) && (param_3 != '\0')) && (0 < iVar8)) {
            _param_3 = 1;
            psVar7 = psVar7 + 2;
            local_10 = iVar8;
            do {
              psVar15 = (short *)((int)psVar7 + 1);
              if ((char)*psVar7 == '\x01') {
                sVar9 = _strlen((char *)psVar15);
                FUN_0047143b(_param_3,psVar15,*(undefined1 *)(param_1 + 0x5d));
                pcVar14 = (char *)((int)psVar7 + sVar9 + 2);
                FUN_004715d3(_param_3,pcVar14,*(undefined1 *)(param_1 + 0x5d));
                sVar9 = _strlen(pcVar14);
                _param_3 = _param_3 + 1;
                psVar15 = (short *)(pcVar14 + sVar9 + 1);
              }
              local_10 = local_10 + -1;
              psVar7 = psVar15;
            } while (local_10 != 0);
          }
        }
        else {
          local_c = (byte *)(psVar7 + 1);
          if (0 < iVar8) {
            _param_3 = 1;
            do {
              iVar21 = 1;
              if (*local_c != 0) {
                do {
                  if (local_c[iVar21] == 0xa1) {
                    local_c[iVar21] = 0x6f;
                  }
                  else if (local_c[iVar21] == 0xd5) {
                    local_c[iVar21] = 0x27;
                  }
                  iVar21 = iVar21 + 1;
                } while (iVar21 <= (int)(uint)*local_c);
              }
              bVar1 = *local_c;
              uVar16 = (uint)bVar1;
              pbVar10 = operator_new(uVar16 + 1);
              pbVar10[uVar16] = 0;
              pbVar17 = local_c + 1;
              pbVar19 = pbVar10;
              for (uVar13 = (uint)(bVar1 >> 2); uVar13 != 0; uVar13 = uVar13 - 1) {
                *(undefined4 *)pbVar19 = *(undefined4 *)pbVar17;
                pbVar17 = pbVar17 + 4;
                pbVar19 = pbVar19 + 4;
              }
              for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
                *pbVar19 = *pbVar17;
                pbVar17 = pbVar17 + 1;
                pbVar19 = pbVar19 + 1;
              }
              FUN_0047143b(_param_3,pbVar10,0xffffffff);
              if (*(char *)(param_1 + 0x5d) != '\0') {
                FUN_0047143b(_param_3,pbVar10,0);
              }
              local_c = local_c + *local_c + 1;
              FUN_006321f0(pbVar10);
              bVar3 = _param_3 < iVar8;
              _param_3 = _param_3 + 1;
            } while (bVar3);
          }
        }
      }
      else {
        iVar8 = FUN_00420096(iVar5);
        _param_3 = 0;
        local_c = (byte *)0x0;
        if (0 < iVar8) {
          do {
            iVar21 = (int)local_c + 1;
            iVar22 = _param_3;
            if ((*(char *)((int)psVar7 + (int)local_c) == '^') && (iVar22 = iVar21, _param_3 != 0))
            {
              uVar16 = (int)local_c - _param_3;
              puVar11 = operator_new(uVar16 + 1);
              puVar18 = (undefined4 *)((int)psVar7 + _param_3);
              puVar20 = puVar11;
              for (uVar13 = uVar16 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                *puVar20 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar20 = puVar20 + 1;
              }
              for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
                *(undefined1 *)puVar20 = *(undefined1 *)puVar18;
                puVar18 = (undefined4 *)((int)puVar18 + 1);
                puVar20 = (undefined4 *)((int)puVar20 + 1);
              }
              *(undefined1 *)((int)puVar11 + ((int)local_c - _param_3)) = 0;
              FUN_0047143b(((*(int **)(param_1 + 0x6c))[1] - **(int **)(param_1 + 0x6c)) / 0xc + 1,
                           puVar11,0xffffffff);
              if (*(char *)(param_1 + 0x5d) != '\0') {
                FUN_0047143b(((*(int **)(param_1 + 0x6c))[1] - **(int **)(param_1 + 0x6c)) / 0xc + 1
                             ,puVar11,0);
              }
              FUN_006321f0(puVar11);
              _param_3 = 0;
              iVar22 = _param_3;
            }
            _param_3 = iVar22;
            local_c = (byte *)iVar21;
          } while (iVar21 < iVar8);
        }
      }
      FUN_00465a06(iVar5);
      if (param_2 != '\0') {
        iVar5 = 0xc;
        _param_3 = 1;
        iVar8 = ((*(int **)(param_1 + 0x6c))[1] - **(int **)(param_1 + 0x6c)) / 0xc;
        do {
          iVar21 = 0xc;
          piVar12 = (int *)(iVar5 + *(int *)(param_1 + 0x6c));
          if (((piVar12[1] - *piVar12) / 0xc == 0) && (_param_2 = 1, 0 < iVar8)) {
            do {
              iVar22 = _param_3;
              uVar6 = FUN_00471509(_param_2,0);
              FUN_0047132c(_param_2,uVar6,iVar22);
              iVar21 = iVar21 + 0xc;
              *(undefined1 *)(*(int *)(iVar5 + *(int *)(param_1 + 0x6c)) + -0x10 + iVar21) = 0;
              _param_2 = _param_2 + 1;
            } while (_param_2 <= iVar8);
          }
          _param_3 = _param_3 + 1;
          iVar5 = iVar5 + 0xc;
        } while (iVar5 < 0xf0);
      }
      uVar6 = 0;
    }
  }
  return uVar6;
}

