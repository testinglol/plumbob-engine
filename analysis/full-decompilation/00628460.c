
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00628460(int param_1,byte *param_2,byte *param_3)

{
  undefined **ppuVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  FARPROC pFVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined **ppuVar14;
  byte *pbVar15;
  double *pdVar16;
  int iVar17;
  int *piVar18;
  char *pcVar19;
  char *pcVar20;
  bool bVar21;
  float10 fVar22;
  undefined4 uVar23;
  uint local_418;
  int local_414;
  int local_410;
  HMODULE local_40c;
  byte local_404 [512];
  byte local_204 [516];
  
  cVar2 = *(char *)(*param_2 + 0x100 + param_1);
  pbVar15 = param_2;
  while (cVar2 == '\0') {
    cVar2 = *(char *)((uint)pbVar15[1] + param_1);
    pbVar15 = pbVar15 + 1;
  }
  if (*pbVar15 == 0) {
    *(undefined4 *)(param_1 + 0x208) = 1;
    fVar22 = (float10)FUN_0062a120(param_1,param_2,param_3);
    return fVar22;
  }
  uVar6 = *(int *)(param_1 + 0x214) + 3U & 0xfffffffc;
  *(undefined4 *)(param_1 + 0x208) = 0;
  *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
  *(undefined4 *)(param_1 + 0x210) = 0;
  local_410 = 0;
  *(uint *)(param_1 + 0x218) = uVar6;
  *(int *)(param_1 + 0x21c) = *(int *)(param_1 + 0x220) + -8;
  FUN_0062b290(param_1,0);
  pbVar15 = *(byte **)(param_1 + 0x21c);
  pbVar9 = *(byte **)(param_1 + 0x228);
  *pbVar15 = 0x20;
  pbVar15[4] = 0xff;
  pbVar15[5] = 0xff;
  pbVar15[6] = 0xff;
  pbVar15[7] = 0xff;
  pbVar12 = param_2;
  pbVar13 = param_2;
  if (pbVar9 <= pbVar15) goto LAB_00628530;
LAB_0062852a:
  do {
    *(byte **)(param_1 + 0x228) = pbVar15;
    pbVar13 = pbVar12;
LAB_00628530:
    do {
      while( true ) {
        bVar3 = *pbVar13;
        pbVar12 = pbVar13;
        while (bVar3 == 0x20) {
          pbVar9 = pbVar12 + 1;
          pbVar12 = pbVar12 + 1;
          bVar3 = *pbVar9;
        }
        bVar3 = *pbVar12;
        if ((bVar3 != 0x28) && (bVar3 != 0x5b)) break;
        *(byte **)(param_1 + 0x21c) = pbVar15 + -8;
        FUN_0062b290(param_1,0);
        pbVar15 = *(byte **)(param_1 + 0x21c);
        bVar3 = *pbVar12;
        *pbVar15 = bVar3;
        pbVar9 = *(byte **)(param_1 + 0x228);
        *(uint *)(pbVar15 + 4) = (uint)*(byte *)((uint)bVar3 + param_1);
        if (pbVar15 < pbVar9) {
          *(byte **)(param_1 + 0x228) = pbVar15;
        }
        local_410 = local_410 + 1;
        pbVar13 = pbVar12 + 1;
      }
      if ((bVar3 == 0x2b) ||
         ((((bVar3 == 0x2d || (bVar3 == 0x7e)) || (bVar3 == 0x21)) ||
          ((bVar3 == 0x3c || (bVar3 == 0x3e)))))) {
        local_418 = (uint)bVar3;
        pbVar13 = pbVar12 + 1;
        switch(local_418) {
        case 0x21:
          local_418 = 0x8e;
          break;
        case 0x2b:
          goto LAB_00628530;
        case 0x2d:
          local_418 = 0x8c;
          break;
        case 0x3c:
          local_418 = 0x8f;
          if (pbVar12[2] == 0x3c) {
            local_418 = 0x91;
code_r0x00628bec:
            pbVar13 = pbVar12 + 2;
          }
          break;
        case 0x3e:
          local_418 = 0x90;
          if (pbVar12[2] == 0x3e) {
            local_418 = 0x92;
            goto code_r0x00628bec;
          }
          break;
        case 0x7e:
          local_418 = 0x8d;
        }
        pbVar12 = pbVar13;
        uVar10 = (uint)*(byte *)(local_418 + 0x100 + param_1);
        *(byte **)(param_1 + 0x21c) = pbVar15 + -8;
        FUN_0062b290(param_1,0x18);
        pbVar15 = *(byte **)(param_1 + 0x21c);
        *pbVar15 = (byte)local_418;
        goto LAB_00628b6b;
      }
      pbVar9 = pbVar12 + ((int)param_3 - (int)param_2);
      pbVar15 = local_404;
      if (bVar3 == 0x2a) {
        pbVar15 = local_404 + 1;
        pbVar12 = pbVar12 + 1;
        local_404[0] = 0x2a;
      }
      else {
        bVar21 = false;
        if (bVar3 != 0) {
          while (bVar3 == 0x20) {
            pbVar13 = pbVar12 + 1;
            pbVar12 = pbVar12 + 1;
            bVar3 = *pbVar13;
          }
          bVar3 = *pbVar12;
          if (bVar3 == 0x27) {
            bVar21 = true;
          }
          else if (*(char *)(bVar3 + 0x100 + param_1) != '\0') goto LAB_0062861b;
          pbVar12 = pbVar12 + 1;
          pbVar15 = local_404;
          bVar4 = *pbVar12;
          while (pbVar15 = pbVar15 + 1, local_404[0] = bVar3, bVar4 != 0) {
            if (bVar4 == 0x27) {
              bVar21 = !bVar21;
            }
            if (((!bVar21) && (*(char *)((uint)bVar4 + param_1) != '\0')) || (bVar4 == 0x20)) break;
            *pbVar15 = bVar4;
            pbVar13 = pbVar12 + 1;
            pbVar12 = pbVar12 + 1;
            bVar4 = *pbVar13;
          }
        }
      }
LAB_0062861b:
      bVar3 = *pbVar12;
      iVar17 = 0;
      *pbVar15 = 0;
      local_418 = 0;
      if (bVar3 != 0x28) {
LAB_0062886f:
        if (*pbVar12 == 0x5b) {
          local_418 = 0x8b;
        }
        FUN_0062b290(param_1,0x18);
        pdVar16 = *(double **)(param_1 + 0x218);
        fVar22 = (float10)FUN_0062a120(param_1,local_404,pbVar9);
        *pdVar16 = (double)fVar22;
        uVar23 = *(undefined4 *)(param_1 + 0x210);
        *(undefined4 *)(pdVar16 + 1) = *(undefined4 *)(param_1 + 0x20c);
        *(byte **)((int)pdVar16 + 0xc) = pbVar9;
        *(undefined4 *)(pdVar16 + 2) = uVar23;
        pdVar16 = pdVar16 + 3;
        *(double **)(param_1 + 0x218) = pdVar16;
        if (*(double **)(param_1 + 0x224) < pdVar16) {
          *(double **)(param_1 + 0x224) = pdVar16;
        }
        *(undefined4 *)(param_1 + 0x210) = 0;
        *(undefined4 *)(param_1 + 0x20c) = 0;
        bVar3 = *pbVar12;
        while (bVar3 == 0x20) {
          pbVar15 = pbVar12 + 1;
          pbVar12 = pbVar12 + 1;
          bVar3 = *pbVar15;
        }
        local_414 = local_410 + -1;
LAB_006288f3:
        do {
          bVar3 = *pbVar12;
          if ((bVar3 != 0x29) && (bVar3 != 0x5d)) goto LAB_006289c8;
          if (local_410 == 0) goto LAB_00628d4e;
          if ((*(int *)(param_1 + 0x102b4) == 0) ||
             (*(int *)(*(int *)(param_1 + 0x102b4) * 0x90 + -0x8c + *(int *)(param_1 + 0x102b8)) <
              local_414)) {
            uVar23 = 1;
          }
          else {
            uVar23 = 0;
          }
          FUN_00629120(param_1,*(undefined1 *)((uint)bVar3 + param_1),uVar23);
          pcVar19 = *(char **)(param_1 + 0x21c);
          if ((*pcVar19 == '(') || (*pcVar19 == '[')) {
            *(char **)(param_1 + 0x21c) = pcVar19 + 8;
          }
          else {
            *(char **)(param_1 + 0x21c) = pcVar19 + -8;
            FUN_0062b290(param_1,0);
            pbVar9 = *(byte **)(param_1 + 0x21c);
            bVar3 = *pbVar12;
            *pbVar9 = bVar3;
            pbVar15 = *(byte **)(param_1 + 0x228);
            *(uint *)(pbVar9 + 4) = (uint)*(byte *)((uint)bVar3 + param_1);
            if (pbVar9 < pbVar15) {
              local_410 = local_410 + -1;
              local_414 = local_414 + -1;
              *(byte **)(param_1 + 0x228) = pbVar9;
              pbVar12 = pbVar12 + 1;
              goto LAB_006288f3;
            }
          }
          local_410 = local_410 + -1;
          local_414 = local_414 + -1;
          pbVar12 = pbVar12 + 1;
        } while( true );
      }
      if (PTR_DAT_006da6e4 != (undefined *)0x0) {
        ppuVar14 = &PTR_DAT_006da6e4;
        do {
          iVar7 = FUN_00646330(local_404,*ppuVar14);
          if (iVar7 == 0) {
            local_418 = iVar17 + 0x93;
            if (local_418 != 0) {
              if (local_418 != 0x2a) goto LAB_0062882f;
              goto LAB_0062886f;
            }
            break;
          }
          ppuVar1 = ppuVar14 + 1;
          ppuVar14 = ppuVar14 + 1;
          iVar17 = iVar17 + 1;
        } while (*ppuVar1 != (undefined *)0x0);
      }
      uVar23 = *(undefined4 *)(param_1 + 0x102bc);
      piVar18 = (int *)(*(int *)(param_1 + 0x102b8) + *(int *)(param_1 + 0x102b4) * 0x90);
      local_418 = 0xb4;
      piVar18[2] = 0;
      iVar17 = FUN_00629010(uVar23,local_404);
      if (iVar17 == -1) {
        local_40c = LoadLibraryExA((LPCSTR)local_404,(HANDLE)0x0,0);
        if (local_40c == (HMODULE)0x0) {
          uVar10 = 0xffffffff;
          pbVar15 = local_404;
          do {
            pbVar9 = pbVar15;
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1;
            pbVar9 = pbVar15 + 1;
            bVar3 = *pbVar15;
            pbVar15 = pbVar9;
          } while (bVar3 != 0);
          uVar10 = ~uVar10;
          pbVar15 = pbVar9 + -uVar10;
          pbVar9 = local_204;
          for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
            *(undefined4 *)pbVar9 = *(undefined4 *)pbVar15;
            pbVar15 = pbVar15 + 4;
            pbVar9 = pbVar9 + 4;
          }
          for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *pbVar9 = *pbVar15;
            pbVar15 = pbVar15 + 1;
            pbVar9 = pbVar9 + 1;
          }
          uVar10 = 0xffffffff;
          pcVar19 = ".exe";
          do {
            pcVar20 = pcVar19;
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1;
            pcVar20 = pcVar19 + 1;
            cVar2 = *pcVar19;
            pcVar19 = pcVar20;
          } while (cVar2 != '\0');
          uVar10 = ~uVar10;
          iVar17 = -1;
          pbVar15 = local_204;
          do {
            pbVar9 = pbVar15;
            if (iVar17 == 0) break;
            iVar17 = iVar17 + -1;
            pbVar9 = pbVar15 + 1;
            bVar3 = *pbVar15;
            pbVar15 = pbVar9;
          } while (bVar3 != 0);
          pbVar15 = (byte *)(pcVar20 + -uVar10);
          pbVar9 = pbVar9 + -1;
          for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
            *(undefined4 *)pbVar9 = *(undefined4 *)pbVar15;
            pbVar15 = pbVar15 + 4;
            pbVar9 = pbVar9 + 4;
          }
          for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *pbVar9 = *pbVar15;
            pbVar15 = pbVar15 + 1;
            pbVar9 = pbVar9 + 1;
          }
          local_40c = LoadLibraryExA((LPCSTR)local_204,(HANDLE)0x0,0);
          if (local_40c == (HMODULE)0x0) {
            uVar23 = 5;
            goto LAB_00628d63;
          }
        }
        pFVar8 = (FARPROC)0x0;
        local_414 = 0;
        ppuVar14 = &PTR_s_exprmain_006da6d8;
        do {
          if (pFVar8 != (FARPROC)0x0) goto LAB_0062877d;
          pFVar8 = GetProcAddress(local_40c,*ppuVar14);
          local_414 = local_414 + 1;
          ppuVar14 = ppuVar14 + 1;
        } while ((int)ppuVar14 < 0x6da6e4);
        if (pFVar8 == (FARPROC)0x0) {
          FreeLibrary(local_40c);
          uVar23 = 5;
          goto LAB_00628d63;
        }
