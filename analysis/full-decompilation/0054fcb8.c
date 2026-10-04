
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_0054fcb8(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  undefined4 *puVar9;
  int extraout_ECX;
  uint uVar10;
  int unaff_EBP;
  uint uVar11;
  char *pcVar12;
  LPCSTR pCVar13;
  
  FUN_00634c24();
  FUN_00636080();
  if (*(int *)(unaff_EBP + 8) == 0) {
    *(undefined4 *)(extraout_ECX + 0xe0) = 0;
    goto LAB_00550f92;
  }
  iVar4 = *(int *)(extraout_ECX + 0xe0);
  *(undefined4 *)(unaff_EBP + -0x14) = DAT_006f2a9c;
  if ((*(int *)(unaff_EBP + 8) == iVar4) && (*(char *)(unaff_EBP + 0x10) == '\0'))
  goto LAB_00550f92;
  uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(extraout_ECX + 0xe0) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 0xe4) = uVar3;
  wsprintfA((LPSTR)(unaff_EBP + -0xb4),(LPCSTR)&DAT_006c08e4);
  iVar4 = *(int *)(*(int *)(extraout_ECX + 0xe0) + 0x44);
  if ((iVar4 < 0x15) || (0x1f < iVar4)) {
    if ((iVar4 < 0x51) || (0x59 < iVar4)) {
      if ((0x5c < iVar4) && (iVar4 < 100)) {
        pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x6c);
        goto LAB_0054ff1b;
      }
      if ((iVar4 < 0x28) || (0x31 < iVar4)) {
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0x398) = &PTR_FUN_006664e8;
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0x4a8) = &PTR_FUN_006664e8;
        FUN_00425531();
        FUN_0046f8e4();
        FUN_0046f847();
        FUN_0046f5cd();
        *(undefined4 *)(unaff_EBP + -4) = 4;
        uVar3 = FUN_0046f71c();
        *(undefined4 *)(unaff_EBP + 0x10) = uVar3;
        FUN_004706f0();
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_004706f0();
        *(undefined1 *)(unaff_EBP + -4) = 6;
        if (*(int *)(unaff_EBP + 0x10) == 0) {
          FUN_00470d31();
          FUN_00470d31();
          FUN_0046b7ee();
          FUN_00471509();
          FUN_00635f62();
          FUN_00471509();
          FUN_006358b0();
          pCVar13 = (LPCSTR)(unaff_EBP + -0x278);
        }
        else {
          pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x1c);
        }
        wsprintfA((LPSTR)(unaff_EBP + -0xe20),pCVar13);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_004712d0();
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_004712d0();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      else {
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0x398) = &PTR_FUN_006664e8;
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0x4a8) = &PTR_FUN_006664e8;
        FUN_00425531();
        FUN_0046f8e4();
        FUN_0046f847();
        FUN_0046f5cd();
        *(undefined4 *)(unaff_EBP + -4) = 2;
        uVar3 = FUN_0046f71c();
        *(undefined4 *)(unaff_EBP + 0x10) = uVar3;
        FUN_004706f0();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (*(int *)(unaff_EBP + 0x10) == 0) {
          FUN_00470d31();
          FUN_0046b7ee();
          iVar4 = *(int *)(*(int *)(extraout_ECX + 0xe0) + 0x44);
          if ((0x27 < iVar4) || (0x2a < iVar4)) {
            FUN_00471509();
            FUN_006358b0();
            FUN_006358b0();
            FUN_006358c0();
            pCVar13 = (LPCSTR)(unaff_EBP + -0x5a8);
            goto LAB_005500ea;
          }
        }
        else {
          iVar4 = *(int *)(*(int *)(extraout_ECX + 0xe0) + 0x44);
          if (iVar4 < 0x28) {
            if (iVar4 < 0x2b) goto LAB_005500f6;
          }
          else if (iVar4 < 0x2b) {
            pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x3c);
            goto LAB_005500ea;
          }
          pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x40);
LAB_005500ea:
          wsprintfA((LPSTR)(unaff_EBP + -0xe20),pCVar13);
        }
