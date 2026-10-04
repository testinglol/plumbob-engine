
void FUN_0048b08b(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int extraout_ECX;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  char cVar7;
  int unaff_EBP;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 local_38;
  
  FUN_00634c24();
  local_38 = unaff_EBP + 8;
  cVar2 = FUN_00484ba0();
  if (cVar2 == '\0') {
    local_38 = 0x48b0b9;
    uVar3 = FUN_00492b26();
    *(undefined4 **)(unaff_EBP + -0x20) = &local_38;
    local_38._0_2_ =
         CONCAT11((char)(*(int *)(unaff_EBP + 8) >> 4),(char)(*(int *)(unaff_EBP + 0xc) >> 4));
    local_38._0_3_ = CONCAT12(uVar3,(undefined2)local_38);
    local_38 = CONCAT13(extraout_var,(undefined3)local_38);
    iVar4 = FUN_00488924();
    if (iVar4 == 0) goto LAB_0048b32c;
    DAT_006e57e0 = *(undefined4 *)(unaff_EBP + 8);
    uVar5 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined1 *)(extraout_ECX + 0x70) = 0;
    puVar8 = *(undefined4 **)(unaff_EBP + 0x14);
    DAT_006e57e4 = uVar5;
    *(undefined4 *)(extraout_ECX + 0x38) = DAT_006e57e0;
    *(undefined4 *)(extraout_ECX + 0x3c) = uVar5;
    local_38 = unaff_EBP + 8;
    puVar10 = (undefined4 *)(extraout_ECX + 0x40);
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    FUN_0048b857();
    local_38 = 0x48b11c;
    uVar3 = FUN_00492b26();
    *(undefined1 *)(unaff_EBP + -0x12) = uVar3;
    *(char *)(unaff_EBP + -0x14) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
    *(char *)(unaff_EBP + -0x13) = (char)(*(int *)(unaff_EBP + 8) >> 4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    local_38 = 0x48b13d;
    uVar5 = FUN_0048b777();
    *(undefined4 *)(extraout_ECX + 0x6c) = uVar5;
    if (*(int *)(extraout_ECX + 0x5c) == 0) {
LAB_0048b296:
      local_38 = *(undefined4 *)(extraout_ECX + 0x6c);
      FUN_0048b9f3();
      *(undefined1 *)(extraout_ECX + 0x30) = *(undefined1 *)(unaff_EBP + -0x14);
      *(undefined1 *)(extraout_ECX + 0x31) = *(undefined1 *)(unaff_EBP + -0x13);
      *(undefined1 *)(extraout_ECX + 0x32) = *(undefined1 *)(unaff_EBP + -0x12);
      local_38 = unaff_EBP + -0x14;
      FUN_0048b8b2();
      iVar4 = *(int *)(extraout_ECX + 0x6c);
      uVar5 = *(undefined4 *)(*(int *)(unaff_EBP + 0x14) + 0xc);
      *(undefined4 *)(unaff_EBP + 0x14) = uVar5;
      *(int *)(extraout_ECX + 0x54) = (int)*(short *)(unaff_EBP + 0x16);
      *(int *)(extraout_ECX + 0x58) = (int)(short)uVar5;
      if (iVar4 != 1) {
        local_38 = 0xfffffffc;
        FUN_0057a7f7(s_UI_bld_dragtool_mousedown_006c5f1c);
      }
      goto LAB_0048b349;
    }
    local_38 = 0;
    cVar2 = FUN_00496e92(unaff_EBP + -0x14);
    if (cVar2 != '\0') {
      if (('\x01' < *(char *)(unaff_EBP + -0x12)) && (*(int *)(extraout_ECX + 0x6c) != 1)) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
        *(undefined4 *)(unaff_EBP + -0x34) = 8;
        *(undefined4 *)(unaff_EBP + -0x2c) = 4;
        *(undefined4 *)(unaff_EBP + -0x28) = 2;
        piVar9 = (int *)(unaff_EBP + -0x34);
        do {
          iVar4 = *piVar9;
          *(undefined1 *)(unaff_EBP + -0x10) = (&DAT_006e481c)[iVar4 * 3];
          uVar3 = (&DAT_006e481d)[iVar4 * 3];
          *(undefined1 *)(unaff_EBP + -0xe) = 0;
          *(undefined1 *)(unaff_EBP + -0xf) = uVar3;
          local_38 = unaff_EBP + -0x10;
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0046185f(unaff_EBP + -0x18);
          iVar1 = DAT_006e54d8;
          cVar2 = (char)*(undefined4 *)(unaff_EBP + -0x18);
          iVar4 = *(int *)(DAT_006e54d8 + 0x70);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          if (((((int)cVar2 < iVar4 + 1) || (*(int *)(iVar1 + 0x74) + -1 < (int)cVar2)) ||
              (cVar7 = (char)((uint)*(undefined4 *)(unaff_EBP + -0x18) >> 8),
              (int)cVar7 < *(int *)(iVar1 + 0x78) + 1)) ||
             (*(int *)(iVar1 + 0x7c) + -1 < (int)cVar7)) {
LAB_0048b241:
            *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
          }
          else {
            *(undefined4 **)(unaff_EBP + -0x24) = &local_38;
            local_38._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + -0x17),cVar2);
            local_38._3_1_ = cVar7 >> 7;
            local_38._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0x16),(undefined2)local_38);
            iVar4 = FUN_00488924();
            if (iVar4 == 0) goto LAB_0048b241;
            *(undefined4 **)(unaff_EBP + -0x24) = &local_38;
            local_38._0_2_ =
                 CONCAT11(*(undefined1 *)(unaff_EBP + -0x17),*(undefined1 *)(unaff_EBP + -0x18));
            local_38._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0x16),(undefined2)local_38);
            local_38 = CONCAT13(extraout_var_00,(undefined3)local_38);
            uVar6 = FUN_004893e4();
            if ((uVar6 & 1) == 0) goto LAB_0048b241;
          }
          if (*(int *)(unaff_EBP + -0x1c) == 4) goto LAB_0048b325;
          *(undefined1 *)(unaff_EBP + -4) = 0;
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
          piVar9 = piVar9 + 1;
        } while (*(int *)(unaff_EBP + -0x20) < 4);
      }
      local_38 = unaff_EBP + -0x14;
      FUN_00496868();
      iVar4 = *(int *)(extraout_ECX + 0x60);
      if (iVar4 == 1) {
        iVar4 = 0xff;
        local_38 = 0xff;
      }
      else {
        local_38 = *(undefined4 *)(extraout_ECX + 100);
      }
      FUN_00496851(iVar4);
      *(undefined4 *)(*(int *)(extraout_ECX + 0x5c) + 0xe040) = *(undefined4 *)(extraout_ECX + 0x6c)
      ;
      goto LAB_0048b296;
    }
    local_38 = 0x48b2f4;
    iVar4 = FUN_00492b26();
    if ((iVar4 < 2) || (*(int *)(extraout_ECX + 0x6c) == 1)) goto LAB_0048b349;
    *(undefined4 **)(unaff_EBP + 0x14) = &local_38;
    local_38._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + -0x13),*(undefined1 *)(unaff_EBP + -0x14))
    ;
    local_38._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0x12),(undefined2)local_38);
    local_38 = CONCAT13(extraout_var_01,(undefined3)local_38);
    uVar6 = FUN_004893e4();
    if ((uVar6 & 1) != 0) goto LAB_0048b349;
LAB_0048b325:
    iVar4 = *(int *)(extraout_ECX + 0x5c);
    local_38 = 0x20;
  }
  else {
LAB_0048b32c:
    iVar4 = *(int *)(extraout_ECX + 0x5c);
    local_38 = 1;
  }
  uVar5 = local_38;
  local_38 = 0xffffffff;
  *(undefined4 *)(iVar4 + 0xe064) = uVar5;
  FUN_004864ed(uVar5);
  local_38 = 0x48b349;
  FUN_00492c37();
LAB_0048b349:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