LAB_0062877d:
        *(int *)(*(int *)(param_1 + 0x102c4) + 4 + *(int *)(param_1 + 0x102c0) * 0xc) =
             local_414 + -1;
        *(FARPROC *)(*(int *)(param_1 + 0x102c4) + *(int *)(param_1 + 0x102c0) * 0xc) = pFVar8;
        *(HMODULE *)(*(int *)(param_1 + 0x102c4) + 8 + *(int *)(param_1 + 0x102c0) * 0xc) =
             local_40c;
        iVar17 = *(int *)(param_1 + 0x102c0);
        iVar7 = *(int *)(param_1 + 0x102c4);
        piVar18[1] = local_410;
        uVar23 = *(undefined4 *)(param_1 + 0x102bc);
        *piVar18 = iVar7 + iVar17 * 0xc;
        FUN_00628e90(uVar23,local_404,iVar17);
        *(int *)(param_1 + 0x102c0) = iVar17 + 1;
        *(int *)(param_1 + 0x102b4) = *(int *)(param_1 + 0x102b4) + 1;
      }
      else {
        iVar7 = *(int *)(param_1 + 0x102c4);
        piVar18[1] = local_410;
        iVar5 = *(int *)(param_1 + 0x102b4);
        *piVar18 = iVar7 + iVar17 * 0xc;
        *(int *)(param_1 + 0x102b4) = iVar5 + 1;
      }