LAB_005500f6:
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_004712d0();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      goto LAB_005502a6;
    }
    if (iVar4 < 0x54) {
      pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x60);
    }
    else {
      pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 100);
    }
LAB_0054ff1b:
    wsprintfA((LPSTR)(unaff_EBP + -0xe20),pCVar13);
  }
  else {
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x398) = &PTR_FUN_006664e8;
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x4a8) = &PTR_FUN_006664e8;
    FUN_00425531();
    FUN_0046f8e4();
    FUN_0046f847();
    FUN_0046f5cd();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar3 = FUN_0046f71c();
    *(undefined4 *)(unaff_EBP + 0x10) = uVar3;
    FUN_004706f0();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (*(int *)(unaff_EBP + 0x10) == 0) {
      FUN_00470d31();
      FUN_0046b7ee();
      iVar4 = *(int *)(*(int *)(extraout_ECX + 0xe0) + 0x44);
      if ((0x14 < iVar4) || (0x17 < iVar4)) {
        FUN_00471509();
        FUN_006358b0();
        FUN_006358b0();
        FUN_006358c0();
        pCVar13 = (LPCSTR)(unaff_EBP + -0x5a8);
        goto LAB_0054fed2;
      }
    }
    else {
      iVar4 = *(int *)(*(int *)(extraout_ECX + 0xe0) + 0x44);
      if (iVar4 < 0x15) {
        if (iVar4 < 0x18) goto LAB_0054fede;
      }
      else if (iVar4 < 0x18) {
        pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x34);
        goto LAB_0054fed2;
      }
      pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x38);
LAB_0054fed2:
      wsprintfA((LPSTR)(unaff_EBP + -0xe20),pCVar13);
    }
