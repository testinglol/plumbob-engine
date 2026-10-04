
void FUN_004f4f41(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  HWND pHVar5;
  HDC pHVar6;
  BOOL BVar7;
  LONG LVar8;
  LPVOID pvVar9;
  size_t sVar10;
  LPCSTR pCVar11;
  UINT UVar12;
  undefined4 extraout_ECX;
  int unaff_EBP;
  DWORD DVar13;
  int iVar14;
  LPWSTR lpWideCharStr;
  int cchWideChar;
  LPWSTR lpWideCharStr_00;
  char *pcVar15;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x280) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -0x30) = 1;
  *(undefined1 *)(unaff_EBP + -0x20) = 1;
  *(undefined1 *)(unaff_EBP + -0x14) = 0;
  *(undefined1 *)(unaff_EBP + -0x40) = 0;
  *(undefined1 *)(unaff_EBP + -0x48) = 0;
  *(undefined1 *)(unaff_EBP + -0x10) = 0;
  *(undefined1 *)(unaff_EBP + -0x3c) = 0;
  *(undefined1 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  uVar2 = FUN_005efc9b();
  *(undefined4 *)(unaff_EBP + -0x44) = uVar2;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  pvVar3 = operator_new(0x10);
  *(void **)(unaff_EBP + -0x1e4) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + -0x1e4) == 0) {
    *(undefined4 *)(unaff_EBP + -0x284) = 0;
  }
  else {
    uVar2 = FUN_005bc0be();
    *(undefined4 *)(unaff_EBP + -0x284) = uVar2;
  }
  *(undefined4 *)(unaff_EBP + -0x1e0) = *(undefined4 *)(unaff_EBP + -0x284);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x1e0);
  iVar4 = (**(code **)(*DAT_006f2a0c + 0xc))();
  *(bool *)(unaff_EBP + -0x1c) = iVar4 != 0;
  pHVar5 = FindWindowExA((HWND)0x0,(HWND)0x0,s_Gonzo_006cb0b8,DAT_006f2930);
  *(HWND *)(unaff_EBP + -0x18) = pHVar5;
  if (((*(int *)(unaff_EBP + -0x18) == 0) && (DAT_00706000 < 2)) &&
     (*(char *)(unaff_EBP + -0x1c) != '\0')) {
    iVar4 = FUN_004f5a42();
    if ((iVar4 != 0) && (iVar4 = FUN_004f5a68(), 4 < iVar4)) {
      *(undefined1 *)(unaff_EBP + -0x40) = 1;
    }
    if (*(char *)(unaff_EBP + -0x40) != '\0') {
      uVar2 = FUN_005bdf5b();
      *(undefined4 *)(unaff_EBP + -0x4c) = uVar2;
      if ((*(uint *)(unaff_EBP + -0x4c) & 0x10) != 0) {
        *(undefined1 *)(unaff_EBP + -0x48) = 1;
      }
    }
    if (*(int *)(unaff_EBP + -0x28) != 0) {
      uVar2 = FUN_005bc272();
      *(undefined4 *)(unaff_EBP + -0x34) = uVar2;
    }
    if (*(uint *)(unaff_EBP + -0x44) < 0x600) {
      FUN_005b86bd(&DAT_006f27b0);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005b86bd(&DAT_006f2790);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      sVar10 = _strlen(&DAT_006c08dc);
      uVar2 = FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
      *(undefined4 *)(unaff_EBP + -0x200) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x204) = DAT_006f27a4;
      uVar2 = FUN_00412d8a(DAT_006f27a0,*(undefined4 *)(unaff_EBP + -0x204));
      *(undefined4 *)(unaff_EBP + -0x208) = uVar2;
      MessageBoxA((HWND)0x0,*(LPCSTR *)(unaff_EBP + -0x58),*(LPCSTR *)(unaff_EBP + -100),0);
      FUN_00637cca(1);
    }
    if (0x5ff < *(uint *)(unaff_EBP + -0x44)) {
      *(undefined1 *)(unaff_EBP + -0x20) = 1;
    }
    if (*(int *)(unaff_EBP + -0x34) == 4) {
      DAT_006f29ed = '\x01';
      *(undefined1 *)(unaff_EBP + -0x30) = 1;
    }
    else if (*(int *)(unaff_EBP + -0x34) == 3) {
      DAT_006f29ed = '\0';
      *(undefined1 *)(unaff_EBP + -0x30) = 1;
    }
    if (*(char *)(unaff_EBP + 0x10) == '\0') {
      *(undefined4 *)(unaff_EBP + -0x6c) = 0;
      pHVar6 = GetDC((HWND)0x0);
      *(HDC *)(unaff_EBP + -0x70) = pHVar6;
      if (*(int *)(unaff_EBP + -0x70) != 0) {
        iVar4 = GetDeviceCaps(*(HDC *)(unaff_EBP + -0x70),0xc);
        *(int *)(unaff_EBP + -0x6c) = iVar4;
      }
      if (*(int *)(unaff_EBP + -0x6c) == 0x10) {
        *(undefined1 *)(unaff_EBP + -0x24) = 1;
      }
      iVar4 = GetDeviceCaps(*(HDC *)(unaff_EBP + -0x70),8);
      *(int *)(unaff_EBP + -0x68) = iVar4;
      iVar4 = GetDeviceCaps(*(HDC *)(unaff_EBP + -0x70),10);
      *(int *)(unaff_EBP + -0x74) = iVar4;
      if ((*(int *)(unaff_EBP + 8) <= *(int *)(unaff_EBP + -0x68)) &&
         (*(int *)(unaff_EBP + 0xc) <= *(int *)(unaff_EBP + -0x74))) {
        *(undefined1 *)(unaff_EBP + -0x14) = 1;
      }
      ReleaseDC((HWND)0x0,*(HDC *)(unaff_EBP + -0x70));
    }
    else {
      *(undefined1 *)(unaff_EBP + -0x24) = 1;
      *(undefined1 *)(unaff_EBP + -0x14) = 1;
    }
    _memset((void *)(unaff_EBP + -0x108),0,0x94);
    *(undefined2 *)(unaff_EBP + -0xe4) = 0x94;
    *(undefined4 *)(unaff_EBP + -0x10c) = 0;
    do {
      *(undefined4 *)(unaff_EBP + -0x288) = *(undefined4 *)(unaff_EBP + -0x10c);
      *(int *)(unaff_EBP + -0x10c) = *(int *)(unaff_EBP + -0x10c) + 1;
      BVar7 = EnumDisplaySettingsA
                        ((LPCSTR)0x0,*(DWORD *)(unaff_EBP + -0x288),(DEVMODEA *)(unaff_EBP + -0x108)
                        );
      if (BVar7 == 0) goto LAB_004f5248;
    } while ((*(int *)(unaff_EBP + -0xa0) != 0xf) && (*(int *)(unaff_EBP + -0xa0) != 0x10));
    *(undefined1 *)(unaff_EBP + -0x3c) = 1;
    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0xa0);