LAB_0062882f:
      *(int *)(param_1 + 0x21c) = *(int *)(param_1 + 0x21c) + -8;
      FUN_0062b290(param_1,0x18);
      pbVar15 = *(byte **)(param_1 + 0x21c);
      *pbVar15 = (byte)local_418;
      pbVar9 = *(byte **)(param_1 + 0x228);
      pbVar15[4] = 0xf;
      pbVar15[5] = 0;
      pbVar15[6] = 0;
      pbVar15[7] = 0;
      pbVar13 = pbVar12;
    } while (pbVar9 <= pbVar15);
  } while( true );
LAB_006289c8:
  bVar3 = *pbVar12;
  if (bVar3 == 0) {
    if (local_410 == 0) {
      if ((*(int *)(param_1 + 0x102b4) == 0) ||
         (*(int *)(*(int *)(param_1 + 0x102b4) * 0x90 + -0x8c + *(int *)(param_1 + 0x102b8)) < -1))
      {
        uVar23 = 1;
      }
      else {
        uVar23 = 0;
      }
      FUN_00629120(param_1,0,uVar23);
      iVar17 = *(int *)(param_1 + 0x218);
      uVar10 = iVar17 - 0x18;
      *(uint *)(param_1 + 0x218) = uVar10;
      if (uVar10 != uVar6) {
        FUN_0061cf50(param_1,*(undefined4 *)(iVar17 + -0xc),7);
      }
      pdVar16 = *(double **)(param_1 + 0x218);
      iVar17 = *(int *)(pdVar16 + 1);
      *(undefined4 *)(param_1 + 0x210) = *(undefined4 *)(pdVar16 + 2);
      *(int *)(param_1 + 0x20c) = iVar17;
      if (((*(int *)(param_1 + 0x230) == 1) && (iVar17 < 0)) && (*pdVar16 != _DAT_006669e8)) {
        FUN_0061cf50(param_1,param_3,0xe);
      }
      return (float10)**(double **)(param_1 + 0x218);
    }
    goto LAB_00628d4e;
  }
  if (local_418 != 0) goto LAB_00628afe;
  while( true ) {
    local_418 = (uint)bVar3;
    pbVar12 = pbVar12 + 1;
    if ((0x20 < local_418) || (bVar21 = local_418 == 0, local_418 = 0, bVar21)) break;
    bVar3 = *pbVar12;
  }
  switch(local_418) {
  case 0x21:
    bVar3 = *pbVar12;
    if (bVar3 == 0x3d) {
      local_418 = 0x85;
    }
    else if (bVar3 == 0x3a) {
      local_418 = 0x89;
    }
    else {
      if (bVar3 != 0x3f) break;
      local_418 = 0x8a;
    }
    goto code_r0x00628afd;
  case 0x25:
    if (*pbVar12 == 0x25) goto code_r0x00628afd;
    break;
  case 0x26:
    if (*pbVar12 == 0x26) {
      local_418 = 0x86;
      goto code_r0x00628afd;
    }
    break;
  case 0x2a:
    if (*pbVar12 == 0x2a) {
      local_418 = 0x86;
      goto code_r0x00628afd;
    }
    break;
  case 0x2b:
    if (*pbVar12 == 0x2b) {
      local_418 = 0x87;
      goto code_r0x00628afd;
    }
    break;
  case 0x2d:
    if (*pbVar12 == 0x2d) {
      local_418 = 0x88;
      goto code_r0x00628afd;
    }
    break;
  case 0x2f:
    if (*pbVar12 == 0x2f) {
      local_418 = 0x25;
      goto code_r0x00628afd;
    }
    break;
  case 0x3c:
    bVar3 = *pbVar12;
    if (bVar3 == 0x3c) {
      local_418 = 0x80;
    }
    else if (bVar3 == 0x3d) {
      local_418 = 0x82;
    }
    else {
      if (bVar3 != 0x3e) break;
      local_418 = 0x85;
    }
    goto code_r0x00628afd;
  case 0x3d:
    if (*pbVar12 == 0x3d) {
      local_418 = 0x84;
      goto code_r0x00628afd;
    }
    break;
  case 0x3e:
    if (*pbVar12 == 0x3e) {
      local_418 = 0x81;
    }
    else {
      if (*pbVar12 != 0x3d) break;
      local_418 = 0x83;
    }
code_r0x00628afd:
    pbVar12 = pbVar12 + 1;
    break;
  case 0x7c:
    if (*pbVar12 == 0x7c) {
      local_418 = 0x87;
      goto code_r0x00628afd;
    }
  }
