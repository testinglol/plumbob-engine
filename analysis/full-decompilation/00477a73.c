
undefined4 FUN_00477a73(void)

{
  int iVar1;
  char cVar2;
  undefined3 uVar7;
  int *piVar3;
  undefined1 *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int *piVar8;
  int iVar9;
  int unaff_EBP;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  
  FUN_00634c24();
  iVar10 = *(int *)(unaff_EBP + 8);
  iVar12 = *(int *)(extraout_ECX + 0x10);
  if (iVar12 == iVar10) {
    uVar7 = (undefined3)((uint)iVar10 >> 8);
  }
  else {
    *(int *)(extraout_ECX + 0x10) = iVar10;
    if ((*(int *)(extraout_ECX + 0x14) == 0) ||
       (*(int *)(*(int *)(extraout_ECX + 0x14) + 8) < iVar10)) {
      FUN_004782a0();
      pvVar5 = operator_new(0x20);
      *(void **)(unaff_EBP + -0x4c) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0047c37a(0x40);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(extraout_ECX + 0x14) = uVar6;
      pvVar5 = operator_new(0x20);
      *(void **)(unaff_EBP + -0x4c) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0047c8fb(0x40);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(extraout_ECX + 0x18) = uVar6;
      pvVar5 = operator_new(0x20);
      *(void **)(unaff_EBP + -0x4c) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0047cb08(0x40);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(extraout_ECX + 0x1c) = uVar6;
      pvVar5 = operator_new(0x20);
      *(void **)(unaff_EBP + -0x4c) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      if (pvVar5 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_0047cb08(0x40);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(extraout_ECX + 0x20) = uVar6;
      pvVar5 = operator_new(0x28);
      *(void **)(unaff_EBP + -0x4c) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      if (pvVar5 == (void *)0x0) {
        iVar10 = 0;
      }
      else {
        iVar10 = FUN_00461651(0x40);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(extraout_ECX + 0x60) = iVar10;
      if (iVar10 != 0) {
        FUN_00461765();
      }
      pvVar5 = operator_new(0x28);
      *(void **)(unaff_EBP + -0x4c) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 5;
      if (pvVar5 == (void *)0x0) {
        iVar10 = 0;
      }
      else {
        iVar10 = FUN_004772fb(0x40);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(extraout_ECX + 100) = iVar10;
      if (iVar10 != 0) {
        FUN_00461765();
      }
      puVar11 = (undefined4 *)(extraout_ECX + 0x2c);
      *(undefined4 *)(unaff_EBP + -0x24) = 2;
      do {
        pvVar5 = operator_new(0x20);
        *(void **)(unaff_EBP + -0x4c) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 6;
        if (pvVar5 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_0047c57e(0x40);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        puVar11[-2] = uVar6;
        pvVar5 = operator_new(0x20);
        *(void **)(unaff_EBP + -0x4c) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 7;
        if (pvVar5 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_0047c57e(0x40);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *puVar11 = uVar6;
        pvVar5 = operator_new(0x20);
        *(void **)(unaff_EBP + -0x4c) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 8;
        if (pvVar5 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_0047c8fb(0x40);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        puVar11[2] = uVar6;
        pvVar5 = operator_new(0x20);
        *(void **)(unaff_EBP + -0x4c) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 9;
        if (pvVar5 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_0047ccd7(0x40);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        puVar11[6] = uVar6;
        pvVar5 = operator_new(0x20);
        *(void **)(unaff_EBP + -0x4c) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 10;
        if (pvVar5 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_0047c747(0x40);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        puVar11[4] = uVar6;
        pvVar5 = operator_new(0x20);
        *(void **)(unaff_EBP + -0x4c) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 0xb;
        if (pvVar5 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_0047ce8c(0x40);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        puVar11[8] = uVar6;
        pvVar5 = operator_new(0xc);
        *(void **)(unaff_EBP + -0x20) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 0xc;
        if (pvVar5 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          FUN_0055e4e2(unaff_EBP + -0xd);
          *(undefined1 *)(unaff_EBP + -4) = 0xd;
          FUN_0047c545(0x1000);
          uVar6 = *(undefined4 *)(unaff_EBP + -0x20);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        puVar11[0xf] = uVar6;
        pvVar5 = operator_new(0x28);
        *(void **)(unaff_EBP + -0x4c) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 0xe;
        if (pvVar5 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_0056e03b(0x40);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        puVar11[0xb] = uVar6;
        puVar11 = puVar11 + 1;
        piVar3 = (int *)(unaff_EBP + -0x24);
        *piVar3 = *piVar3 + -1;
      } while (*piVar3 != 0);
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      do {
        piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x4c,0x3f);
        *(undefined1 *)(*piVar3 + *(int *)(unaff_EBP + -0x1c)) = 0xff;
        piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x48,0x3f);
        iVar10 = *piVar3;
        iVar12 = *(int *)(unaff_EBP + -0x1c);
        puVar11 = (undefined4 *)(extraout_ECX + 0x68);
        *(undefined4 *)(unaff_EBP + -0x24) = 2;
        *(undefined1 *)(iVar10 + iVar12) = 0xff;
        *(int *)(unaff_EBP + -0x2c) = (char)iVar12 * 4 + 0x3f00;
        *(int *)(unaff_EBP + -0x28) = iVar12 * 2;
        do {
          piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x44,0x3f);
          iVar10 = *piVar3;
          *(undefined4 *)(unaff_EBP + -4) = 0xf;
          _memset((void *)(iVar10 + *(int *)(unaff_EBP + -0x18)),0,0xe);
          piVar3 = (int *)*puVar11;
          iVar10 = *(int *)(unaff_EBP + -0x2c);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          iVar12 = *piVar3;
          *(undefined1 *)(iVar12 + 3 + iVar10) = 0x7f;
          puVar4 = (undefined1 *)(iVar12 + iVar10);
          puVar4[2] = 0x7f;
          puVar4[1] = 0x7f;
          *puVar4 = 0x7f;
          piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x40,0x3f);
          puVar11 = puVar11 + 1;
          iVar12 = *piVar3;
          piVar3 = (int *)(unaff_EBP + -0x24);
          *piVar3 = *piVar3 + -1;
          iVar10 = *piVar3;
          *(undefined1 *)(*(int *)(unaff_EBP + -0x28) + iVar12) = 0;
        } while (iVar10 != 0);
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 0xe;
      } while (*(int *)(unaff_EBP + -0x18) < 0x380);
      FUN_00478ac2();
    }
    else if (iVar10 < iVar12) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (0 < iVar10) {
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
        *(int *)(unaff_EBP + -0x28) = (int)(char)((char)iVar10 + -1) << 6;
        *(int *)(unaff_EBP + -0x14) = iVar10 + -1;
        do {
          piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + -0x14));
          uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
          *(undefined1 *)(*piVar3 + *(int *)(unaff_EBP + -0x18)) = 0xff;
          piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x34,uVar6);
          iVar12 = *piVar3;
          iVar1 = *(int *)(unaff_EBP + -0x18);
          iVar10 = extraout_ECX + 0x2c;
          *(undefined4 *)(unaff_EBP + -0x24) = 2;
          *(undefined1 *)(iVar12 + iVar1) = 0xff;
          *(int *)(unaff_EBP + -0x2c) = ((int)(char)iVar1 + *(int *)(unaff_EBP + -0x28)) * 4;
          *(int *)(unaff_EBP + -0x1c) = iVar1 * 2;
          do {
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
            uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
            *(undefined2 *)(*(int *)(unaff_EBP + -0x1c) + *piVar3) = 0;
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x3c,uVar6);
            uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
            *(undefined2 *)(*piVar3 + *(int *)(unaff_EBP + -0x1c)) = 0;
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x40,uVar6);
            iVar12 = *piVar3;
            *(undefined4 *)(unaff_EBP + -4) = 0x10;
            _memset((void *)(iVar12 + *(int *)(unaff_EBP + -0x20)),0,0xe);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x44,*(undefined4 *)(unaff_EBP + -0x14));
            *(undefined2 *)(*piVar3 + *(int *)(unaff_EBP + -0x1c)) = 0;
            *(undefined4 *)(unaff_EBP + -4) = 0x11;
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x48,*(undefined4 *)(unaff_EBP + -0x14));
            iVar12 = *piVar3;
            iVar1 = *(int *)(unaff_EBP + -0x2c);
            uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(undefined1 *)(iVar12 + *(int *)(unaff_EBP + -0x18)) = 0;
            iVar12 = **(int **)(iVar10 + 0x3c);
            *(undefined1 *)(iVar12 + 3 + iVar1) = 0x7f;
            puVar4 = (undefined1 *)(iVar12 + iVar1);
            puVar4[2] = 0x7f;
            puVar4[1] = 0x7f;
            *puVar4 = 0x7f;
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x4c,uVar6);
            iVar1 = *piVar3;
            iVar10 = iVar10 + 4;
            piVar3 = (int *)(unaff_EBP + -0x24);
            *piVar3 = *piVar3 + -1;
            iVar12 = *piVar3;
            *(undefined1 *)(iVar1 + *(int *)(unaff_EBP + -0x1c)) = 0;
          } while (iVar12 != 0);
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 0xe;
        } while (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + 8));
        iVar10 = *(int *)(unaff_EBP + 8);
      }
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (0 < iVar10) {
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
        *(int *)(unaff_EBP + -0x28) = iVar10 * 0xe;
        *(int *)(unaff_EBP + -0x2c) = (int)(char)((char)iVar10 + -1);
        do {
          piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x4c,*(undefined4 *)(unaff_EBP + -0x14));
          uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
          *(undefined1 *)(*(int *)(unaff_EBP + 8) + -1 + *piVar3) = 0xff;
          piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x48,uVar6);
          iVar12 = *piVar3;
          iVar10 = extraout_ECX + 0x2c;
          *(undefined4 *)(unaff_EBP + -0x24) = 2;
          *(undefined1 *)(iVar12 + -1 + *(int *)(unaff_EBP + 8)) = 0xff;
          *(int *)(unaff_EBP + -0x20) =
               (*(char *)(unaff_EBP + -0x14) * 0x40 + *(int *)(unaff_EBP + -0x2c)) * 4;
          do {
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x44,*(undefined4 *)(unaff_EBP + -0x14));
            uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
            *(undefined2 *)(*piVar3 + -2 + *(int *)(unaff_EBP + 8) * 2) = 0;
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x40,uVar6);
            uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
            *(undefined2 *)(*piVar3 + -2 + *(int *)(unaff_EBP + 8) * 2) = 0;
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x3c,uVar6);
            iVar12 = *piVar3;
            *(undefined4 *)(unaff_EBP + -4) = 0x12;
            _memset((void *)(*(int *)(unaff_EBP + -0x28) + -0xe + iVar12),0,0xe);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
            *(undefined2 *)(*piVar3 + -2 + *(int *)(unaff_EBP + 8) * 2) = 0;
            *(undefined4 *)(unaff_EBP + -4) = 0x13;
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x34,*(undefined4 *)(unaff_EBP + -0x14));
            iVar12 = *piVar3;
            uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            iVar1 = *(int *)(unaff_EBP + -0x20);
            *(undefined1 *)(iVar12 + -1 + *(int *)(unaff_EBP + 8)) = 0;
            iVar12 = **(int **)(iVar10 + 0x3c);
            *(undefined1 *)(iVar12 + 3 + iVar1) = 0x7f;
            puVar4 = (undefined1 *)(iVar12 + iVar1);
            puVar4[2] = 0x7f;
            puVar4[1] = 0x7f;
            *puVar4 = 0x7f;
            piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x30,uVar6);
            iVar1 = *piVar3;
            iVar9 = *(int *)(unaff_EBP + 8);
            iVar10 = iVar10 + 4;
            piVar3 = (int *)(unaff_EBP + -0x24);
            *piVar3 = *piVar3 + -1;
            iVar12 = *piVar3;
            *(undefined1 *)(iVar1 + -2 + iVar9 * 2) = 0;
          } while (iVar12 != 0);
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        } while (*(int *)(unaff_EBP + -0x14) < iVar9);
      }
    }
    FUN_0047b6ce(0);
    FUN_00407761();
    piVar3 = *(int **)(unaff_EBP + 8);
    *(int **)(extraout_ECX + 0x10) = piVar3;
    iVar10 = DAT_006e54d8;
    if (DAT_006e54d8 != 0) {
      *(undefined1 *)(unaff_EBP + -0x14) = 0;
      *(undefined1 *)(unaff_EBP + -0x13) = 0;
      *(undefined1 *)(unaff_EBP + -0x12) = 0;
      cVar2 = (char)piVar3 + -1;
      *(undefined4 *)(unaff_EBP + -4) = 0x14;
      *(char *)(unaff_EBP + -0x18) = cVar2;
      *(undefined1 *)(unaff_EBP + -0x17) = 0;
      *(undefined1 *)(unaff_EBP + -0x16) = 0;
      *(char *)(unaff_EBP + -0x1c) = cVar2;
      *(char *)(unaff_EBP + -0x1b) = cVar2;
      *(undefined1 *)(unaff_EBP + -0x1a) = 0;
      *(undefined1 *)(unaff_EBP + 8) = 0;
      *(char *)(unaff_EBP + 9) = cVar2;
      *(undefined1 *)(unaff_EBP + 10) = 0;
      uVar6 = *(undefined4 *)(iVar10 + 0x84);
      *(undefined1 *)(unaff_EBP + -4) = 0x17;
      FUN_00434ffd(uVar6);
      FUN_00434ffd(*(undefined4 *)(DAT_006e54d8 + 0x84));
      FUN_00434ffd(*(undefined4 *)(DAT_006e54d8 + 0x84));
      FUN_00434ffd(*(undefined4 *)(DAT_006e54d8 + 0x84));
      iVar10 = (int)*(char *)(unaff_EBP + -0x18);
      iVar12 = (int)*(char *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x24) = iVar12;
      *(int *)(unaff_EBP + -0x2c) = iVar10;
      piVar3 = (int *)(unaff_EBP + -0x2c);
      if (iVar12 <= iVar10) {
        piVar3 = (int *)(unaff_EBP + -0x24);
      }
      iVar9 = (int)*(char *)(unaff_EBP + -0x1c);
      piVar8 = (int *)(extraout_ECX + 0x70);
      *piVar8 = *piVar3;
      iVar1 = *piVar8;
      *(int *)(unaff_EBP + -0x2c) = iVar9;
      piVar3 = (int *)(unaff_EBP + -0x2c);
      if (iVar1 <= iVar9) {
        piVar3 = piVar8;
      }
      *piVar8 = *piVar3;
      iVar1 = *piVar8;
      *(int *)(unaff_EBP + -0x2c) = (int)*(char *)(unaff_EBP + 8);
      piVar3 = (int *)(unaff_EBP + -0x2c);
      if (iVar1 <= *(char *)(unaff_EBP + 8)) {
        piVar3 = piVar8;
      }
      *piVar8 = *piVar3;
      *(int *)(unaff_EBP + -0x2c) = iVar10;
      *(int *)(unaff_EBP + -0x28) = iVar12;
      piVar3 = (int *)(unaff_EBP + -0x2c);
      if (iVar10 <= iVar12) {
        piVar3 = (int *)(unaff_EBP + -0x28);
      }
      piVar8 = (int *)(extraout_ECX + 0x74);
      *piVar8 = *piVar3;
      iVar10 = *piVar8;
      *(int *)(unaff_EBP + -0x2c) = iVar9;
      piVar3 = (int *)(unaff_EBP + -0x2c);
      if (iVar9 <= iVar10) {
        piVar3 = piVar8;
      }
      *piVar8 = *piVar3;
      iVar10 = *piVar8;
      *(int *)(unaff_EBP + -0x2c) = (int)*(char *)(unaff_EBP + 8);
      piVar3 = (int *)(unaff_EBP + -0x2c);
      if (*(char *)(unaff_EBP + 8) <= iVar10) {
        piVar3 = piVar8;
      }
      iVar10 = (int)*(char *)(unaff_EBP + -0x17);
      iVar12 = (int)*(char *)(unaff_EBP + -0x13);
      *piVar8 = *piVar3;
      *(int *)(unaff_EBP + -0x2c) = iVar10;
      *(int *)(unaff_EBP + -0x24) = iVar12;
      piVar3 = (int *)(unaff_EBP + -0x2c);
      if (iVar12 <= iVar10) {
        piVar3 = (int *)(unaff_EBP + -0x24);
      }
      iVar9 = (int)*(char *)(unaff_EBP + -0x1b);
      piVar8 = (int *)(extraout_ECX + 0x78);
      *piVar8 = *piVar3;
      iVar1 = *piVar8;
      *(int *)(unaff_EBP + -0x2c) = iVar9;
      piVar3 = (int *)(unaff_EBP + -0x2c);
      if (iVar1 <= iVar9) {
        piVar3 = piVar8;
      }
      *piVar8 = *piVar3;
      iVar1 = *piVar8;
      *(int *)(unaff_EBP + -0x2c) = (int)*(char *)(unaff_EBP + 9);
      piVar3 = (int *)(unaff_EBP + -0x2c);
      if (iVar1 <= *(char *)(unaff_EBP + 9)) {
        piVar3 = piVar8;
      }
      *piVar8 = *piVar3;
      *(int *)(unaff_EBP + -0x2c) = iVar10;
      *(int *)(unaff_EBP + -0x28) = iVar12;
      piVar8 = (int *)(unaff_EBP + -0x2c);
      if (iVar10 <= iVar12) {
        piVar8 = (int *)(unaff_EBP + -0x28);
      }
      piVar3 = (int *)(extraout_ECX + 0x7c);
      *piVar3 = *piVar8;
      iVar10 = *piVar3;
      *(int *)(unaff_EBP + -0x2c) = iVar9;
      piVar8 = (int *)(unaff_EBP + -0x2c);
      if (iVar9 <= iVar10) {
        piVar8 = piVar3;
      }
      *piVar3 = *piVar8;
      iVar10 = *piVar3;
      *(int *)(unaff_EBP + 8) = (int)*(char *)(unaff_EBP + 9);
      piVar8 = (int *)(unaff_EBP + 8);
      if (*(char *)(unaff_EBP + 9) <= iVar10) {
        piVar8 = piVar3;
      }
      *piVar3 = *piVar8;
    }
    uVar7 = (undefined3)((uint)piVar3 >> 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT31(uVar7,1);
}

