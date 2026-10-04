
undefined4 FUN_00491801(void)

{
  undefined1 uVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_ECX;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 uVar6;
  undefined1 extraout_var_01;
  int unaff_EBP;
  char *pcVar7;
  undefined4 local_20;
  
  FUN_00634c24();
  if ((DAT_006e57b0 & 1) == 0) {
    DAT_006e57b0 = DAT_006e57b0 | 1;
    local_20 = &DAT_006e4822;
    FUN_00461b74();
    local_20 = &DAT_006e481c;
    DAT_006e57a6 = 0;
    FUN_00461b74();
    local_20 = &DAT_006e4825;
    DAT_006e57a9 = 0;
    FUN_00461b74();
    local_20 = &LAB_00491b17;
    DAT_006e57ac = 0;
    DAT_006e57ad = 0;
    DAT_006e57ae = 0;
    DAT_006e57af = 0;
    FUN_00635543();
  }
  uVar6 = **(undefined1 **)(unaff_EBP + 8);
  uVar1 = (*(undefined1 **)(unaff_EBP + 8))[1];
  *(undefined1 *)(unaff_EBP + -0x10) = uVar6;
  *(undefined1 *)(unaff_EBP + -0xf) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + -0x18) = uVar6;
  *(undefined1 *)(unaff_EBP + -0x17) = uVar1;
  *(undefined1 *)(unaff_EBP + -0xe) = 1;
  *(undefined1 *)(unaff_EBP + -0x16) = 2;
  pcVar7 = &DAT_006e57a4;
  while( true ) {
    *(undefined1 *)(unaff_EBP + 8) = *(undefined1 *)(unaff_EBP + -0x10);
    *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)(unaff_EBP + -0xf);
    *(undefined1 *)(unaff_EBP + 10) = *(undefined1 *)(unaff_EBP + -0xe);
    *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(unaff_EBP + -0x17);
    *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0x16);
    iVar4 = DAT_006e54d8;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    local_20 = (undefined1 *)(-*(int *)(iVar4 + 0x84) & 3);
    FUN_00434ffd();
    local_20 = (undefined1 *)(-*(int *)(DAT_006e54d8 + 0x84) & 3);
    FUN_00434ffd();
    if ((((('\0' < *(char *)(unaff_EBP + 8)) &&
          (iVar4 = *(int *)(DAT_006e54dc + 0x10) + -1, *(char *)(unaff_EBP + 8) < iVar4)) &&
         ('\0' < *(char *)(unaff_EBP + 9))) &&
        ((*(char *)(unaff_EBP + 9) < iVar4 && ('\0' < *(char *)(unaff_EBP + -0x14))))) &&
       ((*(char *)(unaff_EBP + -0x14) < iVar4 &&
        (('\0' < *(char *)(unaff_EBP + -0x13) && (*(char *)(unaff_EBP + -0x13) < iVar4)))))) break;
LAB_00491ac3:
    cVar3 = *pcVar7;
    cVar2 = pcVar7[1];
    *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + cVar3;
    *(char *)(unaff_EBP + -0xf) = *(char *)(unaff_EBP + -0xf) + cVar2;
    *(char *)(unaff_EBP + -0x18) = *(char *)(unaff_EBP + -0x18) + cVar3;
    *(char *)(unaff_EBP + -0x17) = *(char *)(unaff_EBP + -0x17) + cVar2;
    pcVar7 = pcVar7 + 3;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (0x6e57af < (int)pcVar7) {
      uVar5 = 1;
LAB_00491ae9:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar5;
    }
  }
  local_20 = (undefined1 *)(unaff_EBP + 8);
  iVar4 = FUN_00433166();
  if (iVar4 == 0) {
    local_20 = (undefined1 *)(unaff_EBP + -0x14);
    iVar4 = FUN_00433166();
    if (iVar4 == 0) {
      local_20 = (undefined1 *)(unaff_EBP + 8);
      cVar3 = FUN_00490021();
      if (cVar3 == '\0') {
        local_20 = (undefined1 *)(unaff_EBP + -0x14);
        cVar3 = FUN_00490021();
        if (cVar3 == '\0') {
          local_20 = (undefined1 *)(unaff_EBP + 8);
          cVar3 = FUN_004790bc();
          if (((((cVar3 == '\0') &&
                (iVar4 = *(int *)(DAT_006e54dc + 0x10), (int)*(char *)(unaff_EBP + 8) <= iVar4 + -2)
                ) && ((int)*(char *)(unaff_EBP + 9) <= iVar4 + -2)) &&
              ((('\x01' < *(char *)(unaff_EBP + 8) && ('\x01' < *(char *)(unaff_EBP + 9))) &&
               (((int)*(char *)(unaff_EBP + -0x14) <= iVar4 + -2 &&
                (((int)*(char *)(unaff_EBP + -0x13) <= iVar4 + -2 &&
                 ('\x01' < *(char *)(unaff_EBP + -0x14))))))))) &&
             ('\x01' < *(char *)(unaff_EBP + -0x13))) {
            local_20 = (undefined1 *)(unaff_EBP + 8);
            cVar3 = FUN_00479115();
            if (cVar3 == '\0') {
              uVar6 = extraout_var;
              if (*(char *)(unaff_EBP + 0xc) == '\0') {
LAB_00491a77:
                *(undefined4 **)(unaff_EBP + -0x1c) = &local_20;
                local_20._0_2_ =
                     CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
                local_20._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_20);
                local_20 = (undefined1 *)CONCAT13(uVar6,(undefined3)local_20);
                iVar4 = FUN_00488924();
                if (iVar4 != 0) {
                  *(undefined4 **)(unaff_EBP + -0x1c) = &local_20;
                  local_20._0_2_ =
                       CONCAT11(*(undefined1 *)(unaff_EBP + -0x17),
                                *(undefined1 *)(unaff_EBP + -0x18));
                  local_20._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0x16),(undefined2)local_20)
                  ;
                  local_20 = (undefined1 *)CONCAT13(extraout_var_01,(undefined3)local_20);
                  iVar4 = FUN_00488924();
                  if (iVar4 != 0) goto LAB_00491ac3;
                }
              }
              else {
                local_20 = (undefined1 *)(unaff_EBP + -0x10);
                cVar3 = FUN_0049177e();
                if (cVar3 == '\0') {
                  local_20 = (undefined1 *)(unaff_EBP + -0x18);
                  cVar3 = FUN_0049177e();
                  uVar6 = extraout_var_00;
                  if (cVar3 == '\0') goto LAB_00491a77;
                }
              }
            }
          }
        }
      }
    }
  }
  uVar6 = *(undefined1 *)(unaff_EBP + -0x10);
  *(undefined4 *)(extraout_ECX + 0x38) = 1;
  *(undefined1 *)(extraout_ECX + 0x34) = uVar6;
  *(undefined1 *)(extraout_ECX + 0x35) = *(undefined1 *)(unaff_EBP + -0xf);
  *(undefined1 *)(extraout_ECX + 0x36) = *(undefined1 *)(unaff_EBP + -0xe);
  uVar5 = 0;
  goto LAB_00491ae9;
}