LAB_00628afe:
  uVar10 = (uint)*(byte *)(local_418 + param_1);
  if (1 < *(byte *)(local_418 + param_1)) {
    if ((*(int *)(param_1 + 0x102b4) == 0) ||
       (*(int *)(*(int *)(param_1 + 0x102b4) * 0x90 + -0x8c + *(int *)(param_1 + 0x102b8)) <
        local_410 + -1)) {
      uVar23 = 1;
    }
    else {
      uVar23 = 0;
    }
    FUN_00629120(param_1,uVar10,uVar23);
    *(int *)(param_1 + 0x21c) = *(int *)(param_1 + 0x21c) + -8;
    FUN_0062b290(param_1,0);
    pbVar15 = *(byte **)(param_1 + 0x21c);
    *pbVar15 = (byte)local_418;
LAB_00628b6b:
    pbVar9 = *(byte **)(param_1 + 0x228);
    *(uint *)(pbVar15 + 4) = uVar10;
    pbVar13 = pbVar12;
    if (pbVar15 < pbVar9) goto LAB_0062852a;
    goto LAB_00628530;
  }
LAB_00628d4e:
  uVar23 = 7;
  param_3 = pbVar12 + ((int)param_3 - (int)param_2);
LAB_00628d63:
  FUN_0061cf50(param_1,param_3,uVar23);
  return (float10)_DAT_006669e8;
}

