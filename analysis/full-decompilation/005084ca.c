
void FUN_005084ca(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  void *pvVar7;
  int extraout_ECX;
  uint extraout_ECX_00;
  int iVar8;
  int iVar9;
  int unaff_EBP;
  uint uStack_1c4;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 0xa8;
  *(undefined4 *)(unaff_EBP + -0x30) = 0x7f;
  FUN_005ed3c4();
  FUN_005ed3c4();
  uVar2 = (**(code **)(**(int **)(extraout_ECX + 0xd8) + 0x58))();
  piVar4 = *(int **)(extraout_ECX + 0xd8);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  iVar3 = (**(code **)(*piVar4 + 0x68))();
  iVar8 = *(int *)(extraout_ECX + 0x84) - *(int *)(extraout_ECX + 0x7c);
  *(int *)(unaff_EBP + -0x90) = iVar3 + 0xb2;
  iVar6 = DAT_006e486c;
  iVar9 = iVar8 + -0xc;
  iVar3 = *(int *)(unaff_EBP + -0x18) + 0xc;
  *(int *)(unaff_EBP + -0x8c) = iVar3;
  *(int *)(unaff_EBP + -0x7c) = iVar3;
  cVar1 = *(char *)(iVar6 + 100);
  *(int *)(unaff_EBP + -0x80) = iVar9;
  if (cVar1 == '\x13') {
    iVar9 = iVar8 + -0x11;
    *(int *)(unaff_EBP + -0x80) = iVar9;
  }
  if (*(int *)(extraout_ECX + 0xe0) != 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    piVar4 = (int *)FUN_004752f8();
    if (*piVar4 != piVar4[1]) {
      puVar5 = (undefined4 *)FUN_004752f8();
      *(undefined4 *)(unaff_EBP + -0x14) = *puVar5;
      FUN_004752f8();
      FUN_004752f8();
      piVar4 = (int *)FUN_004752f8();
      iVar3 = piVar4[1];
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      iVar3 = iVar3 - *piVar4;
      *(int *)(unaff_EBP + -0x1c) = iVar3;
      iVar6 = iVar3;
      while (0 < iVar6) {
        iVar6 = (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x58))();
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar6;
        iVar6 = (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x60))();
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar6;
        iVar6 = iVar3 - *(int *)(unaff_EBP + -0x10);
        *(int *)(unaff_EBP + -0x1c) = iVar6;
      }
      iVar3 = *(int *)(unaff_EBP + -0x8c);
    }
    *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x18) + iVar3;
  }
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  puVar5 = (undefined4 *)(extraout_ECX + 0x120);
  do {
    iVar3 = FUN_004cd119();
    if (iVar3 != 0) {
      if (*(int *)(unaff_EBP + -0x10) < 7) {
        wsprintfA((LPSTR)(unaff_EBP + -0x1a8),(LPCSTR)*puVar5);
        uStack_1c4 = 0x508665;
        _strlen((char *)(unaff_EBP + -0x1a8));
      }
      FUN_00412d8a();
      FUN_004015e4();
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    puVar5 = puVar5 + 3;
  } while (*(int *)(unaff_EBP + -0x10) < 0xe);
  iVar3 = *(int *)(unaff_EBP + -0x44);
  if (iVar3 != *(int *)(unaff_EBP + -0x48)) {
    FUN_00406466();
    iVar3 = *(int *)(unaff_EBP + -0x44);
  }
  iVar6 = *(int *)(unaff_EBP + -0x48);
  iVar8 = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  if (iVar6 != iVar3) {
    iVar3 = iVar3 - iVar6;
    *(int *)(unaff_EBP + -0x14) = iVar6;
    *(int *)(unaff_EBP + -0x10) = iVar3;
    *(int *)(unaff_EBP + -0x18) = iVar3;
    while (0 < iVar3) {
      iVar3 = (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x58))();
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + iVar3;
      iVar3 = (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x60))();
      iVar8 = iVar8 + iVar3;
      iVar3 = *(int *)(unaff_EBP + -0x10) - iVar8;
      *(int *)(unaff_EBP + -0x18) = iVar3;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x10) = 5;
  iVar3 = *(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + -0x7c);
  iVar6 = *(int *)(extraout_ECX + 0xe0);
  *(int *)(unaff_EBP + -0x9c) = iVar3;
  *(int *)(unaff_EBP + -0x6c) = iVar3;
  if (*(int *)(iVar6 + 0x28) != 0) {
    cVar1 = FUN_004578c8();
    if (cVar1 == '\0') {
      cVar1 = FUN_00457935();
      if (cVar1 == '\0') {
        cVar1 = FUN_00457a80();
        if (cVar1 == '\0') {
          cVar1 = FUN_00457a11();
          if (cVar1 == '\0') {
            cVar1 = FUN_004579a2();
            if (cVar1 == '\0') goto LAB_005087bb;
            *(undefined4 *)(unaff_EBP + -0x10) = 2;
          }
          else {
            *(undefined4 *)(unaff_EBP + -0x10) = 3;
          }
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x10) = 4;
        }
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x10) = 1;
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
    iVar6 = (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x58))();
    *(int *)(unaff_EBP + -0x6c) = iVar6 + iVar3;
  }