LAB_0054fede:
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_004712d0();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_005502a6:
    FUN_0046b2e6();
  }
  FUN_006358c0();
  *(undefined4 *)(unaff_EBP + 0xc) = 0;
  *(undefined4 *)(unaff_EBP + -0x58) = 0;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0;
  *(undefined4 *)(unaff_EBP + -0x88) = 0;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 7;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FUN_005d4bbf();
  iVar4 = *(int *)(*(int *)(unaff_EBP + 8) + 0x44);
  if (((iVar4 < 0x5a) || (0x5c < iVar4)) || (*(int *)(extraout_ECX + 0x100) == 0)) {
    uVar3 = FUN_00551013();
  }
  else {
    FUN_00635f62();
    uVar3 = FUN_0055118c();
  }
  *(undefined4 *)(unaff_EBP + 0x10) = uVar3;
  FUN_005d4956();
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  FUN_005d4956();
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_0046f824();
  *(undefined ***)(unaff_EBP + -0x288) = &PTR_FUN_006664e8;
  FUN_00425531();
  iVar4 = *(int *)(*(int *)(extraout_ECX + 0xe0) + 0x44);
  if (((((0x27 < iVar4) && (iVar4 < 0x31)) || ((0x14 < iVar4 && (iVar4 < 0x1f)))) ||
      ((0x50 < iVar4 && (iVar4 < 0x5a)))) ||
     (((0x59 < iVar4 && (iVar4 < 100)) || (iVar4 = FUN_0042ba25(), iVar4 != 0)))) {
    FUN_0046f847();
  }
  FUN_0046f5cd();
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  iVar4 = FUN_0046f71c();
  FUN_004706f0();
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  if (iVar4 == 0) {
    iVar4 = FUN_00470d31();
    if (iVar4 == 0) {
      iVar4 = FUN_00471509();
      if (iVar4 != 0) {
        FUN_005d4bbf();
      }
      iVar4 = FUN_00471509();
      if (iVar4 != 0) {
        FUN_005d4bbf();
      }
    }
    FUN_0046b7ee();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  FUN_004712d0();
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_0046b2e6();
  FUN_005b8789();
  iVar4 = *(int *)(*(int *)(extraout_ECX + 0xe0) + 0x44);
  if ((((0x14 < iVar4) && (iVar4 < 0x1f)) || ((0x27 < iVar4 && (iVar4 < 0x31)))) ||
     (((0x50 < iVar4 && (iVar4 < 0x5a)) || ((0x5c < iVar4 && (iVar4 < 100)))))) {
    FUN_004096c2();
    FUN_004096c2();
    pcVar12 = s__s__s_006cdc34;
    goto LAB_00550976;
  }
  iVar4 = FUN_0042ba25();
  if (iVar4 == 2) {
    FUN_004096c2();
    FUN_004096c2();
    pcVar12 = *(char **)(*(int *)(extraout_ECX + 0xec) + *(int *)(unaff_EBP + 0x10) * 4);
    goto LAB_00550976;
  }
  iVar4 = FUN_0042ba25();
  if (iVar4 != 1) {
    pCVar13 = &DAT_006f539c;
code_r0x005509a6:
    wsprintfA((LPSTR)(unaff_EBP + -0x1220),pCVar13);
    goto LAB_005509b1;
  }
  piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
  (**(code **)(*piVar5 + 0x7c))();
  (**(code **)(*piVar5 + 0x7c))();
  iVar4 = *(int *)(extraout_ECX + 0xe0);
  *(int *)(unaff_EBP + -0x10) = *piVar5;
  iVar4 = *(int *)(iVar4 + 0x34);
  (**(code **)(*(int *)(unaff_EBP + -0x10) + 0x7c))(iVar4,iVar4 >> 0x1f);
  iVar4 = *(int *)(extraout_ECX + 0xe0);
  *(int *)(unaff_EBP + -0x10) = *piVar5;
  iVar4 = *(int *)(iVar4 + 0x1c);
  (**(code **)(*(int *)(unaff_EBP + -0x10) + 0x7c))(iVar4,iVar4 >> 0x1f,unaff_EBP + -0x54);
  FUN_005d5156();
  if (0x26 < *(uint *)(unaff_EBP + 0x10)) goto LAB_005509b1;
  iVar4 = *(int *)(unaff_EBP + 0x10);
  switch(iVar4) {
  case 0:
  case 9:
    wsprintfA((LPSTR)(unaff_EBP + -0x1220),*(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + iVar4 * 4));
    if ((*(int *)(extraout_ECX + 0xf0) != 0) &&
       (*(int *)(*(int *)(extraout_ECX + 0xf0) + 0xd4) == 4)) {
      wsprintfA((LPSTR)(unaff_EBP + -0xa20),*(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x50));
code_r0x00550728:
      FUN_006358b0();
    }
    break;
  case 1:
    FUN_004096c2();
    FUN_004096c2();
    wsprintfA((LPSTR)(unaff_EBP + -0x1220),*(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 4));
    break;
  case 2:
    FUN_004096c2();
    FUN_004096c2();
    pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 8);
    goto code_r0x00550793;
  case 3:
    FUN_004096c2();
    FUN_004096c2();
    pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0xc);
    goto code_r0x005508d0;
  case 4:
    FUN_004096c2();
    FUN_004096c2();
    pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x10);
code_r0x00550793:
    wsprintfA((LPSTR)(unaff_EBP + -0x1220),pCVar13);
    break;
  case 5:
    FUN_004096c2();
    FUN_004096c2();
    pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x14);
    goto code_r0x005508d0;
  case 6:
  case 8:
  case 10:
  case 0xb:
  case 0xc:
    pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + iVar4 * 4);
    goto code_r0x005509a6;
  case 0x13:
  case 0x14:
  case 0x15:
    FUN_004096c2();
    FUN_004096c2();
    pcVar12 = *(char **)(*(int *)(extraout_ECX + 0xec) + iVar4 * 4);
    goto LAB_00550976;
  case 0x1c:
    FUN_004096c2();
    FUN_004096c2();
    pcVar12 = *(char **)(*(int *)(extraout_ECX + 0xec) + 0x70);
