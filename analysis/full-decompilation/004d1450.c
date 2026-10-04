
undefined1 FUN_004d1450(void)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int extraout_ECX;
  byte bVar9;
  int unaff_EBP;
  undefined4 uVar10;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  piVar2 = *(int **)(extraout_ECX + 0x174);
  bVar9 = (byte)uVar1 & 1;
  *(int *)(extraout_ECX + 0x170) = *(int *)(extraout_ECX + 0x170) + 1;
  *(byte *)(unaff_EBP + -0xe) = bVar9;
  *(byte *)(unaff_EBP + -0xf) = (byte)(uVar1 >> 2) & 1;
  if (piVar2 != (int *)0x0) {
    cVar4 = (**(code **)(*piVar2 + 0x28))
                      (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
    *(char *)(unaff_EBP + -0xd) = cVar4;
    if (cVar4 != '\0') {
      uVar5 = 1;
      goto LAB_004d161d;
    }
    bVar9 = *(byte *)(unaff_EBP + -0xe);
  }
  iVar6 = DAT_006e486c;
  uVar3 = *(uint *)(unaff_EBP + 8);
  if (0x28 < uVar3) {
    if (uVar3 == 0x70) {
      cVar4 = FUN_004cebca();
      if (cVar4 == '\0') {
        iVar6 = FUN_00401f6f();
        if (iVar6 != 2) {
          uVar10 = 2;
          goto LAB_004d18a1;
        }
        iVar6 = FUN_004cfe0d();
        FUN_004cfe14(iVar6 != 1,0);
      }
    }
    else if (uVar3 == 0x71) {
      cVar4 = FUN_004cebb8();
      if (cVar4 == '\0') {
        iVar6 = FUN_004cfe0d();
        if (iVar6 == 1) {
          FUN_004cfe14(0,0);
        }
        iVar6 = FUN_00401f6f();
        if (iVar6 == 1) {
          iVar6 = *(int *)(*(int *)(extraout_ECX + 0x11c) + 0xa0);
          if (iVar6 == 0) {
            uVar10 = 1;
          }
          else if (iVar6 == 1) {
            uVar10 = 0;
          }
          else if (iVar6 == 2) {
            uVar10 = 2;
          }
          else if (iVar6 == 3) {
            uVar10 = 3;
          }
          else if (iVar6 == 4) {
            uVar10 = 4;
          }
          else if (iVar6 == 5) {
            uVar10 = 5;
          }
          else {
            if (iVar6 != 6) goto LAB_004d1974;
            uVar10 = 6;
          }
          FUN_004cf54e(uVar10);
        }
        else {
          FUN_004cebf8(1,0);
        }
LAB_004d1974:
        FUN_004cffbb();
      }
    }
    else if (uVar3 == 0x72) {
      cVar4 = FUN_004cebb8();
      if (cVar4 == '\0') {
        iVar6 = FUN_004cfe0d();
        if (iVar6 == 1) {
          FUN_004cfe14(0,0);
        }
        uVar10 = 0;
        goto LAB_004d18a1;
      }
    }
    else if (uVar3 == 0x73) {
      cVar4 = FUN_004cebca();
      if ((cVar4 == '\0') && (*(char *)(unaff_EBP + -0xf) == '\0')) {
        iVar6 = FUN_004cfe0d();
        if (iVar6 == 1) {
          FUN_004cfe14(0,0);
        }
        uVar10 = 4;
        goto LAB_004d18a1;
      }
    }
    else if (uVar3 == 0x74) {
      iVar6 = FUN_004cfe0d();
      if (iVar6 == 1) {
        FUN_004cfe14(0,0);
      }
      uVar10 = 3;
LAB_004d18a1:
      FUN_004cebf8(uVar10,0);
    }
    else if (uVar3 == 0x77) {
      if ((*(int *)(extraout_ECX + 0x11a8) != 0) &&
         (*(char *)(*(int *)(extraout_ECX + 0x11a8) + 0x151) != '\0')) {
        *(undefined1 *)(unaff_EBP + -0xd) = 1;
        if (bVar9 == 0) {
          FUN_004c24d2();
          goto LAB_004d161a;
        }
        FUN_005d4956(&DAT_006de560);
        *(undefined4 *)(unaff_EBP + -4) = 1;
        FUN_005d499c(unaff_EBP + -0x1c);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
      }
    }
    else if (uVar3 == 0x79) {
      *(undefined1 *)(unaff_EBP + -0xd) = 1;
      FUN_004d2ffa();
      goto LAB_004d161a;
    }
    goto LAB_004d1a0d;
  }
  if (0x24 < uVar3) {
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
    if (*(int *)(iVar6 + 4) != 0) {
      if ((uVar1 >> 1 & 1) == 0) {
        if (bVar9 != 0) {
          if (uVar3 == 0x25) {
            FUN_004cef2b(1);
          }
          else if (uVar3 == 0x27) {
            FUN_004cef47(1);
          }
        }
      }
      else {
        cVar4 = FUN_004d3d05();
        if ((cVar4 != '\0') && (iVar6 = FUN_00401f6f(), iVar6 == 4)) {
          iVar7 = FUN_004cfddd();
          iVar8 = FUN_004cfde4();
          iVar6 = *(int *)(unaff_EBP + 8);
          if (iVar6 == 0x25) {
            iVar7 = iVar7 + -4;
          }
          else if (iVar6 == 0x26) {
            iVar8 = iVar8 + 4;
          }
          else if (iVar6 == 0x27) {
            iVar7 = iVar7 + 4;
          }
          else if (iVar6 == 0x28) {
            iVar8 = iVar8 + -4;
          }
          FUN_004cfcfd(iVar7,iVar8);
        }
      }
    }
    goto LAB_004d161a;
  }
  if (uVar3 == 9) {
    iVar6 = FUN_004cebac();
    uVar10 = 1;
    if (iVar6 == 1) {
      iVar6 = FUN_00401f6f();
      if (((iVar6 != 0) || (cVar4 = FUN_004cfc5c(), cVar4 == '\0')) &&
         (cVar4 = FUN_004cfc50(), cVar4 == '\0')) {
        FUN_0057a7f7(s_UI_error_006c5e80,0xfffffffc);
        goto LAB_004d1a0d;
      }
      uVar10 = 2;
    }
    FUN_004cefa3(uVar10,1);
LAB_004d1a0d:
    if (*(char *)(unaff_EBP + -0xd) == '\0') {
      if (DAT_006e54ac != (int *)0x0) {
        cVar4 = (**(code **)(*DAT_006e54ac + 0x48))
                          (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
        *(char *)(unaff_EBP + -0xd) = cVar4;
        if (cVar4 != '\0') goto LAB_004d161a;
      }
      uVar5 = FUN_005dd72f(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
      goto LAB_004d161d;
    }
  }
  else {
    if (uVar3 == 0xd) {
      iVar6 = FUN_00401f6f();
      if ((iVar6 == 2) && (iVar6 = FUN_004e99a9(), iVar6 != -1)) {
        uVar10 = FUN_004e9744(iVar6);
        FUN_0051c538(uVar10);
      }
      goto LAB_004d1a0d;
    }
    if (uVar3 == 0x1b) {
      FUN_00429f1a();
      if (*(int **)(DAT_006fe8f4 + 500) != (int *)0x0) {
        (**(code **)(**(int **)(DAT_006fe8f4 + 500) + 0x98))();
      }
      goto LAB_004d1a0d;
    }
    if (uVar3 == 0x21) {
      *(undefined1 *)(unaff_EBP + -0xd) = 1;
      iVar6 = FUN_004cebac();
      if ((iVar6 < 2) &&
         (((iVar6 = FUN_00401f6f(), iVar6 == 0 && (cVar4 = FUN_004cfc5c(), cVar4 != '\0')) ||
          (cVar4 = FUN_004cfc50(), cVar4 != '\0')))) {
        uVar10 = 2;
        goto LAB_004d1615;
      }
LAB_004d162e:
      FUN_0057a7f7(s_UI_error_006c5e80,0xfffffffc);
    }
    else {
      if (uVar3 != 0x22) {
        if (uVar3 == 0x23) {
          iVar6 = FUN_005ecb6f();
          if (iVar6 == 1) {
LAB_004d1543:
            uVar10 = 4;
          }
          else {
            iVar6 = FUN_005ecb6f();
            if (iVar6 != 4) {
              iVar6 = FUN_005ecb6f();
              if (iVar6 == 2) goto LAB_004d1576;
              goto LAB_004d158a;
            }
            uVar10 = 2;
          }
LAB_004d1544:
          FUN_004cf0ab(uVar10,1);
        }
        else {
          if (uVar3 != 0x24) goto LAB_004d1a0d;
          iVar6 = FUN_005ecb6f();
          if (iVar6 != 1) {
            iVar6 = FUN_005ecb6f();
            if (iVar6 == 4) {
              uVar10 = 1;
              goto LAB_004d1544;
            }
            iVar6 = FUN_005ecb6f();
            if (iVar6 != 2) goto LAB_004d158a;
            goto LAB_004d1543;
          }
LAB_004d1576:
          FUN_0057a7f7(s_UI_error_006c5e80,0xfffffffc);
        }
LAB_004d158a:
        *(undefined1 *)(*(int *)(DAT_006e486c + 4) + 0x4e) = 1;
        (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
        goto LAB_004d1a0d;
      }
      *(undefined1 *)(unaff_EBP + -0xd) = 1;
      iVar6 = FUN_004cebac();
      if (iVar6 < 2) goto LAB_004d162e;
      uVar10 = 1;
LAB_004d1615:
      FUN_004cefa3(uVar10,1);
    }
  }
LAB_004d161a:
  uVar5 = *(undefined1 *)(unaff_EBP + -0xd);
LAB_004d161d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

