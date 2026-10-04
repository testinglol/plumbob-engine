
void FUN_0048cd36(void)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined2 extraout_var;
  char *pcVar8;
  BOOL BVar9;
  undefined4 uVar10;
  int *extraout_ECX;
  byte bVar11;
  uint uVar12;
  int unaff_EBP;
  undefined4 uVar13;
  
  FUN_00634c24();
  *(undefined1 *)(extraout_ECX + 0x3f) = 0;
  FUN_0048c97e();
  (**(code **)(*extraout_ECX + 0x1c))();
  *(undefined2 *)(unaff_EBP + 0x10) = *(undefined2 *)((int)extraout_ECX + 0x2e);
LAB_0048cd78:
  FUN_00492b05();
  iVar5 = FUN_00445724();
  extraout_ECX[0x40] = iVar5;
  if (iVar5 == 0) goto LAB_0048d47f;
  if ((*(short *)(iVar5 + 0x600) == 0) || (0x11 < *(short *)(iVar5 + 0x600))) {
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
  }
  sVar1 = *(short *)(iVar5 + 0x60e);
  *(byte *)(unaff_EBP + -0xe) = (byte)((uint)(int)sVar1 >> 2) & 1;
  uVar12 = (uint)(int)sVar1 >> 1;
  bVar11 = (byte)uVar12 & 1;
  extraout_ECX[0x3e] = (int)*(short *)(unaff_EBP + 0x10);
  iVar6 = FUN_00492b10();
  extraout_ECX[0x3d] = iVar6;
  iVar5 = extraout_ECX[0x1a];
  if (iVar5 == 0x1f) {
    if (iVar6 != 0) {
      iVar5 = *(int *)(iVar6 + 0x11c);
      if (((*(char *)(unaff_EBP + -0xd) == '\0') && ((uVar12 & 1) == 0)) &&
         (*(byte *)(unaff_EBP + -0xe) == bVar11)) {
LAB_0048ce23:
        if ((iVar5 == 0) || (cVar3 = FUN_00457935(), cVar3 == '\0')) {
LAB_0048ce3d:
          if ((((uVar12 & 1) != 0) ||
              (((iVar5 == 0 || (cVar3 = FUN_004579a2(), cVar3 == '\0')) ||
               ((*(byte *)((int)DAT_006e486c + 0x66) & 0x20) == 0)))) &&
             ((((*(char *)(unaff_EBP + -0xe) != '\0' || (iVar5 == 0)) ||
               (cVar3 = FUN_00457a11(), cVar3 == '\0')) ||
              ((*(byte *)((int)DAT_006e486c + 0x66) & 0x20) == 0)))) {
            if (((uVar12 & 1) == 0) && (*(byte *)(unaff_EBP + -0xe) == bVar11)) {
              if (iVar5 != 0) {
                FUN_00457a80();
              }
            }
            else if (iVar5 != 0) {
              FUN_00457ae5();
            }
          }
        }
      }
      else if ((iVar5 == 0) || (cVar3 = FUN_004578c8(), cVar3 == '\0')) {
        if (*(char *)(unaff_EBP + -0xd) == '\0') goto LAB_0048ce23;
        goto LAB_0048ce3d;
      }
    }
LAB_0048cf61:
    FUN_00492d46();
  }
  else if ((((iVar5 != 0x1d) && (iVar5 != 0x2a)) || (iVar6 != extraout_ECX[0x40])) ||
          ((extraout_ECX[0xd] - extraout_ECX[0xc]) / 0x44 == 0)) goto LAB_0048cf61;
  uVar2 = *(ushort *)(*(int *)(unaff_EBP + 0x14) + 0x10);
  if (((uVar2 & 0x200) == 0) || ((uVar2 & 0x100) == 0)) {
    if ((extraout_ECX[0x40] == 0) && (extraout_ECX[0xf] != 1)) goto LAB_0048d47f;
    if (extraout_ECX[0xf] == 1) {
      iVar5 = FUN_006359f2(extraout_ECX[0x3d],0,&cXObject::RTTI_Type_Descriptor,
                           &cXPerson::RTTI_Type_Descriptor);
      extraout_ECX[0x40] = iVar5;
    }
    if (extraout_ECX[0xf] == 3) {
      extraout_ECX[0x3d] = extraout_ECX[0x40];
    }
    if ((extraout_ECX[0x40] == 0) || ((extraout_ECX[0x3d] == 0 && (extraout_ECX[0xf] != 0))))
    goto LAB_0048d47f;
    *(undefined1 *)((int)extraout_ECX + 0xfd) = 0;
    if (extraout_ECX[0x3d] == 0) {
      *(undefined1 *)((int)extraout_ECX + 0xfd) = 1;
      iVar5 = FUN_0043acf5();
      if (iVar5 != 0) {
        FUN_00492b05();
        uVar7 = FUN_00440b6d();
        *(undefined4 *)(unaff_EBP + 0x10) = uVar7;
        extraout_ECX[0x3e] = (int)(short)uVar7;
        iVar5 = FUN_00492b10();
        extraout_ECX[0x3d] = iVar5;
        if (iVar5 != 0) {
          uVar7 = FUN_00492b26();
          FUN_0047bd91(unaff_EBP + 0xc,unaff_EBP + 8,-*(int *)(DAT_006e54d8 + 0x84) & 3);
          FUN_00434876();
          *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + 8);
          *(undefined1 *)(unaff_EBP + -0x27) = 0;
          *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + 0xc);
          *(undefined1 *)(unaff_EBP + -0x3c) = 1;
          *(undefined4 *)(unaff_EBP + -0x30) = uVar7;
          *(undefined1 *)(unaff_EBP + -0x28) = 1;
          cVar3 = FUN_00434895(unaff_EBP + -0x3c);
          if (cVar3 == '\0') {
            *(uint *)(unaff_EBP + 0xc) = *(uint *)(unaff_EBP + 0xc) & 0xfffffff8 | 8;
            *(uint *)(unaff_EBP + 8) = *(uint *)(unaff_EBP + 8) & 0xfffffff8 | 8;
          }
          if (*(short *)(DAT_006e486c[7] + 0x24) == 99) {
            uVar4 = FUN_00492b26();
            *(char *)(unaff_EBP + -0x14) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
            *(char *)(unaff_EBP + -0x13) = (char)(*(int *)(unaff_EBP + 8) >> 4);
            *(undefined1 *)(unaff_EBP + -0x12) = uVar4;
            *(undefined4 *)(unaff_EBP + -4) = 1;
            *(undefined1 **)(unaff_EBP + -0x24) = &stack0xfffffe88;
            cVar3 = FUN_0048d490();
            if (cVar3 < '\n') goto LAB_0048d473;
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          }
          cVar3 = (**(code **)(*(int *)extraout_ECX[0x3d] + 0x54))(unaff_EBP + 8,uVar7,0);
          if (cVar3 == '\0') {
            FUN_00492b05();
            FUN_0044127f();
            *(undefined4 *)(unaff_EBP + 0x10) = 0;
          }
          else {
            *(undefined1 *)(extraout_ECX + 0x3f) = 1;
            (**(code **)(*(int *)extraout_ECX[0x3d] + 0x58))(unaff_EBP + 8,uVar7,0,0);
          }
        }
        FUN_0048c97e(*(undefined4 *)(unaff_EBP + 0x10),0xffffffff);
      }
    }
    extraout_ECX[0x41] = 0;
    if ((extraout_ECX[0xd] - extraout_ECX[0xc]) / 0x44 == 0) {
      FUN_00492c37();
      if ((char)extraout_ECX[0x3f] != '\0') {
        iVar5 = extraout_ECX[0x3d];
        goto joined_r0x0048d30d;
      }
      goto LAB_0048d47f;
    }
    if (extraout_ECX[0x40] == 0) goto LAB_0048d418;
    if ((extraout_ECX[0xf] != 2) && (extraout_ECX[0xf] != 3)) {
      iVar5 = *(int *)(unaff_EBP + 0x14);
      iVar6 = DAT_006e486c[7];
      *(undefined1 *)(unaff_EBP + -0xd) = DAT_006e5458;
      uVar4 = *(undefined1 *)(iVar6 + 0xd4);
      *(undefined1 *)(iVar6 + 0xd4) = 1;
      iVar6 = (int)*(short *)(iVar5 + 0xe);
      iVar5 = extraout_ECX[0x40];
      uVar7 = FUN_0048e01d(extraout_ECX[0x3d]);
      uVar12 = FUN_0048d6b6(uVar7,iVar5,iVar6);
      *(undefined1 *)(DAT_006e486c[7] + 0xd4) = uVar4;
      DAT_006e5458 = *(undefined1 *)(unaff_EBP + -0xd);
      if (uVar12 != 0xfffffffe) {
        if (((uVar12 != 0) && (0 < (int)uVar12)) &&
           (uVar12 <= (uint)((extraout_ECX[0xd] - extraout_ECX[0xc]) / 0x44))) {
          extraout_ECX[0x41] = uVar12 * 0x44 + -0x44 + extraout_ECX[0xc];
        }
        goto LAB_0048d418;
      }
      sVar1 = *(short *)((int)extraout_ECX + 0x2e);
      *(undefined2 *)((int)extraout_ECX + 0x2e) = 0xffff;
      FUN_0048c97e((int)sVar1,0xffffffff);
      *(undefined1 *)(extraout_ECX + 0x3f) = 0;
      FUN_0048c97e(0,0xffffffff);
      (**(code **)(*extraout_ECX + 0x1c))
                (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                 *(undefined4 *)(unaff_EBP + 0x10));
      *(uint *)(unaff_EBP + 0x10) = CONCAT22(extraout_var,*(undefined2 *)((int)extraout_ECX + 0x2e))
      ;
      goto LAB_0048cd78;
    }
    FUN_0042016f();
    *(undefined4 *)(unaff_EBP + -4) = 2;
    for (iVar5 = extraout_ECX[0xc]; iVar5 != extraout_ECX[0xd]; iVar5 = iVar5 + 0x44) {
      iVar6 = FUN_0048e01d();
      if (iVar6 != 0) {
        pcVar8 = (char *)FUN_004705f2((short)*(undefined4 *)(iVar5 + 0x10) + 1);
        if ((pcVar8 != (char *)0x0) && (*pcVar8 == '\0')) {
          pcVar8 = (char *)0x0;
        }
        FUN_004207e3(pcVar8);
      }
    }
    BVar9 = GetCursorPos((LPPOINT)(unaff_EBP + -0x1c));
    if (BVar9 == 0) {
      *(undefined2 *)(unaff_EBP + -0x12) = 0x140;
      *(undefined2 *)(unaff_EBP + -0x14) = 0xf0;
    }
    else {
      *(undefined2 *)(unaff_EBP + -0x12) = *(undefined2 *)(unaff_EBP + -0x1c);
      *(undefined2 *)(unaff_EBP + -0x14) = *(undefined2 *)(unaff_EBP + -0x18);
    }
    FUN_00420b7d(*(undefined4 *)(unaff_EBP + -0x14),1,unaff_EBP + -0x22);
    uVar12 = (uint)*(short *)(unaff_EBP + 0x16);
    if (((uVar12 != 0) && (0 < (int)uVar12)) &&
       (uVar12 <= (uint)((extraout_ECX[0xd] - extraout_ECX[0xc]) / 0x44))) {
      extraout_ECX[0x41] = uVar12 * 0x44 + -0x44 + extraout_ECX[0xc];
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0042071f();
LAB_0048d418:
    iVar5 = extraout_ECX[0x41];
    if (iVar5 == 0) {
      if ((char)extraout_ECX[0x3f] != '\0') {
        iVar5 = extraout_ECX[0x3d];
joined_r0x0048d30d:
        if (iVar5 == 0) goto LAB_0048d47f;
LAB_0048d473:
        FUN_00492b05();
        FUN_0044127f();
      }
    }
    else {
      iVar6 = extraout_ECX[0xf];
      if ((iVar6 == 2) || (iVar6 == 3)) {
        if (iVar6 == 3) {
          *(undefined4 *)(unaff_EBP + 0x10) = 0;
        }
        uVar7 = *(undefined4 *)(iVar5 + 0x10);
        uVar13 = *(undefined4 *)(unaff_EBP + 0x10);
        uVar10 = CONCAT22((short)((uint)*(int *)(iVar5 + 4) >> 0x10),
                          *(undefined2 *)(*(int *)(iVar5 + 4) + 0xf0));
        FUN_00492b05(uVar10,uVar13,uVar7);
        FUN_0044322d(uVar10,uVar13,uVar7);
      }
    }
  }
  else {
    *(undefined1 *)(unaff_EBP + 0x12) = 0;
    iVar5 = extraout_ECX[0x3d];
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar5 == 0) {
      uVar4 = FUN_00492b26();
      *(undefined1 *)(unaff_EBP + 0x12) = uVar4;
      *(char *)(unaff_EBP + 0x10) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
      *(char *)(unaff_EBP + 0x11) = (char)(*(int *)(unaff_EBP + 8) >> 4);
      FUN_00434ffd();
    }
    else {
      *(undefined1 *)(unaff_EBP + 0x10) = *(undefined1 *)(iVar5 + 0xfc);
      *(undefined1 *)(unaff_EBP + 0x11) = *(undefined1 *)(iVar5 + 0xfd);
      *(undefined1 *)(unaff_EBP + 0x12) = *(undefined1 *)(iVar5 + 0xfe);
    }
    FUN_0043f371(*DAT_006e486c,unaff_EBP + 0x10);
    while (*(int *)(unaff_EBP + -0x1c) != 0) {
      FUN_0040766a(0x8c);
      FUN_0043f3b9();
    }
  }
LAB_0048d47f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