LAB_004f5248:
    if (((*(char *)(unaff_EBP + 0x10) == '\0') && (*(char *)(unaff_EBP + -0x3c) != '\0')) &&
       ((*(char *)(unaff_EBP + -0x14) == '\0' || (*(char *)(unaff_EBP + -0x24) == '\0')))) {
      _memset((void *)(unaff_EBP + -0x1a4),0,0x94);
      *(undefined2 *)(unaff_EBP + -0x180) = 0x94;
      *(undefined4 *)(unaff_EBP + -0x17c) = 0;
      if (*(char *)(unaff_EBP + -0x14) == '\0') {
        *(undefined4 *)(unaff_EBP + -0x138) = *(undefined4 *)(unaff_EBP + 8);
        *(undefined4 *)(unaff_EBP + -0x134) = *(undefined4 *)(unaff_EBP + 0xc);
        *(uint *)(unaff_EBP + -0x17c) = *(uint *)(unaff_EBP + -0x17c) | 0x180000;
      }
      if (*(char *)(unaff_EBP + -0x24) == '\0') {
        *(undefined4 *)(unaff_EBP + -0x13c) = *(undefined4 *)(unaff_EBP + -0x2c);
        *(uint *)(unaff_EBP + -0x17c) = *(uint *)(unaff_EBP + -0x17c) | 0x40000;
      }
      LVar8 = ChangeDisplaySettingsA((DEVMODEA *)(unaff_EBP + -0x1a4),0);
      *(LONG *)(unaff_EBP + -0x110) = LVar8;
      if (*(int *)(unaff_EBP + -0x110) == 0) {
        *(undefined1 *)(unaff_EBP + -0x14) = 1;
        *(undefined1 *)(unaff_EBP + -0x24) = 1;
      }
    }
    *(undefined1 *)(unaff_EBP + -0x38) = 1;
    pvVar9 = VirtualAlloc((LPVOID)0x0,0x9600000,0x2000,1);
    *(LPVOID *)(unaff_EBP + -0x1a8) = pvVar9;
    if (*(int *)(unaff_EBP + -0x1a8) == 0) {
      *(undefined1 *)(unaff_EBP + -0x38) = 0;
    }
    else {
      VirtualFree(*(LPVOID *)(unaff_EBP + -0x1a8),0,0x8000);
    }
    pcVar15 = s_test_tmp_006cb0ac;
    FUN_005b8e25(s_test_tmp_006cb0ac);
    cVar1 = FUN_005b960e(pcVar15);
    if (cVar1 != '\0') {
      uVar2 = 1;
      pcVar15 = s_test_tmp_006cb0ac;
      FUN_005b8e25(s_test_tmp_006cb0ac,1);
      uVar2 = FUN_005b936f(pcVar15,uVar2);
      *(undefined4 *)(unaff_EBP + -0x1ac) = uVar2;
      if (*(int *)(unaff_EBP + -0x1ac) == 0) {
        *(undefined1 *)(unaff_EBP + -0x38) = 0;
      }
      else {
        cVar1 = FUN_005b8ff1(0x3200000);
        if (cVar1 == '\0') {
          *(undefined1 *)(unaff_EBP + -0x38) = 0;
        }
        uVar2 = *(undefined4 *)(unaff_EBP + -0x1ac);
        FUN_005b8e25(uVar2);
        FUN_005b95c0(uVar2);
        pcVar15 = s_test_tmp_006cb0ac;
        FUN_005b8e25(s_test_tmp_006cb0ac);
        FUN_005b9796(pcVar15);
      }
    }
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x10) = 1;
    *(undefined1 *)(unaff_EBP + -0x24) = 1;
    *(undefined1 *)(unaff_EBP + -0x30) = 1;
    *(undefined1 *)(unaff_EBP + -0x20) = 1;
    *(undefined1 *)(unaff_EBP + -0x14) = 1;
    *(undefined1 *)(unaff_EBP + -0x40) = 1;
    *(undefined1 *)(unaff_EBP + -0x48) = 1;
    *(undefined1 *)(unaff_EBP + -0x3c) = 1;
    *(undefined1 *)(unaff_EBP + -0x38) = 1;
  }
  if (((((*(char *)(unaff_EBP + -0x24) == '\0') || (*(char *)(unaff_EBP + -0x30) == '\0')) ||
       (*(char *)(unaff_EBP + -0x20) == '\0')) ||
      ((*(char *)(unaff_EBP + -0x14) == '\0' || (*(char *)(unaff_EBP + -0x40) == '\0')))) ||
     ((*(char *)(unaff_EBP + -0x10) != '\0' ||
      ((*(char *)(unaff_EBP + -0x3c) == '\0' || (*(char *)(unaff_EBP + -0x38) == '\0')))))) {
    FUN_005b86bd(&DAT_006f27b0);
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_005b86bd(&DAT_006f2790);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (*(char *)(unaff_EBP + -0x40) == '\0') {
      sVar10 = _strlen(&DAT_006c08dc);
      uVar2 = FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
      *(undefined4 *)(unaff_EBP + -0x20c) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x210) = DAT_006f2784;
      uVar2 = FUN_00412d8a(DAT_006f2780,*(undefined4 *)(unaff_EBP + -0x210));
      *(undefined4 *)(unaff_EBP + -0x214) = uVar2;
    }
    if (*(char *)(unaff_EBP + -0x24) == '\0') {
      sVar10 = _strlen(&DAT_006c08dc);
      uVar2 = FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
      *(undefined4 *)(unaff_EBP + -0x218) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x21c) = DAT_006f2774;
      uVar2 = FUN_00412d8a(DAT_006f2770,*(undefined4 *)(unaff_EBP + -0x21c));
      *(undefined4 *)(unaff_EBP + -0x220) = uVar2;
    }
    if (*(char *)(unaff_EBP + -0x30) == '\0') {
      sVar10 = _strlen(&DAT_006c08dc);
      uVar2 = FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
      *(undefined4 *)(unaff_EBP + -0x224) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x228) = DAT_006f2764;
      uVar2 = FUN_00412d8a(DAT_006f2760,*(undefined4 *)(unaff_EBP + -0x228));
      *(undefined4 *)(unaff_EBP + -0x22c) = uVar2;
    }
    if (*(char *)(unaff_EBP + -0x20) == '\0') {
      sVar10 = _strlen(&DAT_006c08dc);
      uVar2 = FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
      *(undefined4 *)(unaff_EBP + -0x230) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x234) = DAT_006f27a4;
      uVar2 = FUN_00412d8a(DAT_006f27a0,*(undefined4 *)(unaff_EBP + -0x234));
      *(undefined4 *)(unaff_EBP + -0x238) = uVar2;
    }
    if (*(char *)(unaff_EBP + -0x14) == '\0') {
      sVar10 = _strlen(&DAT_006c08dc);
      uVar2 = FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
      *(undefined4 *)(unaff_EBP + -0x23c) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x240) = DAT_006f2754;
      uVar2 = FUN_00412d8a(DAT_006f2750,*(undefined4 *)(unaff_EBP + -0x240));
      *(undefined4 *)(unaff_EBP + -0x244) = uVar2;
    }
    if (*(char *)(unaff_EBP + -0x10) != '\0') {
      sVar10 = _strlen(&DAT_006c08dc);
      uVar2 = FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
      *(undefined4 *)(unaff_EBP + -0x248) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x24c) = DAT_006f2744;
      uVar2 = FUN_00412d8a(DAT_006f2740,*(undefined4 *)(unaff_EBP + -0x24c));
      *(undefined4 *)(unaff_EBP + -0x250) = uVar2;
    }
    if (*(char *)(unaff_EBP + -0x3c) == '\0') {
      sVar10 = _strlen(&DAT_006c08dc);
      uVar2 = FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
      *(undefined4 *)(unaff_EBP + -0x254) = uVar2;
      *(undefined4 *)(unaff_EBP + -600) = DAT_006f2734;
      uVar2 = FUN_00412d8a(DAT_006f2730,*(undefined4 *)(unaff_EBP + -600));
      *(undefined4 *)(unaff_EBP + -0x25c) = uVar2;
    }
    if (*(char *)(unaff_EBP + -0x38) == '\0') {
      sVar10 = _strlen(&DAT_006c08dc);
      uVar2 = FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
      *(undefined4 *)(unaff_EBP + -0x260) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x264) = DAT_006f2714;
      uVar2 = FUN_00412d8a(DAT_006f2710,*(undefined4 *)(unaff_EBP + -0x264));
      *(undefined4 *)(unaff_EBP + -0x268) = uVar2;
    }
    sVar10 = _strlen(&DAT_006c08dc);
    uVar2 = FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
    *(undefined4 *)(unaff_EBP + -0x26c) = uVar2;
    *(undefined4 *)(unaff_EBP + -0x270) = DAT_006f2724;
    uVar2 = FUN_00412d8a(DAT_006f2720,*(undefined4 *)(unaff_EBP + -0x270));
    *(undefined4 *)(unaff_EBP + -0x274) = uVar2;
    if (DAT_006f29ed == '\0') {
      *(undefined4 *)(unaff_EBP + -0x1d8) = *(undefined4 *)(unaff_EBP + -0x1b8);
      *(undefined4 *)(unaff_EBP + -0x1dc) = *(undefined4 *)(unaff_EBP + -0x1c4);
      if ((*(int *)(unaff_EBP + -0x1d8) == 0) ||
         (sVar10 = _strlen(*(char **)(unaff_EBP + -0x1d8)), sVar10 == 0)) {
        *(char **)(unaff_EBP + -0x1d8) = s_Argh__006cb0a4;
      }
      if ((*(int *)(unaff_EBP + -0x1dc) == 0) ||
         (sVar10 = _strlen(*(char **)(unaff_EBP + -0x1dc)), sVar10 == 0)) {
        *(char **)(unaff_EBP + -0x1dc) = s_argh__006cb09c;
      }
      iVar4 = MessageBoxA((HWND)0x0,*(LPCSTR *)(unaff_EBP + -0x1b8),*(LPCSTR *)(unaff_EBP + -0x1c4),
                          0);
      *(int *)(unaff_EBP + -0x1d4) = iVar4;
    }
    else {
      pvVar3 = operator_new((*(int *)(unaff_EBP + -0x1b4) - *(int *)(unaff_EBP + -0x1b8)) * 4);
      *(void **)(unaff_EBP + -0x1e8) = pvVar3;
      *(undefined4 *)(unaff_EBP + -0x1c8) = *(undefined4 *)(unaff_EBP + -0x1e8);
      pvVar3 = operator_new((*(int *)(unaff_EBP + -0x1c0) - *(int *)(unaff_EBP + -0x1c4)) * 4);
      *(void **)(unaff_EBP + -0x1ec) = pvVar3;
      *(undefined4 *)(unaff_EBP + -0x1cc) = *(undefined4 *)(unaff_EBP + -0x1ec);
      if ((*(int *)(unaff_EBP + -0x1c8) != 0) && (*(int *)(unaff_EBP + -0x1cc) != 0)) {
        *(undefined4 *)(unaff_EBP + -0x28c) = DAT_006fe8bc;
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x28c) + 4))();
        *(undefined4 *)(unaff_EBP + -0x290) = uVar2;
        *(undefined4 *)(unaff_EBP + -0x294) = *(undefined4 *)(unaff_EBP + -0x278);
        *(undefined4 *)(unaff_EBP + -0x294) = DAT_006fe8bc;
        iVar4 = (*(int *)(unaff_EBP + -0x1b4) - *(int *)(unaff_EBP + -0x1b8)) * 2;
        lpWideCharStr_00 = *(LPWSTR *)(unaff_EBP + -0x1c8);
        cchWideChar = -1;
        lpWideCharStr = *(LPWSTR *)(unaff_EBP + -0x1b8);
        iVar14 = 1;
        pCVar11 = (LPCSTR)(**(code **)(**(int **)(unaff_EBP + -0x290) + 0x1c))();
        DVar13 = 0;
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x294) + 4))();
        *(undefined4 *)(unaff_EBP + -0x298) = uVar2;
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x298) + 0x58))();
        *(undefined4 *)(unaff_EBP + -0x29c) = uVar2;
        UVar12 = (**(code **)(**(int **)(unaff_EBP + -0x29c) + 0x78))();
        MultiByteToWideChar(UVar12,DVar13,pCVar11,iVar14,lpWideCharStr,cchWideChar);
        *(undefined4 *)(unaff_EBP + -0x2a0) = DAT_006fe8bc;
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x2a0) + 4))();
        *(undefined4 *)(unaff_EBP + -0x2a4) = uVar2;
        *(undefined4 *)(unaff_EBP + -0x2a8) = *(undefined4 *)(unaff_EBP + -0x27c);
        *(undefined4 *)(unaff_EBP + -0x2a8) = DAT_006fe8bc;
        iVar14 = (*(int *)(unaff_EBP + -0x1c0) - *(int *)(unaff_EBP + -0x1c4)) * 2;
        pCVar11 = *(LPCSTR *)(unaff_EBP + -0x1cc);
        DVar13 = 0xffffffff;
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x2a4) + 0x1c))
                          (1,*(undefined4 *)(unaff_EBP + -0x1c4));
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x2a8) + 4))(0,uVar2);
        *(undefined4 *)(unaff_EBP + -0x2ac) = uVar2;
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x2ac) + 0x58))();
        *(undefined4 *)(unaff_EBP + -0x2b0) = uVar2;
        UVar12 = (**(code **)(**(int **)(unaff_EBP + -0x2b0) + 0x78))();
        MultiByteToWideChar(UVar12,DVar13,pCVar11,iVar14,lpWideCharStr_00,iVar4);
        iVar4 = MessageBoxW((HWND)0x0,*(LPCWSTR *)(unaff_EBP + -0x1c8),
                            *(LPCWSTR *)(unaff_EBP + -0x1cc),0);
        *(int *)(unaff_EBP + -0x1d0) = iVar4;
      }
      *(undefined4 *)(unaff_EBP + -0x1f0) = *(undefined4 *)(unaff_EBP + -0x1c8);
      FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x1f0));
      *(undefined4 *)(unaff_EBP + -500) = *(undefined4 *)(unaff_EBP + -0x1cc);
      FUN_006321f0(*(undefined4 *)(unaff_EBP + -500));
    }
    FUN_00637cca(1);
  }
  if (*(int *)(unaff_EBP + -0x28) != 0) {
    *(undefined4 *)(unaff_EBP + -0x1fc) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x1f8) = *(undefined4 *)(unaff_EBP + -0x1fc);
    if (*(int *)(unaff_EBP + -0x1f8) == 0) {
      *(undefined4 *)(unaff_EBP + -0x2b4) = 0;
    }
    else {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x1f8))(1);
      *(undefined4 *)(unaff_EBP + -0x2b4) = uVar2;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

