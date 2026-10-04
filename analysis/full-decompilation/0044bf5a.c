
void FUN_0044bf5a(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 extraout_ECX;
  uint uVar11;
  int unaff_EBP;
  short sVar12;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  FUN_0046f824(unaff_EBP + -0x58,0,0x20);
  *(undefined ***)(unaff_EBP + -100) = &PTR_FUN_006666e4;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
  }
  else {
    *(undefined2 *)(unaff_EBP + -0x20) = *(undefined2 *)(*(int *)(unaff_EBP + 0xc) + 4);
  }
  for (iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),&DAT_006e5030,0,unaff_EBP + -0x14,
                            unaff_EBP + -0x10,unaff_EBP + -0x18); iVar4 != -1;
      iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),&DAT_006e5030,iVar4 + 1,unaff_EBP + -0x14,
                           unaff_EBP + -0x10,unaff_EBP + -0x18)) {
    if (((*(int *)(unaff_EBP + 0xc) != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
       (*(int *)(unaff_EBP + -0x10) < (int)(uint)*(byte *)(*(int *)(unaff_EBP + 0xc) + 6))) {
      iVar5 = FUN_004752fc();
      iVar5 = FUN_00425db3((int)*(short *)(iVar5 + *(int *)(unaff_EBP + -0x10) * 2));
      if (iVar5 != 0) {
        FUN_0046f824(unaff_EBP + -0x164,0,0x100);
        *(undefined ***)(unaff_EBP + -0x170) = &PTR_FUN_00666524;
        uVar6 = FUN_00410304();
        FUN_0046fa40(uVar6);
        FUN_00455800(iVar4,*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x16c));
      }
    }
  }
  iVar5 = DAT_006e5024 - DAT_006e5020;
  iVar4 = 0;
  while (iVar4 = FUN_004558e0(DAT_006e5020,iVar4,iVar5), iVar4 != -1) {
    iVar5 = FUN_0042573e((int)*(short *)(unaff_EBP + -0x20));
    if ((iVar5 != 0) && (iVar5 = FUN_00425db3((int)*(short *)(iVar5 + 0xee)), iVar5 != 0)) {
      FUN_0046f824(unaff_EBP + -0x164,0,0x100);
      *(undefined ***)(unaff_EBP + -0x170) = &PTR_FUN_00666524;
      FUN_004102d4(unaff_EBP + -0x170);
      FUN_00455800(iVar4,DAT_006e5024 - DAT_006e5020,*(undefined4 *)(unaff_EBP + -0x16c));
      if (*(int *)(unaff_EBP + 0x10) != 0) {
        *(short *)(*(int *)(unaff_EBP + 0x10) + 2) = (short)*(undefined4 *)(iVar5 + 0x10c);
      }
    }
    iVar5 = DAT_006e5024 - DAT_006e5020;
    iVar4 = iVar4 + 1;
  }
  iVar5 = DAT_006e5014 - DAT_006e5010;
  iVar4 = 0;
  while (iVar4 = FUN_004558e0(DAT_006e5010,iVar4,iVar5), iVar4 != -1) {
    if (*(int *)(*(int *)(unaff_EBP + -0x1c) + 0x11c) != 0) {
      iVar5 = DAT_006e5014 - DAT_006e5010;
      uVar6 = thunk_FUN_00457ea7();
      FUN_00455790(iVar4,iVar5,uVar6);
    }
    iVar5 = DAT_006e5014 - DAT_006e5010;
    iVar4 = iVar4 + 1;
  }
  iVar4 = FUN_004558e0(DAT_006e5000,0,DAT_006e5004 - DAT_006e5000);
  if (iVar4 != -1) {
    uVar11 = (uint)*(short *)(unaff_EBP + -0x20);
    do {
      iVar5 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0xdc);
      if (((0 < (int)uVar11) &&
          (uVar11 < (*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x18) >> 2) + 1U)) &&
         ((iVar5 = *(int *)(*(int *)(iVar5 + 0x18) + -4 + uVar11 * 4), iVar5 != 0 &&
          (iVar5 = *(int *)(iVar5 + 0x11c), iVar5 != 0)))) {
        if (*(int **)(unaff_EBP + 0x14) != (int *)0x0) {
          **(int **)(unaff_EBP + 0x14) = iVar5;
        }
        iVar5 = DAT_006e5004 - DAT_006e5000;
        uVar6 = thunk_FUN_00457ea7();
        FUN_00455790(iVar4,iVar5,uVar6);
      }
      iVar4 = FUN_004558e0(DAT_006e5000,iVar4 + 1,DAT_006e5004 - DAT_006e5000);
    } while (iVar4 != -1);
  }
  iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),&DAT_006e4fe0,0,unaff_EBP + -0x14,
                       unaff_EBP + -0x10,unaff_EBP + -0x18);
  if (iVar4 != -1) {
    iVar5 = *(int *)(unaff_EBP + 0xc);
    do {
      if (((iVar5 != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
         (*(int *)(unaff_EBP + -0x10) < (int)(uint)*(byte *)(iVar5 + 6))) {
        *(undefined2 *)(unaff_EBP + -0x5c) = 0;
        **(undefined1 **)(unaff_EBP + -0x60) = 0;
        iVar7 = FUN_004752fc();
        FUN_0046fa40((int)*(short *)(iVar7 + *(int *)(unaff_EBP + -0x10) * 2));
        FUN_00455800(iVar4,*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x60));
      }
      iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),&DAT_006e4fe0,iVar4 + 1,unaff_EBP + -0x14,
                           unaff_EBP + -0x10,unaff_EBP + -0x18);
    } while (iVar4 != -1);
  }
  iVar4 = 0;
  while (iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),&DAT_006e4f60,iVar4,unaff_EBP + -0x14,
                              unaff_EBP + -0x10,unaff_EBP + -0x18), iVar4 != -1) {
    iVar7 = 0;
    uVar11 = (uint)*(short *)(*(int *)(unaff_EBP + 0xc) + 4);
    iVar5 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0xdc);
    if ((0 < (int)uVar11) && (uVar11 < (*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x18) >> 2) + 1U))
    {
      iVar7 = *(int *)(*(int *)(iVar5 + 0x18) + -4 + uVar11 * 4);
    }
    if (((*(int *)(unaff_EBP + 0xc) != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
       (*(int *)(unaff_EBP + -0x10) < *(int *)(iVar7 + 0x30))) {
      *(undefined2 *)(unaff_EBP + -0x5c) = 0;
      **(undefined1 **)(unaff_EBP + -0x60) = 0;
      FUN_0046fa40((int)*(short *)(*(int *)(iVar7 + 0x2c) + *(int *)(unaff_EBP + -0x10) * 2));
      FUN_00455800(iVar4,*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x60));
    }
    iVar4 = iVar4 + 1;
  }
  iVar4 = 0;
  while (iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),&DAT_006e4f80,iVar4,unaff_EBP + -0x14,
                              unaff_EBP + -0x10,unaff_EBP + -0x18), iVar4 != -1) {
    iVar7 = 0;
    uVar11 = (uint)*(short *)(*(int *)(unaff_EBP + 0xc) + 4);
    iVar5 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0xdc);
    if ((0 < (int)uVar11) && (uVar11 < (*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x18) >> 2) + 1U))
    {
      iVar7 = *(int *)(*(int *)(iVar5 + 0x18) + -4 + uVar11 * 4);
    }
    if (((*(int *)(unaff_EBP + 0xc) != 0) && (iVar1 = *(int *)(unaff_EBP + -0x10), -1 < iVar1)) &&
       (iVar1 < *(int *)(iVar7 + 0x30))) {
      iVar7 = 0;
      if ((0 < (int)uVar11) &&
         (uVar11 < (*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x18) >> 2) + 1U)) {
        iVar7 = *(int *)(*(int *)(iVar5 + 0x18) + -4 + uVar11 * 4);
      }
      uVar11 = (uint)*(short *)(*(int *)(iVar7 + 0x2c) + iVar1 * 2);
      if (((0 < (int)uVar11) &&
          (uVar11 < (*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x18) >> 2) + 1U)) &&
         (*(int *)(*(int *)(iVar5 + 0x18) + -4 + uVar11 * 4) != 0)) {
        uVar6 = thunk_FUN_00457ea7();
        FUN_00455790(iVar4,*(undefined4 *)(unaff_EBP + -0x14),uVar6);
      }
    }
    iVar4 = iVar4 + 1;
  }
  uVar6 = *(undefined4 *)(unaff_EBP + 8);
  iVar4 = 0;
  while (iVar4 = FUN_0044cb36(uVar6,&DAT_006e4f90,iVar4,unaff_EBP + -0x14,unaff_EBP + -0x10,
                              unaff_EBP + -0x18), iVar4 != -1) {
    if (((*(int *)(unaff_EBP + 0xc) != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
       (*(int *)(unaff_EBP + -0x10) < (int)(uint)*(byte *)(*(int *)(unaff_EBP + 0xc) + 6))) {
      iVar5 = FUN_004752fc();
      uVar11 = (uint)*(short *)(iVar5 + *(int *)(unaff_EBP + -0x10) * 2);
      iVar5 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0xdc);
      if (((0 < (int)uVar11) &&
          (uVar11 < (*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x18) >> 2) + 1U)) &&
         (*(int *)(*(int *)(iVar5 + 0x18) + -4 + uVar11 * 4) != 0)) {
        uVar8 = thunk_FUN_00457ea7();
        FUN_00455790(iVar4,*(undefined4 *)(unaff_EBP + -0x14),uVar8);
      }
    }
    iVar4 = iVar4 + 1;
  }
  iVar4 = 0;
  while (iVar4 = FUN_0044cb36(uVar6,&DAT_006e4f30,iVar4,unaff_EBP + -0x14,unaff_EBP + -0x10,
                              unaff_EBP + -0x18), iVar4 != -1) {
    if (((*(int *)(unaff_EBP + 0xc) != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
       (*(int *)(unaff_EBP + -0x10) < (int)(uint)*(byte *)(*(int *)(unaff_EBP + 0xc) + 6))) {
      *(undefined2 *)(unaff_EBP + -0x24) = 1;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      iVar5 = FUN_006359f2(*(undefined4 *)(unaff_EBP + -0x1c),0,&cXObject::RTTI_Type_Descriptor,
                           &cXPerson::RTTI_Type_Descriptor,0);
      if (iVar5 == 0) {
        *(undefined4 *)(unaff_EBP + 8) = 0x1c;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
      }
      FUN_0042a8e3(*(undefined2 *)(iVar5 + 0x5ca));
      iVar5 = unaff_EBP + -0x2c;
      iVar7 = FUN_004752fc(iVar5);
      FUN_0041f6fd(*(undefined2 *)(iVar7 + *(int *)(unaff_EBP + -0x10) * 2),iVar5);
      iVar5 = FUN_0043acf5(*(undefined4 *)(unaff_EBP + -0x28));
      if (iVar5 != 0) {
        uVar6 = thunk_FUN_00457ea7();
        FUN_00455790(iVar4,*(undefined4 *)(unaff_EBP + -0x14),uVar6);
      }
    }
    iVar4 = iVar4 + 1;
    uVar6 = *(undefined4 *)(unaff_EBP + 8);
  }
  iVar4 = 0;
  do {
    iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),&DAT_006e4f70,iVar4,unaff_EBP + -0x14,
                         unaff_EBP + -0x10,unaff_EBP + -0x18);
    if (iVar4 == -1) {
LAB_0044c69f:
      iVar4 = FUN_004558e0(DAT_006e5040,0,DAT_006e5044 - DAT_006e5040);
      if (iVar4 != -1) {
        puVar2 = *(undefined2 **)(unaff_EBP + 0x10);
        do {
          iVar5 = FUN_00425b48((int)*(short *)(unaff_EBP + -0x20));
          if (iVar5 != 0) {
            if (*(int **)(unaff_EBP + 0x14) != (int *)0x0) {
              **(int **)(unaff_EBP + 0x14) = iVar5;
            }
            iVar5 = DAT_006e5044 - DAT_006e5040;
            uVar6 = thunk_FUN_00457ea7();
            FUN_00455790(iVar4,iVar5,uVar6);
            if (puVar2 != (undefined2 *)0x0) {
              *puVar2 = *(undefined2 *)(unaff_EBP + -0x20);
            }
          }
          iVar4 = FUN_004558e0(DAT_006e5040,iVar4 + 1,DAT_006e5044 - DAT_006e5040);
        } while (iVar4 != -1);
      }
      iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),&DAT_006e4f50,0,unaff_EBP + -0x14,
                           unaff_EBP + -0x10,unaff_EBP + -0x18);
      if (iVar4 != -1) {
        iVar5 = *(int *)(unaff_EBP + 0xc);
        do {
          if (((iVar5 != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
             (*(int *)(unaff_EBP + -0x10) < (int)(uint)*(byte *)(iVar5 + 6))) {
            iVar7 = FUN_004752fc();
            uVar11 = (uint)*(short *)(iVar7 + *(int *)(unaff_EBP + -0x10) * 2);
            iVar7 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0xdc);
            if (((0 < (int)uVar11) &&
                (uVar11 < (*(int *)(iVar7 + 0x1c) - *(int *)(iVar7 + 0x18) >> 2) + 1U)) &&
               (*(int *)(*(int *)(iVar7 + 0x18) + -4 + uVar11 * 4) != 0)) {
              uVar6 = FUN_0045754a();
              FUN_00455790(iVar4,*(undefined4 *)(unaff_EBP + -0x14),uVar6);
            }
          }
          iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),&DAT_006e4f50,iVar4 + 1,
                               unaff_EBP + -0x14,unaff_EBP + -0x10,unaff_EBP + -0x18);
        } while (iVar4 != -1);
      }
      iVar4 = 0;
      while (iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),&DAT_006e4f40,iVar4,
                                  unaff_EBP + -0x14,unaff_EBP + -0x10,unaff_EBP + -0x18),
            iVar4 != -1) {
        if (((*(int *)(unaff_EBP + 0xc) != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
           (*(int *)(unaff_EBP + -0x10) < (int)(uint)*(byte *)(*(int *)(unaff_EBP + 0xc) + 6))) {
          iVar5 = FUN_004752fc();
          sVar12 = *(short *)(iVar5 + *(int *)(unaff_EBP + -0x10) * 2);
          uVar6 = FUN_0040542d();
          *(undefined4 *)(unaff_EBP + 0x10) = uVar6;
          FUN_005b870f(&DAT_006de560);
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (*(int *)(unaff_EBP + 0x10) != 0) {
            uVar6 = FUN_00405216(unaff_EBP + -0x38,(int)sVar12);
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_005d499c(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_005b8770();
          }
          FUN_00455790(iVar4,*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x2c);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        iVar4 = iVar4 + 1;
      }
      uVar6 = *(undefined4 *)(unaff_EBP + 8);
      iVar4 = 0;
      while (iVar4 = FUN_0044cb36(uVar6,&DAT_006e4fb0,iVar4,unaff_EBP + -0x14,unaff_EBP + -0x10,
                                  unaff_EBP + -0x18), iVar4 != -1) {
        if (((*(int *)(unaff_EBP + 0xc) != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
           (*(int *)(unaff_EBP + -0x10) < (int)(uint)*(byte *)(*(int *)(unaff_EBP + 0xc) + 6))) {
          uVar8 = FUN_004034e6(*(undefined4 *)(unaff_EBP + -0x10));
          FUN_00455800(iVar4,*(undefined4 *)(unaff_EBP + -0x14),uVar8);
        }
        iVar4 = iVar4 + 1;
      }
      iVar4 = 0;
      while (iVar4 = FUN_0044cb36(uVar6,&DAT_006e4fd0,iVar4,unaff_EBP + -0x14,unaff_EBP + -0x10,
                                  unaff_EBP + -0x18), iVar4 != -1) {
        if (((*(int *)(unaff_EBP + 0xc) != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
           (*(int *)(unaff_EBP + -0x10) < (int)(uint)*(byte *)(*(int *)(unaff_EBP + 0xc) + 6))) {
          iVar5 = FUN_004752fc();
          iVar5 = (int)*(short *)(iVar5 + *(int *)(unaff_EBP + -0x10) * 2);
          if ((-1 < iVar5) && (iVar5 < 0x18)) {
            FUN_005b8680();
            *(undefined4 *)(unaff_EBP + -4) = 3;
            FUN_004a6cc9(unaff_EBP + -0x38,iVar5);
            FUN_00455790(iVar4,*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x38);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005b8770();
          }
        }
        iVar4 = iVar4 + 1;
        uVar6 = *(undefined4 *)(unaff_EBP + 8);
      }
      *(undefined4 *)(unaff_EBP + 0x10) = 0;
      *(undefined **)(unaff_EBP + -0x2c) = &DAT_006e4fc0;
      *(undefined **)(unaff_EBP + -0x28) = &DAT_006e4fa0;
      *(undefined **)(unaff_EBP + -0x24) = &DAT_006e4ff0;
      do {
        uVar6 = *(undefined4 *)(unaff_EBP + -0x2c + *(int *)(unaff_EBP + 0x10) * 4);
        iVar4 = 0;
        while (iVar4 = FUN_0044cb36(*(undefined4 *)(unaff_EBP + 8),uVar6,iVar4,unaff_EBP + -0x14,
                                    unaff_EBP + -0x10,unaff_EBP + -0x18), iVar4 != -1) {
          sVar12 = 0;
          iVar5 = FUN_006359f2(*(undefined4 *)(unaff_EBP + -0x1c),0,&cXObject::RTTI_Type_Descriptor,
                               &cXPerson::RTTI_Type_Descriptor,0);
          if ((*(int *)(unaff_EBP + -0x10) == -1) || (*(int *)(unaff_EBP + -0x18) == -1)) {
            if (iVar5 != 0) {
              sVar12 = *(short *)(iVar5 + 0x5fc);
              uVar3 = *(undefined2 *)(iVar5 + 0x5fe);
              goto LAB_0044ca63;
            }
          }
          else if ((((*(int *)(unaff_EBP + 0xc) != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
                   (uVar11 = (uint)*(byte *)(*(int *)(unaff_EBP + 0xc) + 6),
                   *(int *)(unaff_EBP + -0x10) < (int)uVar11)) &&
                  ((-1 < *(int *)(unaff_EBP + -0x18) && (*(int *)(unaff_EBP + -0x18) < (int)uVar11))
                  )) {
            iVar7 = FUN_004752fc();
            sVar12 = *(short *)(iVar7 + *(int *)(unaff_EBP + -0x10) * 2);
            iVar7 = FUN_004752fc();
            uVar3 = *(undefined2 *)(iVar7 + *(int *)(unaff_EBP + -0x18) * 2);
LAB_0044ca63:
            *(undefined2 *)(unaff_EBP + 0x14) = uVar3;
          }
          *(byte *)(unaff_EBP + -0x20) = *(byte *)(iVar5 + 0x60e) & 1;
          iVar5 = FUN_00404ccb((int)sVar12);
          if ((iVar5 != 0) && (-1 < *(short *)(unaff_EBP + 0x14))) {
            piVar9 = (int *)FUN_005ed3c4();
            sVar12 = *(short *)(unaff_EBP + 0x14);
            if ((uint)(int)sVar12 < (uint)((piVar9[1] - *piVar9) / 0x3c0)) {
              piVar9 = (int *)FUN_005ed3c4();
              iVar5 = *(int *)(unaff_EBP + 0x10);
              if (iVar5 == 0) {
                puVar10 = (undefined4 *)FUN_004035e8(*(undefined4 *)(unaff_EBP + -0x20));
                uVar6 = *puVar10;
LAB_0044caf2:
                FUN_00455800(iVar4,*(undefined4 *)(unaff_EBP + -0x14),uVar6);
              }
              else if (iVar5 == 1) {
                FUN_00455790(iVar4,*(undefined4 *)(unaff_EBP + -0x14),
                             *piVar9 + sVar12 * 0x3c0 + 0x3b4);
              }
              else if (iVar5 == 2) {
                uVar6 = FUN_004033ea(*(undefined4 *)(unaff_EBP + -0x20));
                goto LAB_0044caf2;
              }
            }
          }
          iVar4 = iVar4 + 1;
          uVar6 = *(undefined4 *)(unaff_EBP + -0x2c + *(int *)(unaff_EBP + 0x10) * 4);
        }
        *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 1;
        if (2 < *(int *)(unaff_EBP + 0x10)) {
          ExceptionList = *(void **)(unaff_EBP + -0xc);
          return;
        }
      } while( true );
    }
    if (((*(int *)(unaff_EBP + 0xc) != 0) && (-1 < *(int *)(unaff_EBP + -0x10))) &&
       (*(int *)(unaff_EBP + -0x10) < (int)(uint)*(byte *)(*(int *)(unaff_EBP + 0xc) + 6))) {
      FUN_005b870f(&DAT_006de560);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar5 = FUN_004752fc();
      iVar5 = FUN_0042573e((int)*(short *)(iVar5 + *(int *)(unaff_EBP + -0x10) * 2));
      if (iVar5 != 0) {
        uVar6 = FUN_0045741b();
        iVar5 = FUN_004e988f(uVar6);
        if (iVar5 == -1) {
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          goto LAB_0044c69f;
        }
        FUN_004e9d82(iVar5,unaff_EBP + -0x2c);
        FUN_00455790(iVar4,*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x2c);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    iVar4 = iVar4 + 1;
  } while( true );
}

