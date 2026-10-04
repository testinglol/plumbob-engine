
uint FUN_005bfeb2(LPCWSTR param_1,uint param_2,UINT param_3,LPWSTR param_4,uint *param_5,
                 UINT param_6)

{
  LPCWSTR pWVar1;
  byte *pbVar2;
  byte bVar3;
  WCHAR WVar4;
  LPWSTR pWVar5;
  UINT CodePage;
  UINT CodePage_00;
  LPCWSTR pWVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  LPWSTR pWVar11;
  uint *puVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  LPCWSTR pWVar16;
  int iVar17;
  
  uVar9 = param_2;
  if (param_2 == 0) goto LAB_005c03ff;
  if ((param_3 == 0xfffffffe) || (CodePage = param_3, param_3 == 0xffffffff)) {
    CodePage = FUN_005bfe47();
  }
  if ((param_6 == 0xfffffffe) || (CodePage_00 = param_6, param_6 == 0xffffffff)) {
    CodePage_00 = FUN_005bfe47();
  }
  puVar8 = param_5;
  if (CodePage != 0x10) {
    uVar10 = 0;
    if (uVar9 != 0) {
      do {
        if (0x7f < *(byte *)(uVar10 + (int)param_1)) goto LAB_005bff13;
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar9);
    }
    CodePage = 0;
  }
LAB_005bff13:
  if ((CodePage == CodePage_00) || ((CodePage == 0 && (CodePage_00 != 0x10)))) {
LAB_005c0409:
    if (param_1 != param_4) {
      puVar12 = param_5;
      if (uVar9 <= *param_5) {
        puVar12 = &param_2;
      }
      uVar9 = *puVar12;
      uVar10 = uVar9;
      if (CodePage_00 == 0x10) {
        uVar10 = uVar9 * 2;
      }
      FUN_00636510(param_4,param_1,uVar10);
    }
    *puVar8 = uVar9;
    return uVar9;
  }
  if (CodePage == 0x10) {
    if (CodePage_00 == 0) {
      if (uVar9 <= *param_5) {
        puVar8 = &param_2;
      }
      uVar9 = *puVar8;
      pWVar6 = param_1 + uVar9;
      for (; param_1 < pWVar6; param_1 = param_1 + 1) {
        *(char *)param_4 = (char)*param_1;
        param_4 = (LPWSTR)((int)param_4 + 1);
      }
      *param_5 = uVar9;
      return uVar9;
    }
  }
  else if (CodePage_00 == 0) goto LAB_005c0409;
  if (param_1 == param_4) {
    return 0;
  }
  if (CodePage == 8) {
    if (CodePage_00 == 0x10) {
      pWVar16 = (LPCWSTR)(uVar9 + (int)param_1);
      uVar9 = *param_5;
      pWVar6 = param_1;
      pWVar11 = param_4;
      if (param_1 < pWVar16) {
        iVar17 = (int)pWVar16 - (int)param_1;
        while (pWVar11 < param_4 + uVar9) {
          bVar3 = (byte)*pWVar6;
          if (bVar3 < 0x80) {
            pWVar6 = (LPCWSTR)((int)pWVar6 + 1);
            *pWVar11 = (ushort)bVar3;
            iVar17 = iVar17 + -1;
          }
          else {
            if (bVar3 < 0xc2) break;
            if (bVar3 < 0xe0) {
              if ((iVar17 < 2) || (bVar13 = *(byte *)((int)pWVar6 + 1) ^ 0x80, 0x3f < bVar13))
              break;
              pWVar6 = pWVar6 + 1;
              *pWVar11 = (ushort)(bVar3 & 0x1f) << 6 | (ushort)bVar13;
              iVar17 = iVar17 + -2;
            }
            else if (bVar3 < 0xf0) {
              if (iVar17 < 3) break;
              bVar13 = *(byte *)((int)pWVar6 + 1) ^ 0x80;
              if (((0x3f < bVar13) || (bVar14 = (byte)pWVar6[1] ^ 0x80, 0x3f < bVar14)) ||
                 ((bVar3 < 0xe1 && (*(byte *)((int)pWVar6 + 1) < 0xa0)))) break;
              pWVar6 = (LPCWSTR)((int)pWVar6 + 3);
              iVar17 = iVar17 + -3;
              *pWVar11 = ((ushort)(bVar3 & 0xf) << 6 | (ushort)bVar13) << 6 | (ushort)bVar14;
            }
            else if (bVar3 < 0xf8) {
              if ((((iVar17 < 4) || (bVar13 = *(byte *)((int)pWVar6 + 1), 0x3f < (bVar13 ^ 0x80)))
                  || ((bVar14 = (byte)pWVar6[1] ^ 0x80, 0x3f < bVar14 ||
                      (bVar15 = *(byte *)((int)pWVar6 + 3) ^ 0x80, 0x3f < bVar15)))) ||
                 ((bVar3 < 0xf1 && (bVar13 < 0x90)))) break;
              pWVar6 = pWVar6 + 2;
              iVar17 = iVar17 + -4;
              *pWVar11 = ((ushort)bVar13 << 6 | (ushort)bVar14) << 6 | (ushort)bVar15;
            }
            else if (bVar3 < 0xfc) {
              if ((((iVar17 < 5) || (0x3f < (*(byte *)((int)pWVar6 + 1) ^ 0x80))) ||
                  (pWVar1 = pWVar6 + 1, 0x3f < (byte)((byte)*pWVar1 ^ 0x80))) ||
                 (((bVar13 = *(byte *)((int)pWVar6 + 3) ^ 0x80, 0x3f < bVar13 ||
                   (bVar14 = (byte)pWVar6[2] ^ 0x80, 0x3f < bVar14)) ||
                  ((bVar3 < 0xf9 && (*(byte *)((int)pWVar6 + 1) < 0x88)))))) break;
              pWVar6 = (LPCWSTR)((int)pWVar6 + 5);
              iVar17 = iVar17 + -5;
              *pWVar11 = ((ushort)(byte)*pWVar1 << 6 | (ushort)bVar13) << 6 | (ushort)bVar14;
            }
            else {
              if (((((0xfd < bVar3) || (iVar17 < 6)) || (0x3f < (*(byte *)((int)pWVar6 + 1) ^ 0x80))
                   ) || ((0x3f < (byte)((byte)pWVar6[1] ^ 0x80) ||
                         (pbVar2 = (byte *)((int)pWVar6 + 3), 0x3f < (*pbVar2 ^ 0x80))))) ||
                 (((bVar13 = (byte)pWVar6[2] ^ 0x80, 0x3f < bVar13 ||
                   (bVar14 = *(byte *)((int)pWVar6 + 5) ^ 0x80, 0x3f < bVar14)) ||
                  ((bVar3 < 0xfd && (*(byte *)((int)pWVar6 + 1) < 0x84)))))) break;
              pWVar6 = pWVar6 + 3;
              iVar17 = iVar17 + -6;
              *pWVar11 = ((ushort)*pbVar2 << 6 | (ushort)bVar13) << 6 | (ushort)bVar14;
            }
          }
          pWVar11 = pWVar11 + 1;
          if (pWVar16 <= pWVar6) break;
        }
      }
      *param_5 = (int)pWVar11 - (int)param_4 >> 1;
      return (int)pWVar6 - (int)param_1;
    }
    goto LAB_005c037c;
  }
  if (CodePage == 0x10) {
    if (CodePage_00 == 8) {
      uVar10 = *param_5;
      pWVar11 = param_4;
      pWVar6 = param_1;
joined_r0x005c025d:
      pWVar5 = pWVar11;
      if (pWVar6 < param_1 + uVar9) {
        WVar4 = *pWVar6;
        uVar7 = (uint)(ushort)WVar4;
        iVar17 = 2;
        pWVar6 = pWVar6 + 1;
        if (uVar7 < 0x80) {
          iVar17 = 1;
        }
        else if (0x7ff < uVar7) {
          if (uVar7 < 0x10000) {
            iVar17 = 3;
          }
          else if (uVar7 < 0x200000) {
            iVar17 = 4;
          }
          else if (uVar7 < 0x4000000) {
            iVar17 = 5;
          }
          else {
            if (0x7fffffff < uVar7) goto LAB_005c0330;
            iVar17 = 6;
          }
        }
        pWVar11 = (LPWSTR)(iVar17 + (int)pWVar5);
        if (pWVar11 <= (LPWSTR)(uVar10 + (int)param_4)) {
          if (iVar17 != 1) {
            if (iVar17 != 2) {
              if (iVar17 != 3) {
                if (iVar17 != 4) {
                  if (iVar17 != 5) goto code_r0x005c02c3;
                  goto LAB_005c02d9;
                }
                goto LAB_005c02ec;
              }
              goto LAB_005c02ff;
            }
            goto LAB_005c0312;
          }
          goto LAB_005c0323;
        }
      }
LAB_005c0330:
      *param_5 = (int)pWVar5 - (int)param_4;
      return (int)pWVar6 - (int)param_1 >> 1;
    }
LAB_005c03d4:
    if (CodePage_00 == 0x10) {
LAB_005c03ff:
      *param_5 = 0;
      return 0;
    }
    param_3 = 0;
    param_2 = CONCAT13(0x20,(undefined3)param_2);
    uVar10 = WideCharToMultiByte(CodePage_00,0,param_1,uVar9,(LPSTR)param_4,*param_5,
                                 (LPCSTR)((int)&param_2 + 3),(LPBOOL)&param_3);
  }
  else {
    if (CodePage == 0) {
      if (CodePage_00 == 0x10) {
        if (uVar9 <= *param_5) {
          puVar8 = &param_2;
        }
        uVar9 = *puVar8;
        uVar10 = 0;
        if (uVar9 != 0) {
          do {
            *param_4 = (ushort)*(byte *)(uVar10 + (int)param_1);
            uVar10 = uVar10 + 1;
            param_4 = param_4 + 1;
          } while (uVar10 < uVar9);
        }
        *param_5 = uVar9;
        return uVar9;
      }
LAB_005c037c:
      if (CodePage_00 == 8) {
        CodePage_00 = 8;
        goto LAB_005c039a;
      }
    }
    else if (CodePage != 0x10) goto LAB_005c037c;
    if (CodePage == 8) {
      if (CodePage_00 != 0x10) {
        CodePage = 8;
LAB_005c039a:
        uVar9 = FUN_005c043c(param_1,uVar9,CodePage,param_4,param_5,CodePage_00);
        return uVar9;
      }
    }
    else {
      if (CodePage == 0x10) goto LAB_005c03d4;
      if (CodePage_00 != 0x10) goto LAB_005c03ff;
    }
    uVar10 = MultiByteToWideChar(CodePage,0,(LPCSTR)param_1,uVar9,param_4,*param_5);
  }
  if (uVar10 == 0) {
    *puVar8 = 0;
    return 0;
  }
  *puVar8 = uVar10;
  return uVar9;
code_r0x005c02c3:
  if (iVar17 == 6) {
    *(byte *)((int)pWVar5 + 5) = (byte)WVar4 & 0x3f | 0x80;
    uVar7 = (ushort)WVar4 >> 6 | 0x4000000;
LAB_005c02d9:
    *(byte *)(pWVar5 + 2) = (byte)uVar7 & 0x3f | 0x80;
    uVar7 = (uVar7 | 0x8000000) >> 6;
LAB_005c02ec:
    *(byte *)((int)pWVar5 + 3) = (byte)uVar7 & 0x3f | 0x80;
    uVar7 = (uVar7 | 0x400000) >> 6;
LAB_005c02ff:
    *(byte *)(pWVar5 + 1) = (byte)uVar7 & 0x3f | 0x80;
    uVar7 = (uVar7 | 0x20000) >> 6;
LAB_005c0312:
    *(byte *)((int)pWVar5 + 1) = (byte)uVar7 & 0x3f | 0x80;
    uVar7 = (uVar7 | 0x3000) >> 6;
LAB_005c0323:
    *(char *)pWVar5 = (char)uVar7;
  }
  goto joined_r0x005c025d;
}

