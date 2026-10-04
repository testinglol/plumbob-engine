
undefined4 FUN_00488de7(void)

{
  undefined1 uVar1;
  ushort uVar2;
  short sVar3;
  int *piVar4;
  undefined1 uVar5;
  char cVar6;
  undefined2 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined1 uVar11;
  undefined4 extraout_ECX;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  int unaff_EBP;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int iStack_7c;
  undefined4 auStack_78 [5];
  undefined4 uStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int *piStack_54;
  undefined4 local_50;
  
  FUN_00634c24();
  uVar1 = *(undefined1 *)(unaff_EBP + 0xc);
  piVar4 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  iVar8 = *piVar4;
  uVar5 = (undefined1)(piVar4[1] >> 4);
  *(undefined1 *)(unaff_EBP + -0x10) = uVar5;
  uVar11 = (undefined1)(iVar8 >> 4);
  *(undefined1 *)(unaff_EBP + -0xf) = uVar11;
  *(undefined1 *)(unaff_EBP + -0xe) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + 0xc) = uVar5;
  *(undefined1 *)(unaff_EBP + 0xd) = uVar11;
  *(undefined1 *)(unaff_EBP + 0xe) = uVar1;
  iVar8 = DAT_006e54d8;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  local_50 = -*(int *)(iVar8 + 0x84) & 3;
  piStack_54 = (int *)0x488e3e;
  FUN_00434ffd();
  iVar8 = piVar4[1];
  *(int *)(unaff_EBP + -0x20) = *piVar4 >> 4;
  cVar6 = (char)(iVar8 >> 4);
  if ((((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)cVar6) &&
       ((int)cVar6 <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
      (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + -0x20))) &&
     ((int)*(char *)(unaff_EBP + -0x20) <= *(int *)(DAT_006e54d8 + 0x7c) + -1)) {
    *(char *)(unaff_EBP + 8) = cVar6;
    *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)(unaff_EBP + -0x20);
    *(undefined1 *)(unaff_EBP + 10) = uVar1;
    local_50 = unaff_EBP + 8;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    piStack_54 = (int *)0x488ea1;
    cVar6 = FUN_004892c1();
    iVar8 = local_50;
    cVar6 = '\x01' - (cVar6 != '\0');
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(char *)(unaff_EBP + 0xb) = cVar6;
    if (cVar6 == '\0') {
      *(undefined4 **)(unaff_EBP + 8) = &local_50;
      local_50._0_2_ =
           CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
      local_50._3_1_ = SUB41(iVar8,3);
      local_50._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_50);
      piStack_54 = (int *)0x488ed7;
      iVar8 = FUN_00488924();
      if (iVar8 != 0) {
        *(undefined4 **)(unaff_EBP + 8) = &local_50;
        local_50._0_2_ =
             CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
        local_50._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_50);
        local_50 = CONCAT13(extraout_var,(undefined3)local_50);
        piStack_54 = (int *)0x488f01;
        uVar9 = FUN_00486420();
        *(undefined4 *)(unaff_EBP + -0x20) = uVar9;
        *(undefined4 **)(unaff_EBP + 8) = &local_50;
        local_50._0_2_ =
             CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
        local_50._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_50);
        local_50 = CONCAT13(extraout_var_00,(undefined3)local_50);
        piStack_54 = (int *)(unaff_EBP + -0x4c);
        iStack_58 = 0x488f2a;
        FUN_00467768();
        *(undefined1 *)(unaff_EBP + -0x14) = 0;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (*(char *)(unaff_EBP + 0xe) == '\x01') {
          local_50 = 0x488f43;
          iVar8 = FUN_004790b4();
          *(bool *)(unaff_EBP + -0x14) =
               *(char *)(*(int *)(*(int *)(iVar8 + 0x10) + *(char *)(unaff_EBP + 0xc) * 4) +
                        (int)*(char *)(unaff_EBP + 0xd)) == '\x10';
        }
        if ((*(byte *)(unaff_EBP + -0x4c) & 0x30) == 0) {
          iVar8 = *(int *)(unaff_EBP + 0x10);
          iVar10 = *(int *)(unaff_EBP + -0x1c);
          if ((*(int *)(unaff_EBP + -0x20) == iVar8) &&
             ((*(int *)(iVar10 + 0x34) != 1 || (*(char *)(unaff_EBP + -0x14) == '\0'))))
          goto LAB_00489202;
          if (iVar8 == 0) {
            local_50 = *(undefined4 *)(unaff_EBP + -0x20);
            piStack_54 = (int *)0x489148;
            uVar9 = FUN_004a15df();
            *(undefined4 *)(unaff_EBP + 0x18) = uVar9;
            local_50 = 0x48915f;
            uVar9 = __ftol();
          }
          else {
            piStack_54 = (int *)0x48916d;
            local_50 = iVar8;
            uVar9 = FUN_004a15df();
          }
          piStack_54 = (int *)0x489177;
          local_50 = uVar9;
          cVar6 = FUN_00492b81();
          if (cVar6 == '\0') {
            *(undefined1 *)(iVar10 + 0x3e) = 1;
            goto LAB_00489211;
          }
          *(undefined1 *)(iVar10 + 0x3e) = 0;
          local_50 = unaff_EBP + -0x10;
          if (iVar8 == 0) {
            piStack_54 = (int *)0x489190;
            cVar6 = FUN_0048941c();
          }
          else {
            piStack_54 = (int *)0x489197;
            cVar6 = FUN_004892c1();
          }
          if (cVar6 == '\0') goto LAB_00489202;
          piStack_54 = *(int **)(unaff_EBP + -0x14);
          iStack_5c = unaff_EBP + -0x10;
          iStack_58 = *(undefined4 *)(unaff_EBP + -0x20);
          iStack_60 = 0x4891af;
          local_50 = uVar9;
          FUN_0048864d();
          iStack_58 = unaff_EBP + -0x10;
          *(int ***)(unaff_EBP + 0x18) = &piStack_54;
          iStack_5c = 0x4891bf;
          local_50 = iVar8;
          FUN_00461b74();
          iStack_58 = 0x4891ca;
          FUN_00487992();
          if (*(char *)(unaff_EBP + -0x14) != '\0') {
            local_50 = 0x4891db;
            iVar8 = FUN_004790b4();
            *(undefined1 *)
             (*(int *)(*(int *)(iVar8 + 0x10) + *(char *)(unaff_EBP + 0xc) * 4) +
             (int)*(char *)(unaff_EBP + 0xd)) = 0xff;
          }
          local_50 = unaff_EBP + -0x10;
          piStack_54 = (int *)0x4891f9;
          FUN_004a6a15();
          local_50 = uVar9;
LAB_004891fd:
          piStack_54 = (int *)0x489202;
          FUN_00492bb0();
        }
        else {
          local_50 = 0x488f6b;
          local_50 = FUN_00492b26();
          iStack_58 = 0x488f72;
          piStack_54 = piVar4;
          iVar8 = FUN_004894b9();
          if (((byte)*(undefined4 *)(unaff_EBP + -0x4c) & 0x10) == 0x10) {
            if ((iVar8 != 0) && (iVar8 != 1)) {
              *(undefined4 *)(unaff_EBP + 8) = 2;
              local_50 = 4;
              goto LAB_00488f96;
            }
            *(undefined4 *)(unaff_EBP + 8) = 4;
            local_50 = 2;
LAB_00488fa6:
            uVar2 = *(ushort *)(unaff_EBP + -0x44);
            iVar8 = local_50;
          }
          else {
            if ((iVar8 == 0) || (iVar8 == 2)) {
              local_50 = 1;
              *(undefined4 *)(unaff_EBP + 8) = 3;
              goto LAB_00488fa6;
            }
            local_50 = 3;
            *(undefined4 *)(unaff_EBP + 8) = 1;
LAB_00488f96:
            uVar2 = *(ushort *)(unaff_EBP + -0x38);
            iVar8 = local_50;
          }
          if ((uint)uVar2 != *(uint *)(unaff_EBP + 0x10)) {
            local_50 = *(undefined4 *)(unaff_EBP + 0x10);
            piStack_54 = (int *)0x488fc1;
            iVar10 = FUN_004a15df();
            *(int *)(unaff_EBP + -0x18) = iVar10;
            if (*(char *)(unaff_EBP + 0x18) == '\0') {
              *(int *)(unaff_EBP + -0x18) = iVar10 / 2;
            }
            local_50 = *(undefined4 *)(unaff_EBP + -0x18);
            piStack_54 = (int *)0x488fdf;
            cVar6 = FUN_00492b81();
            if (cVar6 == '\0') goto LAB_00489211;
            local_50 = *(undefined4 *)(unaff_EBP + -0x18);
            iVar10 = *(int *)(unaff_EBP + -0x20);
            iStack_58 = unaff_EBP + -0x4c;
            piStack_54 = *(int **)(unaff_EBP + -0x14);
            iStack_60 = unaff_EBP + -0x10;
            uStack_64 = 0x489001;
            iStack_5c = iVar10;
            FUN_00488574();
            if ((iVar8 == 2) || (iVar8 == 1)) {
              *(undefined2 *)(unaff_EBP + -0x44) = *(undefined2 *)(unaff_EBP + 0x10);
              uVar7 = (undefined2)*(undefined4 *)(unaff_EBP + 0x10);
            }
            else {
              uVar7 = (undefined2)*(undefined4 *)(unaff_EBP + 0x10);
              *(undefined2 *)(unaff_EBP + -0x38) = uVar7;
            }
            *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) | 0x10;
            if (*(char *)(unaff_EBP + 0x18) == '\0') {
              if (iVar10 != 0xff) {
                if ((*(int *)(unaff_EBP + 8) == 2) || (*(int *)(unaff_EBP + 8) == 1)) {
                  *(short *)(unaff_EBP + -0x44) = (short)iVar10;
                }
                else {
                  *(short *)(unaff_EBP + -0x38) = (short)iVar10;
                }
                goto LAB_00489086;
              }
            }
            else {
              if ((*(int *)(unaff_EBP + 8) == 2) || (*(int *)(unaff_EBP + 8) == 1)) {
                *(undefined2 *)(unaff_EBP + -0x44) = uVar7;
              }
              else {
                *(undefined2 *)(unaff_EBP + -0x38) = uVar7;
              }
LAB_00489086:
              *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) | 0x10;
            }
            *(undefined4 **)(unaff_EBP + 0x18) = auStack_78;
            puVar12 = (undefined4 *)(unaff_EBP + -0x4c);
            puVar13 = auStack_78;
            for (iStack_7c = 0xb; iStack_7c != 0; iStack_7c = iStack_7c + -1) {
              *puVar13 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar13 = puVar13 + 1;
            }
            *(int **)(unaff_EBP + -0x20) = &iStack_7c;
            *(undefined1 *)(unaff_EBP + -4) = 4;
            FUN_00461b74(unaff_EBP + -0x10);
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_00489224();
            if (*(int *)(unaff_EBP + 0x10) == 0) {
              if ((*(int *)(unaff_EBP + 8) == 2) ||
                 (sVar3 = *(short *)(unaff_EBP + -0x38), *(int *)(unaff_EBP + 8) == 1)) {
                sVar3 = *(short *)(unaff_EBP + -0x44);
              }
              if (sVar3 != 0) goto LAB_004890e3;
              *(int ***)(unaff_EBP + 0x18) = &piStack_54;
              local_50 = 0;
            }
            else {
LAB_004890e3:
              local_50 = 0xff;
              *(int ***)(unaff_EBP + 0x18) = &piStack_54;
            }
            iStack_58 = unaff_EBP + -0x10;
            iStack_5c = 0x4890f7;
            FUN_00461b74();
            iStack_58 = 0x489102;
            FUN_00487992();
            local_50 = unaff_EBP + -0x10;
            piStack_54 = (int *)0x48910b;
            FUN_004a6a15();
            local_50 = *(undefined4 *)(unaff_EBP + -0x18);
            goto LAB_004891fd;
          }
        }
LAB_00489202:
        DAT_006e5780 = 1;
        uVar9 = 1;
        goto LAB_00489213;
      }
    }
  }
LAB_00489211:
  uVar9 = 0;
LAB_00489213:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar9;
}

