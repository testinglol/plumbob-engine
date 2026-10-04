
void FUN_0048f168(void)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  iVar4 = FUN_00492b26();
  if (iVar4 < 2) {
    uVar5 = FUN_00433116(unaff_EBP + 8,1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00434d5c(uVar5);
    iVar4 = *(int *)(unaff_EBP + 0xc);
    *(undefined1 *)((int)extraout_ECX + 0x59) = 0;
    *(char *)(unaff_EBP + -0x18) = (char)(iVar4 >> 4);
    *(char *)(unaff_EBP + -0x17) = (char)(*(int *)(unaff_EBP + 8) >> 4);
    *(undefined1 *)(unaff_EBP + -0x16) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_00461b74(&DAT_006e482b);
    *(undefined1 *)(unaff_EBP + -0xe) = 0;
    FUN_0046185f(unaff_EBP + -0x1c,unaff_EBP + -0x10);
    iVar1 = DAT_006e54d8;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar4 = *(int *)(iVar1 + 0x70) + 1;
    if ((iVar4 <= *(char *)(unaff_EBP + -0x18)) &&
       (iVar7 = *(int *)(iVar1 + 0x74) + -1, *(int *)(unaff_EBP + -0x14) = iVar7,
       *(char *)(unaff_EBP + -0x18) <= iVar7)) {
      iVar7 = *(int *)(iVar1 + 0x78) + 1;
      *(int *)(unaff_EBP + -0x24) = iVar7;
      if ((iVar7 <= *(char *)(unaff_EBP + -0x17)) &&
         ((((iVar1 = *(int *)(iVar1 + 0x7c) + -1, *(char *)(unaff_EBP + -0x17) <= iVar1 &&
            (iVar4 <= *(char *)(unaff_EBP + -0x1c))) &&
           ((int)*(char *)(unaff_EBP + -0x1c) <= *(int *)(unaff_EBP + -0x14))) &&
          ((*(int *)(unaff_EBP + -0x24) <= (int)*(char *)(unaff_EBP + -0x1b) &&
           (*(char *)(unaff_EBP + -0x1b) <= iVar1)))))) {
        *(undefined1 *)(unaff_EBP + -0x22) = 0;
        *(undefined1 *)(unaff_EBP + -0x1f) = 0;
        FUN_00461b74(unaff_EBP + -0x18);
        FUN_00461b74(unaff_EBP + -0x1c);
        piVar2 = extraout_ECX + 0x10;
        if (piVar2 != (int *)(unaff_EBP + -0x24)) {
          FUN_00461b74(unaff_EBP + -0x24);
          FUN_00461b74(unaff_EBP + -0x21);
        }
        FUN_0048f0d1(-*(int *)(DAT_006e54d8 + 0x84) & 3);
        if (extraout_ECX[0xb] == 0) {
          cVar3 = FUN_0048fc3a(piVar2);
          if (cVar3 == '\0') {
            extraout_ECX[0x12] = 0;
            FUN_004864ed(extraout_ECX[0x15],0xffffffff);
            FUN_00492c37();
            goto LAB_0048f403;
          }
        }
        else {
          cVar3 = FUN_0049004a(piVar2);
          if (cVar3 == '\0') {
            extraout_ECX[0x12] = 0;
            iVar4 = extraout_ECX[0x15];
            goto LAB_0048f3fc;
          }
        }
        DAT_006e57e0 = *(undefined4 *)(unaff_EBP + 8);
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        DAT_006e57e4 = *(undefined4 *)(unaff_EBP + 0xc);
        if (extraout_ECX[0xd] == 0) {
LAB_0048f34e:
          if (extraout_ECX[0xf] != 0) {
            iVar4 = FUN_00461d22();
            *(int *)(unaff_EBP + -0x14) = iVar4;
            if (iVar4 != 0) {
              FUN_00461765();
            }
          }
        }
        else {
          iVar4 = FUN_00401f73();
          if ((iVar4 == 1) &&
             (iVar4 = *(int *)(extraout_ECX[0xd] + 0x28), *(int *)(unaff_EBP + -0x14) = iVar4,
             iVar4 != 0)) {
            FUN_00461765();
          }
          if (extraout_ECX[0xd] != 0) {
            FUN_00485b4c();
            extraout_ECX[0xd] = 0;
          }
          if (*(int *)(unaff_EBP + -0x14) == 0) goto LAB_0048f34e;
        }
        puVar6 = operator_new(0x34);
        *(undefined4 **)(unaff_EBP + -0x24) = puVar6;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (puVar6 == (undefined4 *)0x0) {
          puVar6 = (undefined4 *)0x0;
        }
        else {
          FUN_00492f28();
          puVar6[9] = 0;
          puVar6[10] = 0;
          puVar6[0xb] = 0;
          puVar6[0xc] = extraout_ECX;
          *puVar6 = &PTR_FUN_00668020;
        }
        *(undefined1 *)(unaff_EBP + -4) = 2;
        extraout_ECX[0xd] = (int)puVar6;
        if (puVar6 != (undefined4 *)0x0) {
          puVar6[2] = puVar6[2] + 1;
          FUN_0048f414(*(undefined4 *)(unaff_EBP + -0x14));
        }
        if (*(int *)(unaff_EBP + -0x14) != 0) {
          FUN_0046176c();
        }
        (**(code **)(*extraout_ECX + 0x28))
                  (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                   *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14));
        if ((extraout_ECX[0x12] != 0) && (extraout_ECX[0xb] != 1)) {
          FUN_0057a7f7(s_UI_bld_dragtool_mousedown_006c5f1c,0xfffffffc);
        }
        goto LAB_0048f403;
      }
    }
    extraout_ECX[0x15] = 1;
    iVar4 = 1;
  }
  else {
    extraout_ECX[0x15] = 0x1f;
    iVar4 = 0x1f;
  }
LAB_0048f3fc:
  FUN_004864ed(iVar4,0xffffffff);
LAB_0048f403:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