LAB_005087bb:
  iVar3 = *(int *)(unaff_EBP + -0x6c);
  iVar6 = *(int *)(extraout_ECX + 0xe0);
  *(int *)(unaff_EBP + -0x60) = iVar9;
  *(undefined4 *)(unaff_EBP + -0x68) = 0xb2;
  *(int *)(unaff_EBP + -100) = iVar3;
  *(int *)(unaff_EBP + -0x5c) = iVar3;
  if (*(int *)(iVar6 + 0x28) != 0) {
    cVar1 = FUN_00457b46();
    if (cVar1 == '\0') {
      iVar3 = *(int *)(unaff_EBP + -0x5c);
    }
    else {
      iVar3 = (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x58))();
      iVar3 = iVar3 + *(int *)(unaff_EBP + -100);
      *(int *)(unaff_EBP + -0x5c) = iVar3;
    }
  }
  iVar6 = *(int *)(extraout_ECX + 0x84);
  iVar3 = iVar3 + 0xc;
  iVar8 = *(int *)(extraout_ECX + 0x7c);
  *(int *)(unaff_EBP + -0x18) = iVar3;
  *(int *)(unaff_EBP + -0x14) = iVar6 - iVar8;
  if (iVar3 < 0x7f) {
    iVar3 = 0x7f;
    *(undefined4 *)(unaff_EBP + -0x18) = 0x7f;
  }
  FUN_004ec1a7();
  iVar6 = *(int *)(extraout_ECX + 0x118);
  *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x38) + iVar3;
  if (iVar6 == 0) {
    pvVar7 = operator_new(100);
    *(void **)(unaff_EBP + -0x1c) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar7 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_005dfb13();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(extraout_ECX + 0x118) = uVar2;
  }
  cVar1 = (**(code **)(**(int **)(extraout_ECX + 0x118) + 0x18))();
  if (cVar1 != '\0') {
    uVar2 = **(undefined4 **)(extraout_ECX + 0x118);
    *(uint **)(unaff_EBP + -0x1c) = &uStack_1c4;
    *(undefined4 *)(unaff_EBP + -0x1c) = uVar2;
    uStack_1c4 = extraout_ECX_00;
    FUN_00436a50(4);
    cVar1 = (**(code **)(*(int *)(unaff_EBP + -0x1c) + 0xc))
                      (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x18));
    if ((cVar1 != '\0') && (cVar1 = FUN_005df69e(), cVar1 != '\0')) {
      cVar1 = (**(code **)(**(int **)(extraout_ECX + 0x118) + 0x20))();
      if (cVar1 != '\0') {
        uStack_1c4 = *(uint *)(extraout_ECX + 0x114);
        *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(uStack_1c4 + 0x14);
        *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(uStack_1c4 + 0x18);
        iVar3 = *(int *)(uStack_1c4 + 0x1c);
        *(int *)(unaff_EBP + -0x50) = iVar3;
        *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(uStack_1c4 + 0x20);
        *(int *)(unaff_EBP + -0x50) = iVar3 / 3;
        piVar4 = *(int **)(extraout_ECX + 0x118);
        *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x4c) / 3;
        (**(code **)(*piVar4 + 0xc0))();
        (**(code **)(**(int **)(extraout_ECX + 0x118) + 0x24))(0x10);
      }
      if (*(int *)(unaff_EBP + -0x30) - *(int *)(unaff_EBP + -0x38) <
          *(int *)(extraout_ECX + 0x88) - *(int *)(extraout_ECX + 0x80)) {
        iVar3 = (((*(int *)(extraout_ECX + 0x88) - *(int *)(extraout_ECX + 0x80)) -
                 *(int *)(unaff_EBP + -0x30)) + *(int *)(unaff_EBP + -0x38)) / 2 -
                *(int *)(unaff_EBP + -0x38);
        *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + iVar3;
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + iVar3;
        iVar3 = *(int *)(*(int *)(extraout_ECX + 0x118) + 0x20);
        if (iVar3 < *(int *)(unaff_EBP + -0x30)) {
          iVar3 = iVar3 - *(int *)(unaff_EBP + -0x30);
          *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + iVar3;
          *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + iVar3;
        }
      }
      cVar1 = (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x118) + 0x5c) + 0x20))();
      if (cVar1 != '\0') {
        uStack_1c4 = 0xffff;
        (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x118) + 0x5c) + 0x40))();
        (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x118) + 0x5c) + 0x24))(1);
      }
      uStack_1c4 = 0x5089bc;
      FUN_004cbd1c();
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x90);
      *(undefined4 *)(unaff_EBP + -0x2c) = 0xb2;
      *(undefined4 *)(unaff_EBP + -0x28) = 0xc;
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x8c);
      FUN_005ed3c4();
      puVar5 = (undefined4 *)FUN_005ed3c4();
      piVar4 = *(int **)(extraout_ECX + 0xd8);
      *(undefined4 *)(unaff_EBP + -0x14) = *puVar5;
      uStack_1c4 = *(uint *)(unaff_EBP + -0x14);
      (**(code **)(*piVar4 + 0x80))(*(undefined4 *)(extraout_ECX + 0x118),unaff_EBP + -0x2c);
      piVar4 = (int *)FUN_005ed3c4();
      iVar3 = piVar4[1];
      iVar6 = *piVar4;
      FUN_005ed3c4();
      puVar5 = *(undefined4 **)(extraout_ECX + 0xd8);
      *(undefined4 **)(unaff_EBP + -0x14) = puVar5;
      *(undefined4 *)(unaff_EBP + -0x18) = *puVar5;
      uVar2 = FUN_004096c2(iVar3 - iVar6);
      iVar3 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x68))(uVar2);
      piVar4 = *(int **)(extraout_ECX + 0xd8);
      *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + iVar3;
      (**(code **)(*piVar4 + 0x80))
                (*(undefined4 *)(extraout_ECX + 0x118),unaff_EBP + -0x2c,&DAT_006cc6a0,4,0);
      iVar3 = (**(code **)(**(int **)(extraout_ECX + 0xd8) + 0x68))(&DAT_006cc6a0,4);
      *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + iVar3;
      iVar3 = *(int *)(extraout_ECX + 0xe8);
      iVar6 = *(int *)(extraout_ECX + 0xe4);
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX + 0xe4);
      (**(code **)(**(int **)(extraout_ECX + 0xd8) + 0x80))
                (*(undefined4 *)(extraout_ECX + 0x118),unaff_EBP + -0x2c,
                 *(undefined4 *)(unaff_EBP + -0x14),iVar3 - iVar6,0);
      iVar3 = *(int *)(unaff_EBP + -0x80);
      *(undefined4 *)(unaff_EBP + -0x2c) = 0xb2;
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x8c);
      *(int *)(unaff_EBP + -0x24) = iVar3;
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x7c);
      uVar2 = FUN_004752f8();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
      puVar5 = (undefined4 *)FUN_004752f8();
      *(undefined4 *)(unaff_EBP + -0x18) = *puVar5;
      (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x80))
                (*(undefined4 *)(extraout_ECX + 0x118),unaff_EBP + -0x2c,
                 *(undefined4 *)(unaff_EBP + -0x18),
                 (*(int **)(unaff_EBP + -0x14))[1] - **(int **)(unaff_EBP + -0x14),0);
      if (0xb2 < iVar3) {
        if (*(int *)(unaff_EBP + -0x7c) < *(int *)(unaff_EBP + -0x9c)) {
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x9c);
          piVar4 = *(int **)(extraout_ECX + 0xdc);
          *(undefined4 *)(unaff_EBP + -0x2c) = 0xb2;
          *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x7c);
          *(int *)(unaff_EBP + -0x24) = iVar3;
          uVar2 = (**(code **)(*piVar4 + 0x1c))();
          piVar4 = *(int **)(extraout_ECX + 0xdc);
          *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
          (**(code **)(*piVar4 + 0x20))();
          uStack_1c4 = unaff_EBP - 0x2c;
          (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x80))
                    (*(undefined4 *)(extraout_ECX + 0x118));
          (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x20))(*(undefined4 *)(unaff_EBP + -0x14));
        }
      }
      if (*(int *)(unaff_EBP + -0x10) != 5) {
        piVar4 = *(int **)(extraout_ECX + 0xdc);
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x9c);
        *(undefined4 *)(unaff_EBP + -0x2c) = 0xb2;
        *(int *)(unaff_EBP + -0x24) = iVar3;
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x6c);
        uVar2 = (**(code **)(*piVar4 + 0x1c))();
        piVar4 = *(int **)(extraout_ECX + 0xdc);
        *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
        (**(code **)(*piVar4 + 0x20))();
        *(undefined4 *)(unaff_EBP + -0x14) =
             *(undefined4 *)(extraout_ECX + (*(int *)(unaff_EBP + -0x10) * 3 + 0x72) * 4);
        uStack_1c4 = unaff_EBP - 0x2c;
        (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x80))(*(undefined4 *)(extraout_ECX + 0x118))
        ;
        (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x20))(*(undefined4 *)(unaff_EBP + -0x18));
      }
      if ((*(int *)(unaff_EBP + -0x68) < *(int *)(unaff_EBP + -0x60)) &&
         (*(int *)(unaff_EBP + -100) < *(int *)(unaff_EBP + -0x5c))) {
        piVar4 = *(int **)(extraout_ECX + 0xdc);
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x9c);
        *(undefined4 *)(unaff_EBP + -0x2c) = 0xb2;
        *(int *)(unaff_EBP + -0x24) = iVar3;
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x6c);
        uVar2 = (**(code **)(*piVar4 + 0x1c))();
        piVar4 = *(int **)(extraout_ECX + 0xdc);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
        (**(code **)(*piVar4 + 0x20))();
        uStack_1c4 = unaff_EBP - 0x68;
        (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x80))(*(undefined4 *)(extraout_ECX + 0x118))
        ;
        (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x20))(*(undefined4 *)(unaff_EBP + -0x14));
      }
      cVar1 = FUN_004cd0fd();
      if ((cVar1 == '\0') &&
         (cVar1 = (**(code **)(**(int **)(extraout_ECX + 0x118) + 0x20))(), piVar4 = DAT_006fe8bc,
         cVar1 != '\0')) {
        *(int *)(unaff_EBP + -0x78) = *(int *)(unaff_EBP + -0x3c) + 4;
        *(int *)(unaff_EBP + -0x70) = *(int *)(unaff_EBP + -0x34) + -4;
        *(int *)(unaff_EBP + -0x74) = *(int *)(unaff_EBP + -0x38) + 4;
        *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x30) + -4;
        piVar4 = (int *)(**(code **)(*piVar4 + 0x1c))();
        iVar3 = **(int **)(extraout_ECX + 0x118);
        uStack_1c4 = 0x508cfe;
        uStack_1c4 = (**(code **)(*piVar4 + 0x38))();
        uStack_1c4 = uStack_1c4 & 0xffff;
        (**(code **)(iVar3 + 0x54))(unaff_EBP + -0x78);
        (**(code **)(**(int **)(extraout_ECX + 0x118) + 0x24))(8);
      }
      piVar4 = *(int **)(extraout_ECX + 0x11c);
      if (piVar4 != (int *)0x0) {
        *(int *)(unaff_EBP + -0x58) = piVar4[0x1f];
        *(int *)(unaff_EBP + -0x54) = piVar4[0x20];
        *(int *)(unaff_EBP + -0x50) = piVar4[0x21];
        *(int *)(unaff_EBP + -0x4c) = piVar4[0x22];
        iVar3 = (**(code **)(*piVar4 + 0x18))();
        if (iVar3 != 0) {
          FUN_00436feb();
          FUN_00436feb();
        }
        FUN_004cb21d();
      }
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

