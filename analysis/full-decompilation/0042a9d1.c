
void FUN_0042a9d1(void)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *piVar6;
  int *piVar7;
  undefined4 extraout_ECX;
  uint uVar8;
  int unaff_EBP;
  int iVar9;
  char *pcVar10;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  DVar2 = timeGetTime();
  FUN_005bc6cb(DVar2);
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  FUN_0042af8c();
  piVar6 = DAT_006e486c;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if ((*(byte *)((int)piVar6 + 0x66) & 4) != 0) {
    iVar9 = 0;
    while (iVar3 = FUN_0043ad1f(iVar9), iVar3 != 0) {
      if (*(short *)(*(int *)(iVar3 + 0x60) + 0x12) == 0x400) {
        uVar4 = FUN_0045741b();
        *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
        FUN_0040555d(unaff_EBP + -0x10);
      }
      else if ((*(short *)(*(int *)(iVar3 + 0x60) + 0x12) == 0x200) &&
              (*(int *)(unaff_EBP + -0x28) == 0)) {
        uVar4 = FUN_0045741b();
        *(undefined4 *)(unaff_EBP + -0x28) = uVar4;
      }
      iVar9 = iVar9 + 1;
    }
    iVar9 = *(int *)(unaff_EBP + -0x18);
    uVar8 = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    piVar6 = (int *)(iVar9 + 0x154);
    if (*(int *)(iVar9 + 0x158) - *piVar6 >> 2 != 0) {
      do {
        if (*(int *)(*(int *)(*piVar6 + uVar8 * 4) + 0x10c) == 2000) {
          *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*piVar6 + uVar8 * 4);
          break;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < (uint)(*(int *)(iVar9 + 0x158) - *piVar6 >> 2));
    }
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xd4) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar4 = FUN_0041532c(9,unaff_EBP + -0xd4,0);
    cVar1 = FUN_004fff98(0xd3,uVar4);
    iVar9 = *(int *)(unaff_EBP + -0x14);
    if (iVar9 == 0) {
      pvVar5 = operator_new(0x15c);
      *(void **)(unaff_EBP + -0x10) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if (pvVar5 == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_004100cf(*(undefined4 *)(*DAT_006e486c + 0x14),2000);
      }
      *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_0046f824(unaff_EBP + -0x1d4,0,0x100);
      *(undefined ***)(unaff_EBP + -0x1e0) = &PTR_FUN_00666524;
      if (cVar1 == '\0') {
        pcVar10 = s_Townie_006c2878;
      }
      else {
        pcVar10 = (char *)FUN_004705f2(1,0xffffffff);
      }
      FUN_0046f8cb(pcVar10);
      FUN_004108c4(unaff_EBP + -0x1e0);
      FUN_0042eb8e(unaff_EBP + -0x14);
      pvVar5 = operator_new(0x13c);
      *(void **)(unaff_EBP + -0x10) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      if (pvVar5 == (void *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)FUN_00525cfd();
      }
      *(undefined1 *)(unaff_EBP + -4) = 2;
      *(int **)(unaff_EBP + -0x2c) = piVar6;
      if (piVar6 == (int *)0x0) goto LAB_0042aca2;
      uVar4 = FUN_004705f2(2,0xffffffff);
      FUN_005d4956(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_00525fb7(unaff_EBP + -0x38);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      uVar4 = FUN_004705f2(3,0xffffffff);
      FUN_005d4956(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005260e7(unaff_EBP + -0x38);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      FUN_005a5631(0xea6,unaff_EBP + -0x10,4);
      if (*(int *)(unaff_EBP + -0x10) != 0) {
        FUN_005260b1(*(undefined4 *)(unaff_EBP + -0x10),1);
      }
      piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
      piVar7 = (int *)(**(code **)(*piVar7 + 8))();
      (**(code **)(*piVar6 + 0x138))();
      (**(code **)(*piVar7 + 0x20))(piVar6);
      (**(code **)(*piVar6 + 0x94))();
      (**(code **)(*piVar6 + 0x44))();
      FUN_00526e66(*(undefined4 *)(unaff_EBP + 8));
      do {
        (*(code *)**(undefined4 **)(DAT_006e486c[0x13] + 0x48))();
LAB_0042aca2:
        do {
          do {
            do {
              if ((9 < (uint)(*(int *)(*(int *)(unaff_EBP + -0x14) + 0x130) -
                              *(int *)(*(int *)(unaff_EBP + -0x14) + 300) >> 2)) ||
                 (iVar9 = *(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x24) >> 2, iVar9 == 0
                 )) goto LAB_0042ae6a;
            } while (iVar9 < 1);
            iVar9 = FUN_005bc722(iVar9);
            iVar3 = FUN_00426392(*(undefined4 *)(iVar9 * 4 + *(int *)(unaff_EBP + -0x24)),
                                 unaff_EBP + -0x68);
          } while (iVar3 == 0);
          FUN_0042ec52(iVar9 * 4 + *(int *)(unaff_EBP + -0x24));
          (*(code *)**(undefined4 **)(DAT_006e486c[0x13] + 0x48))();
          FUN_004108dc(iVar3);
        } while (piVar6 == (int *)0x0);
        FUN_00526e73();
      } while( true );
    }
    uVar8 = *(uint *)(unaff_EBP + 8);
    if ((uint)(*(int *)(iVar9 + 0x130) - *(int *)(iVar9 + 300) >> 2) < uVar8) {
      iVar3 = *(int *)(iVar9 + 0x130);
      iVar9 = *(int *)(iVar9 + 300);
      pvVar5 = operator_new(0x13c);
      *(void **)(unaff_EBP + -0x10) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 7;
      if (pvVar5 == (void *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)FUN_00525cfd();
      }
      *(undefined1 *)(unaff_EBP + -4) = 2;
      *(int **)(unaff_EBP + -0x2c) = piVar6;
      FUN_00526e66(uVar8 - (iVar3 - iVar9 >> 2));
      if (piVar6 != (int *)0x0) {
        uVar4 = FUN_004705f2(4,0xffffffff);
        FUN_005d4956(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_00525fb7(unaff_EBP + -0x38);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_005b8770();
        uVar4 = FUN_004705f2(5,0xffffffff);
        FUN_005d4956(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_005260e7(unaff_EBP + -0x38);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        FUN_005a5631(0xea6,unaff_EBP + -0x10,4);
        if (*(int *)(unaff_EBP + -0x10) != 0) {
          FUN_005260b1(*(undefined4 *)(unaff_EBP + -0x10),1);
        }
        piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
        piVar7 = (int *)(**(code **)(*piVar7 + 8))();
        (**(code **)(*piVar6 + 0x138))();
        (**(code **)(*piVar7 + 0x20))(piVar6);
        (**(code **)(*piVar6 + 0x94))();
        (**(code **)(*piVar6 + 0x44))();
        (*(code *)**(undefined4 **)(DAT_006e486c[0x13] + 0x48))();
      }
LAB_0042ae6a:
      if ((uint)(*(int *)(*(int *)(unaff_EBP + -0x14) + 0x130) -
                 *(int *)(*(int *)(unaff_EBP + -0x14) + 300) >> 2) < *(uint *)(unaff_EBP + 8)) {
        if (*(int *)(unaff_EBP + -0x2c) != 0) {
          FUN_00526e73();
        }
        (*(code *)**(undefined4 **)(DAT_006e486c[0x13] + 0x48))();
        if ((*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x24) >> 2 != 0) &&
           (iVar9 = FUN_005bc722(5), iVar9 == 3)) goto code_r0x0042aec1;
        iVar9 = FUN_00426392(*(undefined4 *)(unaff_EBP + -0x28),unaff_EBP + -0x68);
        goto LAB_0042af18;
      }
      if (*(int *)(unaff_EBP + -0x2c) != 0) {
        FUN_005da4c7(*(undefined4 *)(unaff_EBP + -0x2c));
      }
      FUN_00425316(DAT_006e486c[0x11]);
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00470467();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042afde();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
code_r0x0042aec1:
  iVar9 = *(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x24) >> 2;
  if (0 < iVar9) {
    iVar3 = FUN_005bc722(iVar9);
    iVar9 = FUN_00426392(*(undefined4 *)(iVar3 * 4 + *(int *)(unaff_EBP + -0x24)),unaff_EBP + -0x68)
    ;
    if (iVar9 != 0) {
      FUN_0042ec52(iVar3 * 4 + *(int *)(unaff_EBP + -0x24));
LAB_0042af18:
      if (iVar9 != 0) {
        FUN_004108dc(iVar9);
      }
    }
  }
  goto LAB_0042ae6a;
}

