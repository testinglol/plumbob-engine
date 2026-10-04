
void FUN_00497930(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar6;
  
  FUN_00634c24();
  iVar3 = FUN_00492b26();
  if (iVar3 < 2) {
    uVar4 = FUN_00433116(unaff_EBP + 8,1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00434d5c(uVar4);
    iVar3 = *(int *)(unaff_EBP + 0xc);
    *(undefined1 *)(extraout_ECX + 0xc) = 0;
    *(char *)(unaff_EBP + -0x18) = (char)(iVar3 >> 4);
    *(char *)(unaff_EBP + -0x17) = (char)(*(int *)(unaff_EBP + 8) >> 4);
    *(undefined1 *)(unaff_EBP + -0x16) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_00461b74(&DAT_006e482b);
    *(undefined1 *)(unaff_EBP + -0xe) = 0;
    FUN_0046185f(unaff_EBP + -0x1c,unaff_EBP + -0x10);
    iVar1 = DAT_006e54d8;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar3 = *(int *)(iVar1 + 0x70) + 1;
    if ((iVar3 <= *(char *)(unaff_EBP + -0x18)) &&
       (iVar6 = *(int *)(iVar1 + 0x74) + -1, *(int *)(unaff_EBP + -0x14) = iVar6,
       *(char *)(unaff_EBP + -0x18) <= iVar6)) {
      iVar6 = *(int *)(iVar1 + 0x78) + 1;
      *(int *)(unaff_EBP + -0x24) = iVar6;
      if ((iVar6 <= *(char *)(unaff_EBP + -0x17)) &&
         ((((iVar1 = *(int *)(iVar1 + 0x7c) + -1, *(char *)(unaff_EBP + -0x17) <= iVar1 &&
            (iVar3 <= *(char *)(unaff_EBP + -0x1c))) &&
           ((int)*(char *)(unaff_EBP + -0x1c) <= *(int *)(unaff_EBP + -0x14))) &&
          ((*(int *)(unaff_EBP + -0x24) <= (int)*(char *)(unaff_EBP + -0x1b) &&
           (*(char *)(unaff_EBP + -0x1b) <= iVar1)))))) {
        *(undefined1 *)(unaff_EBP + -0x22) = 0;
        *(undefined1 *)(unaff_EBP + -0x1f) = 0;
        FUN_00461b74(unaff_EBP + -0x18);
        FUN_00461b74(unaff_EBP + -0x1c);
        iVar3 = (int)extraout_ECX + 0x31;
        if (iVar3 != unaff_EBP + -0x24) {
          FUN_00461b74(unaff_EBP + -0x24);
          FUN_00461b74(unaff_EBP + -0x21);
        }
        FUN_0048f0d1(-*(int *)(DAT_006e54d8 + 0x84) & 3);
        if (extraout_ECX[0xb] == 0) {
          cVar2 = FUN_0049847a(iVar3);
          if (cVar2 == '\0') {
            extraout_ECX[0x12] = 0;
            FUN_004864ed(extraout_ECX[0xe],0xffffffff);
            FUN_00492c37();
            goto LAB_00497bcb;
          }
        }
        else {
          cVar2 = FUN_00498291(iVar3);
          if (cVar2 == '\0') {
            extraout_ECX[0x12] = 0;
            iVar3 = extraout_ECX[0xe];
            goto LAB_00497bc4;
          }
        }
        DAT_006e57e0 = *(undefined4 *)(unaff_EBP + 8);
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        DAT_006e57e4 = *(undefined4 *)(unaff_EBP + 0xc);
        if (extraout_ECX[0x15] == 0) {
LAB_00497b16:
          if (extraout_ECX[0x10] != 0) {
            iVar3 = FUN_004777b8();
            *(int *)(unaff_EBP + -0x14) = iVar3;
            if (iVar3 != 0) {
              FUN_00461765();
            }
          }
        }
        else {
          iVar3 = FUN_00401f73();
          if ((iVar3 == 1) &&
             (iVar3 = *(int *)(extraout_ECX[0x15] + 0x28), *(int *)(unaff_EBP + -0x14) = iVar3,
             iVar3 != 0)) {
            FUN_00461765();
          }
          if (extraout_ECX[0x15] != 0) {
            FUN_00485b4c();
            extraout_ECX[0x15] = 0;
          }
          if (*(int *)(unaff_EBP + -0x14) == 0) goto LAB_00497b16;
        }
        puVar5 = operator_new(0x34);
        *(undefined4 **)(unaff_EBP + -0x24) = puVar5;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          FUN_00492f28();
          puVar5[9] = 0;
          puVar5[10] = 0;
          puVar5[0xb] = 0;
          puVar5[0xc] = extraout_ECX;
          *puVar5 = &PTR_FUN_006682a8;
        }
        *(undefined1 *)(unaff_EBP + -4) = 2;
        extraout_ECX[0x15] = (int)puVar5;
        if (puVar5 != (undefined4 *)0x0) {
          puVar5[2] = puVar5[2] + 1;
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
        goto LAB_00497bcb;
      }
    }
    extraout_ECX[0xe] = 1;
    iVar3 = 1;
  }
  else {
    extraout_ECX[0xe] = 0x1f;
    iVar3 = 0x1f;
  }
LAB_00497bc4:
  FUN_004864ed(iVar3,0xffffffff);
LAB_00497bcb:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

