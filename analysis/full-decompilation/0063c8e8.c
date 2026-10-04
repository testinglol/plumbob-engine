
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0063c8e8(undefined4 param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  _cpinfo local_1c;
  uint local_8;
  
  FUN_0063d88b(0x19);
  CodePage = FUN_0063ca95(param_1);
  if (CodePage != DAT_00705124) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_006dab18;
LAB_0063c925:
      if (*pUVar5 != CodePage) goto code_r0x0063c929;
      local_8 = 0;
      puVar15 = &DAT_00705240;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x6dab28);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_006dab10)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_00705240 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar13 = pbVar13 + 8;
      } while (local_8 < 4);
      DAT_0070513c = 1;
      DAT_00705124 = CodePage;
      DAT_00705344 = FUN_0063cadf(CodePage);
      _DAT_00705130 = *(undefined4 *)(iVar12 + 0x6dab1c);
      DAT_00705134 = *(undefined4 *)(iVar12 + 0x6dab20);
      _DAT_00705138 = *(undefined4 *)(iVar12 + 0x6dab24);
      goto LAB_0063ca79;
    }
    goto LAB_0063ca74;
  }
  goto LAB_0063c90f;
code_r0x0063c929:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x6dac07 < (int)pUVar5) goto code_r0x0063c934;
  goto LAB_0063c925;
code_r0x0063c934:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_00705344 = 0;
    puVar15 = &DAT_00705240;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_0070513c = 0;
      DAT_00705124 = CodePage;
    }
    else {
      DAT_00705124 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_00705240 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_00705240 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_00705344 = FUN_0063cadf(CodePage);
      DAT_0070513c = 1;
    }
    _DAT_00705130 = 0;
    DAT_00705134 = 0;
    _DAT_00705138 = 0;
  }
  else {
    if (DAT_00703b48 == 0) {
      uVar14 = 0xffffffff;
      goto LAB_0063ca86;
    }
LAB_0063ca74:
    FUN_0063cb12();
  }
LAB_0063ca79:
  FUN_0063cb3b();
LAB_0063c90f:
  uVar14 = 0;
LAB_0063ca86:
  FUN_0063d8ec(0x19);
  return uVar14;
}

