
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_004b2d29(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 uVar3;
  char cVar4;
  undefined4 uVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  byte bVar11;
  int *extraout_ECX;
  uint uVar12;
  undefined4 extraout_ECX_00;
  int unaff_EBP;
  bool bVar13;
  undefined4 uStack_bc;
  int iStack_b8;
  int *piStack_b4;
  int *piStack_b0;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff58;
  *(int **)(unaff_EBP + -0x44) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined1 *)(unaff_EBP + -0x22) = 0;
  uVar3 = DAT_006f0139;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + -0x11) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  uVar3 = FUN_004c4429();
  *(undefined1 *)(unaff_EBP + -0x58) = uVar3;
  *(int *)(unaff_EBP + -0x54) = DAT_006e4a84;
  *(undefined4 *)(unaff_EBP + -0x50) = _DAT_006f0bc0;
  DAT_006e4a84 = 0;
  *(undefined4 *)(unaff_EBP + -0x4c) = _DAT_006f0bc4;
  *(undefined1 *)(unaff_EBP + -0x1d) = *(undefined1 *)((int)extraout_ECX + 0x51);
  if ((*(char *)(unaff_EBP + 0x2c) != '\0') || (*(int *)(unaff_EBP + 0x28) == 0)) {
    *(undefined1 *)((int)extraout_ECX + 0x51) = 1;
  }
  iVar10 = DAT_006e54dc;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  iVar9 = *(int *)(iVar10 + 0x10);
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  if (iVar9 < 1) {
LAB_004b2e0b:
    *(undefined4 *)(unaff_EBP + -0x1c) = 1;
  }
  else {
    do {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (0 < iVar9) {
        do {
          if ((DAT_006e4a84 != 0) ||
             (uVar12 = ((byte)~*(byte *)(*(int *)(*(int *)(*(int *)(iVar10 + 0x34) + 0xc) +
                                                 *(char *)(unaff_EBP + -0x18) * 4) +
                                        (int)*(char *)(unaff_EBP + -0x38)) & 0x20) >> 5,
             *(uint *)(unaff_EBP + -0x30) = uVar12, uVar12 != 0)) {
            *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + *(int *)(unaff_EBP + -0x18);
            *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + *(int *)(unaff_EBP + -0x38);
            *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
          }
          iVar9 = *(int *)(iVar10 + 0x10);
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
        } while (*(int *)(unaff_EBP + -0x18) < iVar9);
      }
      *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + 1;
    } while (*(int *)(unaff_EBP + -0x38) < iVar9);
    if (*(int *)(unaff_EBP + -0x1c) == 0) goto LAB_004b2e0b;
  }
  uVar3 = __ftol();
  *(undefined1 *)(unaff_EBP + -0x18) = uVar3;
  uVar3 = __ftol();
  *(undefined1 *)(unaff_EBP + -0x24) = *(undefined1 *)(unaff_EBP + -0x18);
  *(undefined1 *)(unaff_EBP + -0x23) = uVar3;
  *(undefined1 *)(unaff_EBP + -0x22) = 1;
  piStack_b0 = (int *)0x4b2e52;
  FUN_00434ffd();
  uVar5 = __ftol();
  *(undefined4 *)(unaff_EBP + -0x2c) = uVar5;
  uVar5 = __ftol();
  *(undefined4 *)(unaff_EBP + -0x28) = uVar5;
  if ((*(int **)(unaff_EBP + 0x34) == (int *)0x0) ||
     (iVar9 = **(int **)(unaff_EBP + 0x34), iVar9 == 0)) {
    uVar5 = 100;
    piStack_b0 = (int *)0x4b2e93;
    pvVar6 = operator_new(100);
    *(void **)(unaff_EBP + 8) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar6 == (void *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)FUN_005dfb13();
      uVar5 = extraout_ECX_00;
    }
    *(int **)(unaff_EBP + 0xc) = piVar8;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(int **)(unaff_EBP + 8) = piVar8;
    if (piVar8 != (int *)0x0) {
      iVar9 = *piVar8;
      piStack_b0 = (int *)0x0;
      piStack_b4 = (int *)0x0;
      *(undefined4 **)(unaff_EBP + -0x30) = &uStack_bc;
      uStack_bc = uVar5;
      iStack_b8 = uVar5;
      FUN_00436a50(4);
      uVar5 = *(undefined4 *)(unaff_EBP + 0xc);
      cVar4 = (**(code **)(iVar9 + 0xc))
                        (*(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28));
      if (cVar4 != '\0') {
        cVar4 = FUN_005df69e();
        if (cVar4 != '\0') {
          if (*(undefined4 **)(unaff_EBP + 0x34) != (undefined4 *)0x0) {
            **(undefined4 **)(unaff_EBP + 0x34) = uVar5;
          }
          goto LAB_004b2efe;
        }
      }
    }
    piVar8 = *(int **)(unaff_EBP + -0x40);
  }
  else {
    *(int *)(unaff_EBP + 8) = iVar9;
LAB_004b2efe:
    piStack_b0 = (int *)0x4b2f0c;
    FUN_004b38e5();
    *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EBP + 0x14);
    *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + 0x10);
    iVar9 = *(int *)(unaff_EBP + 0x28);
    *(int *)(unaff_EBP + -0x78) = iVar9;
    if (iVar9 == 0) {
      *(undefined4 *)(unaff_EBP + -0x78) = 2;
    }
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + 0x18);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + 0x1c);
    *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(unaff_EBP + -0x6c) = 0;
    *(undefined4 *)(unaff_EBP + -0x68) = 0;
    *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x28);
    if (((*(char *)(unaff_EBP + 0x38) == '\0') || (*(char *)(unaff_EBP + 0x2c) != '\0')) ||
       (*(undefined1 *)(unaff_EBP + -0x5c) = 1, iVar9 == 0)) {
      *(undefined1 *)(unaff_EBP + -0x5c) = 0;
    }
    *(undefined1 *)(unaff_EBP + -0x5b) = 0;
    *(undefined1 *)(unaff_EBP + -0x5a) = 0;
    piStack_b0 = (int *)0x4b2f6d;
    FUN_004b3938();
    piStack_b0 = (int *)0x4b2f74;
    pvVar6 = operator_new(0x74);
    *(void **)(unaff_EBP + 0x38) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar6 == (void *)0x0) {
      *(undefined4 *)(unaff_EBP + 0x38) = 0;
    }
    else {
      piStack_b0 = (int *)0x4b2f88;
      uVar5 = FUN_004b4533();
      *(undefined4 *)(unaff_EBP + 0x38) = uVar5;
    }
    piStack_b0 = (int *)0xf;
    piStack_b4 = (int *)0x0;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + 0x38);
    iStack_b8 = 0x4b2fa3;
    FUN_004b463f();
    piVar8 = *(int **)(unaff_EBP + 0x24);
    if ((piVar8 != (int *)0x0) && (*(char *)(unaff_EBP + 0x2c) == '\0')) {
      bVar13 = *(float *)(unaff_EBP + 0x20) == _DAT_00666578;
      *(undefined4 *)(unaff_EBP + 0x10) = 0;
      if (bVar13) {
        *(undefined4 *)(unaff_EBP + 0x10) = 1;
      }
      else if (*(float *)(unaff_EBP + 0x20) == _DAT_00666a48) {
        *(undefined4 *)(unaff_EBP + 0x10) = 2;
      }
      else if (*(float *)(unaff_EBP + 0x20) == _DAT_00668220) {
        *(undefined4 *)(unaff_EBP + 0x10) = 3;
      }
      piStack_b0 = piVar8 + 1;
      iStack_b8 = 0x4b3005;
      piStack_b4 = piVar8;
      FUN_004b3e97();
      bVar11 = (byte)*(undefined4 *)(unaff_EBP + 0x10);
      *piVar8 = *piVar8 >> (bVar11 & 0x1f);
      piVar8[1] = piVar8[1] >> (bVar11 & 0x1f);
      piVar8[2] = extraout_ECX[0x7d] >> (bVar11 & 0x1f);
    }
    if ((*(int *)(unaff_EBP + 0x18) == 0x7fffffff) && (*(int *)(unaff_EBP + 0x1c) == 0x7fffffff)) {
      piStack_b0 = (int *)0x0;
      iStack_b8 = unaff_EBP + -0x34;
      piStack_b4 = (int *)0x1;
      uStack_bc = 0x4b3038;
      puVar7 = (undefined4 *)FUN_00434d3d();
      iStack_b8 = puVar7[1];
      uStack_bc = *puVar7;
      FUN_004a7baa();
      piStack_b0 = (int *)(extraout_ECX[0x5d] + DAT_006f0084);
      piStack_b4 = (int *)(extraout_ECX[0x5c] + DAT_006f0080);
      extraout_ECX[0x5c] = 0;
      extraout_ECX[0x5d] = 0;
      iStack_b8 = 0x4b3077;
      FUN_004a83dc();
      piStack_b0 = *(int **)(unaff_EBP + 0x28);
      if (piStack_b0 == (int *)0x0) {
        piStack_b0 = (int *)0x2;
      }
      piStack_b4 = (int *)0x4b308a;
      FUN_004a82db();
    }
    piStack_b0 = (int *)0x4b3098;
    FUN_004c440c();
    uVar1 = *(undefined2 *)(unaff_EBP + 0x30);
    *(undefined1 *)(extraout_ECX + 0x5f) = 1;
    *(undefined2 *)((int)extraout_ECX + 0x182) = uVar1;
    DAT_006f0139 = 0;
    piStack_b0 = (int *)0x4b30b7;
    FUN_004bbabe();
    (**(code **)(*extraout_ECX + 0x48))();
    FUN_004a8aa5();
    cVar4 = *(char *)(unaff_EBP + 0x2c);
    *(undefined1 *)(extraout_ECX + 0x14) = 1;
    if (cVar4 == '\0') {
      piStack_b0 = *(int **)(unaff_EBP + 8);
      piStack_b4 = (int *)0x4b30dc;
      FUN_004b038a();
      *(undefined2 *)(unaff_EBP + -0x34) = *(undefined2 *)(unaff_EBP + -0x68);
      *(undefined2 *)(unaff_EBP + -0x30) = *(undefined2 *)(unaff_EBP + -0x60);
      piStack_b0 = *(int **)(unaff_EBP + 0x38);
      *(undefined2 *)(unaff_EBP + -0x32) = *(undefined2 *)(unaff_EBP + -0x6c);
      *(undefined2 *)(unaff_EBP + -0x2e) = *(undefined2 *)(unaff_EBP + -100);
      _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x34);
      _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x30);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      piStack_b4 = (int *)0x4b311b;
      FUN_004ad0c7();
      piStack_b0 = (int *)&DAT_006f0bc0;
      piStack_b4 = (int *)0x4b312a;
      FUN_004aa3e7();
      piVar8 = (int *)FUN_004b3137();
      return piVar8;
    }
    if (*(char *)((int)extraout_ECX + 0x51) != '\0') {
      iVar9 = *(int *)(unaff_EBP + 8);
      iVar10 = *(int *)(iVar9 + 0x1c);
      iVar2 = *(int *)(iVar9 + 0x14);
      *(int *)(unaff_EBP + -0x44) = *(int *)(iVar9 + 0x20) - *(int *)(iVar9 + 0x18);
      uVar5 = *(undefined4 *)(extraout_ECX[0x1a] + 0x10);
      *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(extraout_ECX[0x1a] + 0x14);
      iVar9 = extraout_ECX[0x21];
      *(undefined4 *)(unaff_EBP + -0x34) = uVar5;
      *(int *)(unaff_EBP + 0x38) = iVar9;
      piStack_b0 = (int *)0x4b3184;
      cVar4 = FUN_004b0db9();
      if (cVar4 != '\0') {
        piStack_b4 = (int *)0x4b3198;
        piStack_b0 = (int *)(iVar10 - iVar2);
        FUN_005cf06d();
        FUN_004a7d36();
        iVar9 = extraout_ECX[0x1a];
        bVar13 = DAT_006e4870 != '\0';
        *(undefined1 *)(unaff_EBP + 0x2f) = *(undefined1 *)(iVar9 + 0x66);
        if (bVar13) {
          *(undefined1 *)(iVar9 + 0x66) = 0;
        }
        piStack_b0 = (int *)0x4b31bd;
        iVar9 = FUN_005ce621();
        if (-1 < iVar9) {
          iVar9 = 0;
          do {
            piStack_b0 = (int *)0x4b31cf;
            iVar10 = FUN_00479149();
            if (iVar10 != 0) {
              piStack_b4 = (int *)(iVar9 + 1);
              piStack_b0 = (int *)0x0;
              iStack_b8 = extraout_ECX[0x1a];
              uStack_bc = 0x4b31e3;
              FUN_0056eb75();
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < 2);
          FUN_005ce67e();
        }
        *(undefined1 *)(extraout_ECX[0x1a] + 0x66) = *(undefined1 *)(unaff_EBP + 0x2f);
        piStack_b0 = (int *)0x4b3204;
        FUN_004b0db9();
        piStack_b0 = *(int **)(unaff_EBP + -0x34);
        piStack_b4 = (int *)0x4b3212;
        FUN_005cf06d();
        FUN_004a7d36();
      }
    }
    _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x50);
    _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x4c);
    *(undefined1 *)((int)extraout_ECX + 0x51) = *(undefined1 *)(unaff_EBP + -0x1d);
    *(undefined1 *)(extraout_ECX + 0x14) = 0;
    piStack_b0 = (int *)0x4b3240;
    FUN_004b3938();
    DAT_006f0139 = *(undefined1 *)(unaff_EBP + -0x11);
    *(undefined1 *)(extraout_ECX + 0x5f) = 0;
    piStack_b0 = (int *)0x4b325e;
    FUN_004c440c();
    piStack_b0 = (int *)0x4b3265;
    FUN_004bbabe();
    (**(code **)(*extraout_ECX + 0x48))();
    piVar8 = *(int **)(unaff_EBP + 8);
    if (*(ushort *)((int)extraout_ECX + 0x182) == DAT_006f2a64) {
      piStack_b0 = (int *)0x4b3287;
      (**(code **)(*piVar8 + 0x68))();
    }
    iStack_b8 = *(undefined4 *)(unaff_EBP + 0x20);
    piStack_b0 = (int *)0x0;
    uStack_bc = 0x4b3296;
    piStack_b4 = piVar8;
    piVar8 = (int *)FUN_004ba969();
    if (piVar8 != (int *)0x0) {
      piStack_b0 = (int *)0x4b32a9;
      (**(code **)(*piVar8 + 0x68))();
    }
  }
  DAT_006e4a84 = *(undefined4 *)(unaff_EBP + -0x54);
  if (*(int *)(unaff_EBP + -0x3c) != 0) {
    piStack_b0 = (int *)0x4b32c3;
    FUN_006321f0();
  }
  if ((*(int *)(unaff_EBP + 0x34) == 0) && (*(undefined4 **)(unaff_EBP + 8) != (undefined4 *)0x0)) {
    piStack_b0 = (int *)0x4b32d6;
    (**(code **)**(undefined4 **)(unaff_EBP + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar8;
}