LAB_00550976:
    wsprintfA((LPSTR)(unaff_EBP + -0x1220),pcVar12);
    break;
  case 0x1d:
    FUN_004096c2();
    FUN_004096c2();
    pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x74);
    goto code_r0x005508d0;
  case 0x1f:
    FUN_004096c2();
    FUN_004096c2();
    pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x7c);
code_r0x005508d0:
    wsprintfA((LPSTR)(unaff_EBP + -0x1220),pCVar13);
    break;
  case 0x22:
  case 0x23:
    wsprintfA((LPSTR)(unaff_EBP + -0x1220),*(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + iVar4 * 4));
    if ((*(int *)(extraout_ECX + 0x100) != 0) &&
       (*(int *)(*(int *)(extraout_ECX + 0x100) + 0xd4) == 4)) {
      wsprintfA((LPSTR)(unaff_EBP + -0xa20),*(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x70));
      goto code_r0x00550728;
    }
    break;
  case 0x24:
  case 0x25:
    FUN_004096c2();
    FUN_004096c2();
    pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + iVar4 * 4);
    goto code_r0x0055086f;
  case 0x26:
    FUN_004096c2();
    FUN_004096c2();
    pCVar13 = *(LPCSTR *)(*(int *)(extraout_ECX + 0xec) + 0x98);
code_r0x0055086f:
    wsprintfA((LPSTR)(unaff_EBP + -0x1220),pCVar13);
  }
