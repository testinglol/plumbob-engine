
undefined4 __thiscall FUN_0046ffa4(int param_1,char param_2,char param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  int iVar8;
  size_t sVar9;
  int iVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  uint uVar13;
  char *pcVar14;
  short *psVar15;
  uint uVar16;
  byte *pbVar17;
  undefined4 *puVar18;
  byte *pbVar19;
  undefined4 *puVar20;
  int local_14;
  int local_c;
  char local_5;
  
  if ((*(int **)(param_1 + 4) == (int *)0x0) ||
     (cVar4 = (**(code **)(**(int **)(param_1 + 4) + 0x28))(), cVar4 == '\0')) {
    uVar6 = 0xffffffff;
  }
  else {
    *(undefined2 *)(param_1 + 0x10) = 0;
    **(undefined1 **)(param_1 + 0xc) = 0;
    FUN_0047031c();
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
          iVar8 = 0;
          if (0 < sVar2) {
            do {
              sVar9 = _strlen((char *)psVar7);
              iVar8 = iVar8 + 1;
              FUN_0047057a(iVar8,psVar7,*(undefined1 *)(param_1 + 0x5d));
              psVar7 = (short *)((int)psVar7 + sVar9 + 1);
            } while (iVar8 < sVar2);
          }
        }
        else if (iVar8 == -2) {
          sVar2 = psVar7[1];
          psVar7 = psVar7 + 2;
          iVar8 = 0;
          if (0 < sVar2) {
            do {
              sVar9 = _strlen((char *)psVar7);
              iVar8 = iVar8 + 1;
              FUN_0047057a(iVar8,psVar7,*(undefined1 *)(param_1 + 0x5d));
              pcVar14 = (char *)((int)psVar7 + sVar9 + 1);
              sVar9 = _strlen(pcVar14);
              psVar7 = (short *)(pcVar14 + sVar9 + 1);
            } while (iVar8 < sVar2);
          }
        }
        else if (iVar8 == -3) {
          iVar8 = (int)psVar7[1];
          local_c = 0;
          local_5 = -1;
          psVar15 = psVar7 + 2;
          local_14 = iVar8;
          if (0 < iVar8) {
            do {
              cVar4 = (char)*psVar15 + -1;
              if (cVar4 == -1) {
                cVar4 = *(char *)(param_1 + 0x5d);
              }
              if (local_5 != cVar4) {
                local_c = 0;
                local_5 = cVar4;
              }
              pcVar14 = (char *)((int)psVar15 + 1);
              if ((cVar4 == *(char *)(param_1 + 0x5d)) || (param_2 != '\0')) {
                sVar9 = _strlen(pcVar14);
                local_c = local_c + 1;
                FUN_0047057a(local_c,pcVar14,cVar4);
                pcVar14 = (char *)((int)psVar15 + sVar9 + 2);
                sVar9 = _strlen(pcVar14);
                psVar15 = (short *)(pcVar14 + sVar9 + 1);
              }
              else {
                sVar9 = _strlen(pcVar14);
                pcVar14 = (char *)((int)psVar15 + sVar9 + 2);
                sVar9 = _strlen(pcVar14);
                psVar15 = (short *)(pcVar14 + sVar9 + 1);
              }
              local_14 = local_14 + -1;
            } while (local_14 != 0);
          }
          iVar10 = FUN_0046fbe5(0xffffffff);
          if (((iVar10 == 0) && (param_3 != '\0')) && (0 < iVar8)) {
            _param_2 = (byte *)0x1;
            psVar7 = psVar7 + 2;
            _param_3 = iVar8;
            do {
              psVar15 = (short *)((int)psVar7 + 1);
              if ((char)*psVar7 == '\x01') {
                sVar9 = _strlen((char *)psVar15);
                FUN_004704a5(_param_2,psVar15,*(undefined1 *)(param_1 + 0x5d));
                pcVar14 = (char *)((int)psVar7 + sVar9 + 2);
                sVar9 = _strlen(pcVar14);
                _param_2 = (byte *)((int)_param_2 + 1);
                psVar15 = (short *)(pcVar14 + sVar9 + 1);
              }
              _param_3 = _param_3 + -1;
              psVar7 = psVar15;
            } while (_param_3 != 0);
          }
        }
        else {
          _param_3 = 0;
          _param_2 = (byte *)(psVar7 + 1);
          if (0 < iVar8) {
            do {
              iVar10 = 1;
              if (*_param_2 != 0) {
                do {
                  if (_param_2[iVar10] == 0xa1) {
                    _param_2[iVar10] = 0x6f;
                  }
                  else if (_param_2[iVar10] == 0xd5) {
                    _param_2[iVar10] = 0x27;
                  }
                  iVar10 = iVar10 + 1;
                } while (iVar10 <= (int)(uint)*_param_2);
              }
              bVar1 = *_param_2;
              uVar16 = (uint)bVar1;
              pbVar11 = operator_new(uVar16 + 1);
              pbVar11[uVar16] = 0;
              pbVar17 = _param_2 + 1;
              pbVar19 = pbVar11;
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
              _param_3 = _param_3 + 1;
              FUN_0047057a(_param_3,pbVar11,0xffffffff);
              _param_2 = _param_2 + *_param_2 + 1;
              FUN_006321f0(pbVar11);
            } while (_param_3 < iVar8);
          }
        }
      }
      else {
        iVar8 = FUN_00420096(iVar5);
        _param_2 = (byte *)0x0;
        _param_3 = 0;
        if (0 < iVar8) {
          do {
            iVar10 = _param_3 + 1;
            iVar3 = (int)_param_2;
            if ((*(char *)((int)psVar7 + _param_3) == '^') &&
               (iVar3 = iVar10, _param_2 != (byte *)0x0)) {
              uVar16 = _param_3 - (int)_param_2;
              puVar12 = operator_new(uVar16 + 1);
              puVar18 = (undefined4 *)((int)psVar7 + (int)_param_2);
              puVar20 = puVar12;
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
              *(undefined1 *)((int)puVar12 + (_param_3 - (int)_param_2)) = 0;
              FUN_0047057a((*(int *)(param_1 + 100) - *(int *)(param_1 + 0x60) >> 2) + 1,puVar12,
                           0xffffffff);
              FUN_006321f0(puVar12);
              _param_2 = (byte *)0x0;
              iVar3 = (int)_param_2;
            }
            _param_2 = (byte *)iVar3;
            _param_3 = iVar10;
          } while (iVar10 < iVar8);
        }
      }
      FUN_00465a06(iVar5);
      uVar6 = 0;
    }
  }
  return uVar6;
}

