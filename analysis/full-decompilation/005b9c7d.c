
undefined1 FUN_005b9c7d(void)

{
  char cVar1;
  undefined1 uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x38) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b9589(unaff_EBP + 8);
  FUN_005b86bd(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005ba3d5(unaff_EBP + -0x4c);
  FUN_005a509f(unaff_EBP + -200,unaff_EBP + 8);
  if (*(int *)(unaff_EBP + -200) == 0) {
    pvVar3 = operator_new(0x80);
    *(void **)(unaff_EBP + -0x34) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar3 == (void *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      piVar5 = (int *)0x0;
    }
    else {
      uVar4 = FUN_004096c2();
      piVar5 = (int *)FUN_005be7fe(uVar4);
      *(int **)(unaff_EBP + -0x18) = piVar5;
    }
    iVar7 = *piVar5;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    (**(code **)(iVar7 + 0x7c))(0x4000,0);
    cVar1 = (**(code **)(*piVar5 + 0xc))(1,2,1);
    if (cVar1 == '\0') {
      FUN_005b8680();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b8d0f(unaff_EBP + -0x74,s_FAR_byAZCouldn_t_Open_file___s__f_006d250c + 8,
                   *(undefined4 *)(unaff_EBP + 8));
      OutputDebugStringA(*(LPCSTR *)(unaff_EBP + -0x74));
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x80))(1);
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
LAB_005ba3b5:
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar2 = 0;
      goto LAB_005ba385;
    }
    puVar6 = (undefined4 *)FUN_005bac93(unaff_EBP + 8);
    *puVar6 = piVar5;
    pvVar3 = operator_new(0x24);
    *(void **)(unaff_EBP + -0x68) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (pvVar3 == (void *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    else {
      uVar4 = (**(code **)(*piVar5 + 0x1c))();
      FUN_005b8680();
      piVar5 = *(int **)(unaff_EBP + -0x18);
      *(undefined4 *)((int)pvVar3 + 0x10) = uVar4;
      *(int **)((int)pvVar3 + 0xc) = piVar5;
      *(undefined4 *)((int)pvVar3 + 0x14) = 0;
      *(undefined4 *)((int)pvVar3 + 0x18) = 0;
      *(undefined1 *)((int)pvVar3 + 0x1c) = 0;
      *(undefined1 *)((int)pvVar3 + 0x1d) = 0;
      *(undefined4 *)((int)pvVar3 + 0x20) = 0;
      *(void **)(unaff_EBP + -0x14) = pvVar3;
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar7 = FUN_005b8e6a(unaff_EBP + -0x1c4,8);
    if (((iVar7 == 8) && (iVar7 = FUN_005b8e6a(unaff_EBP + -0xcc,4), iVar7 == 4)) &&
       (iVar7 = FUN_005b8e6a(unaff_EBP + -0x80,4), iVar7 == 4)) {
      FUN_005b8f4a(*(undefined4 *)(unaff_EBP + -0x80));
      iVar7 = FUN_005b8e6a(unaff_EBP + -100,4);
      if (iVar7 == 4) {
        FUN_005b8680();
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_005b8680();
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_005b8680();
        *(undefined1 *)(unaff_EBP + -4) = 7;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        if (0 < *(int *)(unaff_EBP + -100)) {
          do {
            iVar7 = FUN_005b8e6a(unaff_EBP + -0x68,4);
            if (((iVar7 != 4) || (iVar7 = FUN_005b8e6a(unaff_EBP + -0xd8,4), iVar7 != 4)) ||
               ((iVar7 = FUN_005b8e6a(unaff_EBP + -0x84,4), iVar7 != 4 ||
                ((iVar7 = FUN_005b8e6a(unaff_EBP + -0x34,4), iVar7 != 4 ||
                 (iVar7 = *(int *)(unaff_EBP + -0x34),
                 iVar8 = FUN_005b8e6a(unaff_EBP + -0x9c4,iVar7), iVar8 != iVar7)))))) {
              *(undefined1 *)(unaff_EBP + -4) = 6;
              FUN_005b8770();
              *(undefined1 *)(unaff_EBP + -4) = 5;
              FUN_005b8770();
              *(undefined1 *)(unaff_EBP + -4) = 1;
              goto LAB_005ba3b5;
            }
            *(undefined1 *)(unaff_EBP + -0x9c4 + *(int *)(unaff_EBP + -0x34)) = 0;
            FUN_005d499c(unaff_EBP + -0x4c);
            FUN_005b8789(unaff_EBP + -0x9c4);
            FUN_005b96fe(*(undefined4 *)(unaff_EBP + -0x58),unaff_EBP + -0x24,unaff_EBP + -0x30);
            iVar7 = *(int *)(unaff_EBP + -0x38);
            cVar1 = FUN_005b9c38(unaff_EBP + -0x24,unaff_EBP + -0x30,0);
            if (cVar1 == '\0') {
              FUN_005a509f(unaff_EBP + -0x7c,unaff_EBP + -0x24);
              if (*(int *)(unaff_EBP + -0x7c) == 0) {
                FUN_005bace3(100,unaff_EBP + -0x3e,unaff_EBP + -0x3b,unaff_EBP + -0x39);
                *(undefined1 *)(unaff_EBP + -4) = 8;
                FUN_005b86bd(unaff_EBP + -0x24);
                *(undefined1 *)(unaff_EBP + -4) = 9;
                FUN_005bad33(unaff_EBP + -0x120);
                iVar7 = *(int *)(iVar7 + 0x10);
                *(undefined1 *)(unaff_EBP + -4) = 10;
                FUN_005bb9b7(iVar7 + 1);
                FUN_005bb8cd(unaff_EBP + -0x74,unaff_EBP + -0x158);
                *(undefined1 *)(unaff_EBP + -4) = 8;
                FUN_005ba44c();
                *(undefined1 *)(unaff_EBP + -4) = 0xb;
                FUN_005bb5f0();
                *(undefined1 *)(unaff_EBP + -4) = 7;
                FUN_005481b6();
                if (*(char *)(unaff_EBP + -0x6c) != '\0') {
                  *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x74);
                  *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x70);
                }
              }
              iVar7 = *(int *)(unaff_EBP + -0x7c);
              FUN_005a509f(unaff_EBP + -0xc0,unaff_EBP + -0x30);
              if (*(int *)(unaff_EBP + -0xc0) == 0) {
                *(undefined4 *)(unaff_EBP + -0xac) = 0;
                *(undefined4 *)(unaff_EBP + -0xa8) = 0;
                *(undefined4 *)(unaff_EBP + -0xa4) = 0;
                *(undefined4 *)(unaff_EBP + -0xa0) = 0;
                *(undefined1 *)(unaff_EBP + -0x9c) = 0;
                *(undefined1 *)(unaff_EBP + -0x9b) = 0;
                *(undefined1 *)(unaff_EBP + -0x9a) = 0;
                FUN_005b86bd(unaff_EBP + -0x30);
                *(undefined1 *)(unaff_EBP + -4) = 0xc;
                FUN_005bb113(unaff_EBP + -0xac);
                iVar7 = *(int *)(iVar7 + 0x20);
                *(undefined1 *)(unaff_EBP + -4) = 0xd;
                FUN_005bb4b8(iVar7 + 1);
                FUN_005bb337(unaff_EBP + -0xe4,unaff_EBP + -0x178);
                *(undefined1 *)(unaff_EBP + -4) = 7;
                FUN_005b8770();
                if (*(char *)(unaff_EBP + -0xdc) != '\0') {
                  iVar7 = *(int *)(unaff_EBP + -0xe4);
                  if ((undefined4 *)(iVar7 + 0x10) != (undefined4 *)0x0) {
                    *(undefined1 *)(iVar7 + 0x20) = 1;
                    *(undefined1 *)(iVar7 + 0x21) = 0;
                    *(undefined4 *)(iVar7 + 0x10) = piVar5;
                    *(undefined4 *)(iVar7 + 0x14) = *(undefined4 *)(unaff_EBP + -0x84);
                    *(undefined4 *)(iVar7 + 0x1c) = *(undefined4 *)(unaff_EBP + -0x68);
                    *(undefined1 *)(iVar7 + 0x22) = 0;
                  }
                }
              }
              iVar7 = FUN_005d49d6();
              iVar7 = iVar7 + -1;
              uVar4 = FUN_004096c2(iVar7);
              FUN_005b86cf(uVar4,iVar7);
              *(undefined1 *)(unaff_EBP + -4) = 0xe;
              FUN_005b96fe(*(undefined4 *)(unaff_EBP + -0xf0),unaff_EBP + -0x24,unaff_EBP + -0x30);
              *(undefined1 *)(unaff_EBP + -0xd) = 0;
              while ((*(int *)(unaff_EBP + -0x24) != *(int *)(unaff_EBP + -0x20) &&
                     (*(char *)(unaff_EBP + -0xd) == '\0'))) {
                iVar7 = *(int *)(unaff_EBP + -0x38);
                FUN_005a509f(unaff_EBP + -0x60,unaff_EBP + -0x24);
                if (*(int *)(unaff_EBP + -0x60) == 0) {
                  FUN_005bace3(100,unaff_EBP + -0x3d,unaff_EBP + -0x3c,unaff_EBP + -0x3a);
                  *(undefined1 *)(unaff_EBP + -4) = 0xf;
                  FUN_005b86bd(unaff_EBP + -0x24);
                  *(undefined1 *)(unaff_EBP + -4) = 0x10;
                  FUN_005bad33(unaff_EBP + -0x138);
                  iVar7 = *(int *)(iVar7 + 0x10);
                  *(undefined1 *)(unaff_EBP + -4) = 0x11;
                  FUN_005bb9b7(iVar7 + 1);
                  FUN_005bb8cd(unaff_EBP + -0xb8,unaff_EBP + -0x1b8);
                  *(undefined1 *)(unaff_EBP + -4) = 0xf;
                  FUN_005ba44c();
                  *(undefined1 *)(unaff_EBP + -4) = 0x12;
                  FUN_005bb5f0();
                  *(undefined1 *)(unaff_EBP + -4) = 0xe;
                  FUN_005481b6();
                  if (*(char *)(unaff_EBP + -0xb0) != '\0') {
                    *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0xb8);
                    *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0xb4);
                  }
                  if (*(int *)(unaff_EBP + -0x60) != 0) goto LAB_005ba1e3;
                  *(undefined1 *)(unaff_EBP + -0xd) = 1;
                }
                else {
LAB_005ba1e3:
                  iVar7 = *(int *)(unaff_EBP + -0x60);
                  FUN_005a509f(unaff_EBP + -0xd4,unaff_EBP + -0x30);
                  if (*(int *)(unaff_EBP + -0xd4) == 0) {
                    *(undefined4 *)(unaff_EBP + -0x98) = 0;
                    *(undefined4 *)(unaff_EBP + -0x94) = 0;
                    *(undefined4 *)(unaff_EBP + -0x90) = 0;
                    *(undefined4 *)(unaff_EBP + -0x8c) = 0;
                    *(undefined1 *)(unaff_EBP + -0x88) = 0;
                    *(undefined1 *)(unaff_EBP + -0x87) = 0;
                    *(undefined1 *)(unaff_EBP + -0x86) = 0;
                    FUN_005b86bd(unaff_EBP + -0x30);
                    *(undefined1 *)(unaff_EBP + -4) = 0x13;
                    FUN_005bb113(unaff_EBP + -0x98);
                    iVar7 = *(int *)(iVar7 + 0x20);
                    *(undefined1 *)(unaff_EBP + -4) = 0x14;
                    FUN_005bb4b8(iVar7 + 1);
                    FUN_005bb337(unaff_EBP + -0x108,unaff_EBP + -0x198);
                    *(undefined1 *)(unaff_EBP + -4) = 0xe;
                    FUN_005b8770();
                    if (*(char *)(unaff_EBP + -0x100) != '\0') {
                      iVar7 = *(int *)(unaff_EBP + -0x108);
                      if ((undefined4 *)(iVar7 + 0x10) != (undefined4 *)0x0) {
                        *(undefined1 *)(iVar7 + 0x20) = 0;
                        *(undefined1 *)(iVar7 + 0x21) = 1;
                        *(undefined4 *)(iVar7 + 0x10) = 0;
                        *(undefined4 *)(iVar7 + 0x14) = 0;
                        *(undefined4 *)(iVar7 + 0x1c) = 0;
                        *(undefined1 *)(iVar7 + 0x22) = 1;
                      }
                    }
                  }
                }
                iVar7 = FUN_005d49d6();
                iVar7 = iVar7 + -1;
                uVar4 = FUN_004096c2(iVar7);
                FUN_005b86cf(uVar4,iVar7);
                *(undefined1 *)(unaff_EBP + -4) = 0x15;
                FUN_005b96fe(*(undefined4 *)(unaff_EBP + -0xfc),unaff_EBP + -0x24,unaff_EBP + -0x30)
                ;
                *(undefined1 *)(unaff_EBP + -4) = 0xe;
                FUN_005b8770();
              }
              *(undefined1 *)(unaff_EBP + -4) = 7;
              FUN_005b8770();
            }
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
          } while (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -100));
          if (0 < *(int *)(unaff_EBP + -100)) {
            *(undefined1 *)(*(int *)(unaff_EBP + -0x38) + 0x2c) = 1;
          }
        }
        if (*(int *)(unaff_EBP + -0x14) != 0) {
          FUN_005b8770();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x14));
        }
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005b8770();
        goto LAB_005ba367;
      }
    }
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
  else {
LAB_005ba367:
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = *(undefined1 *)(unaff_EBP + -0xd);
LAB_005ba385:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