LAB_005509b1:
  FUN_006358c0();
  piVar5 = *(int **)(unaff_EBP + -0x14);
  pcVar12 = (char *)(unaff_EBP + -0xe20);
  cVar2 = *(char *)(unaff_EBP + -0xe20);
  while (((cVar2 != '\0' && (cVar2 != '\n')) && (cVar2 != '\r'))) {
    iVar4 = (**(code **)(*piVar5 + 0x44))();
    pcVar12 = pcVar12 + iVar4;
    cVar2 = *pcVar12;
  }
  uVar3 = (**(code **)(*piVar5 + 0x68))();
  *(undefined4 *)(unaff_EBP + 0x10) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  FUN_004e1d96();
  *(undefined4 *)(unaff_EBP + 8) = 0;
  while( true ) {
    if (*(int *)(unaff_EBP + 0x10) < 0x96) {
      *(undefined4 *)(unaff_EBP + 0x10) = 0x96;
    }
    if (0x140 < *(int *)(unaff_EBP + 0x10)) {
      *(undefined4 *)(unaff_EBP + 0x10) = 0x140;
    }
    iVar4 = *piVar5;
    _strlen((char *)(unaff_EBP + -0xe20));
    iVar6 = (**(code **)(iVar4 + 100))();
    iVar7 = (**(code **)(*piVar5 + 0x58))();
    iVar4 = *(int *)(unaff_EBP + 0x10);
    *(undefined4 *)(extraout_ECX + 0xe8) = 0;
    *(int *)(unaff_EBP + -0xe0) = iVar4 + 0x19;
    *(int *)(unaff_EBP + -0xdc) = iVar7 * iVar6 + 0x19;
    uVar10 = *(int *)(unaff_EBP + -0x44) - *(int *)(unaff_EBP + -0x48);
    *(undefined4 *)(unaff_EBP + -0xe8) = 0x19;
    *(undefined4 *)(unaff_EBP + -0xe4) = 0x19;
    *(int *)(unaff_EBP + -0x78) = iVar7 * iVar6 + 0x32;
    if ((uVar10 & 0xfffffffc) != 0) {
      *(int *)(unaff_EBP + -0x78) = *(int *)(unaff_EBP + -0x78) + 10;
      *(int *)(extraout_ECX + 0xe8) = iVar4 / 0x19;
      if ((uint)(iVar4 / 0x19) < (uint)((int)uVar10 >> 2)) {
        *(int *)(unaff_EBP + -0x78) = *(int *)(unaff_EBP + -0x78) + 0x32;
      }
      else {
        *(int *)(unaff_EBP + -0x78) = *(int *)(unaff_EBP + -0x78) + 0x19;
      }
      piVar5 = *(int **)(unaff_EBP + -0x14);
    }
    if ((*(int *)(unaff_EBP + -0x78) < ((iVar4 + 0x32) * 2) / 3) ||
       (*(int *)(unaff_EBP + 0x10) = (*(int *)(unaff_EBP + 0x10) * 3) / 2,
       1 < *(int *)(unaff_EBP + 8))) break;
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
  }
  FUN_004cb1a2();
  if (*(undefined4 **)(extraout_ECX + 0xd8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(extraout_ECX + 0xd8))();
    *(undefined4 *)(extraout_ECX + 0xd8) = 0;
  }
  if (*(undefined4 **)(extraout_ECX + 0xd4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(extraout_ECX + 0xd4))();
    *(undefined4 *)(extraout_ECX + 0xd4) = 0;
  }
  pvVar8 = operator_new(100);
  *(void **)(unaff_EBP + 0x10) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  if (pvVar8 == (void *)0x0) {
    puVar9 = (undefined4 *)0x0;
  }
  else {
    puVar9 = (undefined4 *)FUN_005dfb13();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  *(undefined4 **)(extraout_ECX + 0xd8) = puVar9;
  if (puVar9 != (undefined4 *)0x0) {
    uVar3 = *puVar9;
    *(undefined1 **)(unaff_EBP + 0x10) = &stack0xffffffd8;
    *(undefined4 *)(unaff_EBP + 0x10) = uVar3;
    FUN_00436a50(4);
    uVar3 = FUN_00551006();
    uVar3 = FUN_0050a296(uVar3);
    cVar2 = (**(code **)(*(int *)(unaff_EBP + 0x10) + 0xc))(uVar3);
    puVar9 = *(undefined4 **)(extraout_ECX + 0xd8);
    if (cVar2 != '\0') {
      cVar2 = FUN_005df761();
      if (cVar2 != '\0') goto LAB_00550bc6;
      puVar9 = *(undefined4 **)(extraout_ECX + 0xd8);
    }
    if (puVar9 != (undefined4 *)0x0) {
      (**(code **)*puVar9)();
    }
    *(undefined4 *)(extraout_ECX + 0xd8) = 0;
  }
LAB_00550bc6:
  pvVar8 = operator_new(100);
  *(void **)(unaff_EBP + 0x10) = pvVar8;
  *(undefined1 *)(unaff_EBP + -4) = 0x16;
  if (pvVar8 == (void *)0x0) {
    puVar9 = (undefined4 *)0x0;
  }
  else {
    puVar9 = (undefined4 *)FUN_005dfb13();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  *(undefined4 **)(extraout_ECX + 0xd4) = puVar9;
  if (puVar9 != (undefined4 *)0x0) {
    uVar3 = *puVar9;
    *(undefined1 **)(unaff_EBP + 0x10) = &stack0xffffffd8;
    *(undefined4 *)(unaff_EBP + 0x10) = uVar3;
    FUN_00436a50(4);
    uVar3 = FUN_00551006();
    uVar3 = FUN_0050a296(uVar3);
    cVar2 = (**(code **)(*(int *)(unaff_EBP + 0x10) + 0xc))(uVar3);
    if (cVar2 == '\0') {
      if (*(undefined4 **)(extraout_ECX + 0xd4) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(extraout_ECX + 0xd4))();
      }
      *(undefined4 *)(extraout_ECX + 0xd4) = 0;
    }
  }
  iVar4 = *(int *)(extraout_ECX + 0xdc);
  if ((iVar4 != 0) && (piVar1 = *(int **)(extraout_ECX + 0xd8), piVar1 != (int *)0x0)) {
    *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar4 + 0x14);
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar4 + 0x18);
    iVar6 = *(int *)(iVar4 + 0x1c);
    *(int *)(unaff_EBP + -0x1c) = iVar6;
    iVar4 = *(int *)(iVar4 + 0x20);
    *(int *)(unaff_EBP + -0x1c) = iVar6 / 3;
    *(int *)(unaff_EBP + -0x18) = iVar4 / 3;
    cVar2 = (**(code **)(*piVar1 + 0x20))();
    if (cVar2 != '\0') {
      (**(code **)(**(int **)(extraout_ECX + 0xd8) + 0xc0))();
      (**(code **)(**(int **)(extraout_ECX + 0xd8) + 0x24))(0x10);
    }
    piVar5 = *(int **)(*(int *)(extraout_ECX + 0xd8) + 0x60);
    cVar2 = (**(code **)(*piVar5 + 0x20))();
    if (cVar2 != '\0') {
      (**(code **)(*piVar5 + 0xc0))();
      (**(code **)(*piVar5 + 0x24))();
    }
    piVar5 = *(int **)(unaff_EBP + -0x14);
  }
  if ((*(int **)(extraout_ECX + 0xd4) != (int *)0x0) &&
     (cVar2 = (**(code **)(**(int **)(extraout_ECX + 0xd4) + 0x20))(), cVar2 != '\0')) {
    (**(code **)(**(int **)(extraout_ECX + 0xd4) + 0x9c))();
    (**(code **)(**(int **)(extraout_ECX + 0xd4) + 0x24))();
  }
  if (*(int *)(extraout_ECX + 0xd4) != 0) {
    iVar4 = *piVar5;
    _strlen((char *)(unaff_EBP + -0xe20));
    (**(code **)(iVar4 + 0x80))();
  }
  if ((*(int **)(extraout_ECX + 0xd4) != (int *)0x0) &&
     (cVar2 = (**(code **)(**(int **)(extraout_ECX + 0xd4) + 0x20))(), cVar2 != '\0')) {
    uVar10 = *(uint *)(extraout_ECX + 0xe8);
    iVar4 = *(int *)(unaff_EBP + -0x78) + -0x19;
    *(int *)(unaff_EBP + 8) = iVar4;
    *(int *)(unaff_EBP + -0x18) = iVar4;
    iVar4 = *(int *)(unaff_EBP + -0x44);
    *(undefined4 *)(unaff_EBP + -0x24) = 0x19;
    if (uVar10 < (uint)(iVar4 - *(int *)(unaff_EBP + -0x48) >> 2)) {
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -0x19;
    }
    uVar11 = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x32;
    *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x18) + -0x19;
    if (0 < (int)uVar10) {
      do {
        if ((uint)(iVar4 - *(int *)(unaff_EBP + -0x48) >> 2) <= uVar11) break;
        FUN_005c1719();
        *(undefined1 *)(unaff_EBP + -4) = 0x17;
        cVar2 = FUN_004e9692();
        if (cVar2 != '\0') {
          iVar4 = **(int **)(extraout_ECX + 0xd4);
          FUN_004096c2();
          FUN_004096c2();
          (**(code **)(iVar4 + 0x9c))();
        }
        *(undefined1 *)(unaff_EBP + -4) = 0x14;
        FUN_005a5e09();
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 0x19;
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0x19;
        iVar4 = *(int *)(unaff_EBP + -0x44);
        uVar11 = uVar11 + 1;
      } while ((int)uVar11 < *(int *)(extraout_ECX + 0xe8));
    }
    uVar10 = *(uint *)(extraout_ECX + 0xe8);
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x24) = 0x19;
    *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + 8) + -0x19;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x32;
    for (; uVar10 < (uint)(iVar4 - *(int *)(unaff_EBP + -0x48) >> 2); uVar10 = uVar10 + 1) {
      FUN_005c1719();
      *(undefined1 *)(unaff_EBP + -4) = 0x18;
      cVar2 = FUN_004e9692();
      if (cVar2 != '\0') {
        iVar4 = **(int **)(extraout_ECX + 0xd4);
        FUN_004096c2();
        FUN_004096c2();
        (**(code **)(iVar4 + 0x9c))();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      FUN_005a5e09();
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 0x19;
      iVar4 = *(int *)(unaff_EBP + -0x44);
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0x19;
    }
    (**(code **)(**(int **)(extraout_ECX + 0xd4) + 0x24))();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_00550f92:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

