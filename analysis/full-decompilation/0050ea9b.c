
undefined4 FUN_0050ea9b(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    FUN_005dbf32();
    FUN_005a5631(0xbc0,extraout_ECX + 0x46,4);
    FUN_005ddfdc(1);
    (**(code **)(*extraout_ECX + 0x60))(0,0,DAT_006f3688,DAT_006f368c);
    FUN_004cb21d(DAT_006f3690,DAT_006f3694);
    piVar2 = (int *)FUN_005e7743();
    iVar4 = *piVar2;
    uVar3 = FUN_005e50fa(3);
    piVar2 = (int *)(**(code **)(iVar4 + 0x24))(0,uVar3);
    extraout_ECX[0x43] = (int)piVar2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x90))(0x2000,1);
      iVar4 = extraout_ECX[0x43];
      FUN_004cb21d((((extraout_ECX[0x21] - *(int *)(iVar4 + 0x84)) - extraout_ECX[0x1f]) +
                   *(int *)(iVar4 + 0x7c)) / 2,
                   (((*(int *)(iVar4 + 0x80) - *(int *)(iVar4 + 0x88)) * 3) / 2 - extraout_ECX[0x20]
                   ) + extraout_ECX[0x22]);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x43]);
    }
    uVar3 = FUN_005d4956(s_<unknown>_006c8f34);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    piVar2 = (int *)FUN_005e7743();
    iVar4 = (**(code **)(*piVar2 + 0x28))(0,*(undefined4 *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x44] = iVar4;
    FUN_005b8770();
    if ((int *)extraout_ECX[0x44] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x44] + 0x60))(0,0,DAT_006f3668,DAT_006f366c);
      if (*(char *)(DAT_006e486c + 100) == '\x13') {
        (**(code **)(*(int *)extraout_ECX[0x44] + 0x60))(0,0,DAT_006f3668 + -10,DAT_006f366c);
      }
      FUN_004cb21d(DAT_006f3670,DAT_006f3674);
      (**(code **)(*(int *)extraout_ECX[0x44] + 0x90))(0x2000,1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x44]);
    }
    pvVar5 = operator_new(0x118);
    *(void **)(unaff_EBP + -0x18) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar5 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_005f4d1c();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x42] = iVar4;
    if (iVar4 != 0) {
      FUN_005f58c2(extraout_ECX[0x45]);
      *(undefined4 *)(extraout_ECX[0x42] + 0xe8) = 0xc;
      iVar4 = *(int *)extraout_ECX[0x45];
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)extraout_ECX[0x42];
      iVar4 = (**(code **)(iVar4 + 0x58))();
      (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x60))(0,0,DAT_006f3678,iVar4 * 0xc);
      FUN_004cb21d(DAT_006f3680,DAT_006f3684);
      if ((((int *)extraout_ECX[0x46] != (int *)0x0) &&
          (piVar2 = (int *)(**(code **)(*(int *)extraout_ECX[0x46] + 0x94))(), piVar2 != (int *)0x0)
          ) && (cVar1 = (**(code **)(*piVar2 + 0x20))(0x40), cVar1 != '\0')) {
        iVar4 = (**(code **)(*piVar2 + 0xcc))();
        uVar6 = (**(code **)(*piVar2 + 0xd0))();
        *(uint *)(extraout_ECX[0x42] + 100) =
             (uint)*(ushort *)(iVar4 + ((piVar2[8] / 2) * (uVar6 >> 1) + piVar2[7] / 2) * 2);
        (**(code **)*piVar2)(1);
      }
    }
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    uVar3 = FUN_0041532c(9,extraout_ECX + 0x47,0);
    cVar1 = FUN_004fff98(0xa6,uVar3);
    if (cVar1 != '\0') {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      iVar4 = FUN_0047168f();
      if (0 < iVar4) {
        do {
          uVar3 = FUN_004705f2(*(int *)(unaff_EBP + -0x10) + 1,0xffffffff);
          FUN_005d4956(uVar3);
          iVar4 = *(int *)extraout_ECX[0x45];
          *(undefined4 *)(unaff_EBP + -4) = 2;
          uVar3 = FUN_004096c2(*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x24));
          iVar4 = (**(code **)(iVar4 + 0x68))(uVar3);
          *(int *)(unaff_EBP + -0x18) = iVar4;
          piVar2 = (int *)(unaff_EBP + -0x18);
          if (iVar4 <= *(int *)(unaff_EBP + -0x14)) {
            piVar2 = (int *)(unaff_EBP + -0x14);
          }
          iVar4 = *piVar2;
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *(int *)(unaff_EBP + -0x14) = iVar4;
          FUN_005b8770();
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 2;
          iVar7 = FUN_0047168f();
        } while (*(int *)(unaff_EBP + -0x10) < iVar7);
        if (iVar4 != 0) {
          FUN_004ec186(iVar4 + 0x19);
        }
      }
      iVar7 = 0;
      iVar4 = FUN_0047168f();
      if (0 < iVar4) {
        do {
          uVar3 = FUN_004705f2(iVar7 + 1,0xffffffff);
          FUN_005d4956(uVar3);
          iVar4 = unaff_EBP + -0x30;
          *(undefined4 *)(unaff_EBP + -4) = 3;
          uVar3 = FUN_005f51ce(iVar4);
          FUN_005f51e0(uVar3,iVar4);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          iVar7 = iVar7 + 2;
          iVar4 = FUN_0047168f();
        } while (iVar7 < iVar4);
      }
    }
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x42]);
    iVar4 = FUN_0047168f();
    if (iVar4 != 0) {
      FUN_005f5543(0);
    }
    iVar4 = extraout_ECX[0x42];
    (**(code **)(*(int *)extraout_ECX[0x44] + 0x60))
              (*(int *)(iVar4 + 0x84) + 0x14,*(undefined4 *)(iVar4 + 0x80),
               *(int *)(iVar4 + 0x84) + 0x14 + DAT_006f3668,*(undefined4 *)(iVar4 + 0x88));
    FUN_004cb1a2(*(int *)(extraout_ECX[0x44] + 0x84) + 0x14,
                 *(int *)(extraout_ECX[0x42] + 0x88) +
                 (*(int *)(extraout_ECX[0x43] + 0x88) - *(int *)(extraout_ECX[0x43] + 0x80)) * 2);
    iVar4 = extraout_ECX[0x43];
    FUN_004cb21d((((extraout_ECX[0x21] - *(int *)(iVar4 + 0x84)) - extraout_ECX[0x1f]) +
                 *(int *)(iVar4 + 0x7c)) / 2,
                 (*(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80)) / 2 +
                 *(int *)(extraout_ECX[0x42] + 0x88));
    iVar4 = FUN_004b46a0();
    (**(code **)(*extraout_ECX + 100))(iVar4 + 0x7c);
    (**(code **)(*extraout_ECX + 0x90))(0x2000,1);
    uVar3 = 1;
  }
  else {
    uVar3 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

