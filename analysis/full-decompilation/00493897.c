
undefined4 FUN_00493897(void)

{
  char *pcVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_ECX;
  undefined1 extraout_var;
  uint uVar6;
  int unaff_EBP;
  undefined4 local_3c;
  
  FUN_00634c24();
  if (*(undefined4 **)(unaff_EBP + 0x18) != (undefined4 *)0x0) {
    **(undefined4 **)(unaff_EBP + 0x18) = 0;
  }
  pcVar1 = *(char **)(unaff_EBP + 8);
  *(undefined1 *)(extraout_ECX + 0x40) = 0;
  cVar3 = *pcVar1;
  if ((((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)cVar3) &&
       ((int)cVar3 <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
      (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)pcVar1[1])) &&
     ((int)pcVar1[1] <= *(int *)(DAT_006e54d8 + 0x7c) + -1)) {
    *(undefined4 **)(unaff_EBP + 8) = &local_3c;
    local_3c._0_2_ = CONCAT11(pcVar1[1],cVar3);
    local_3c._3_1_ = (undefined1)((uint)extraout_ECX >> 0x18);
    local_3c._0_3_ = CONCAT12(pcVar1[2],(undefined2)local_3c);
    iVar4 = FUN_00488924();
    uVar6 = 0;
    if (iVar4 != 0) {
      cVar3 = *pcVar1;
      *(undefined4 **)(unaff_EBP + 8) = &local_3c;
      local_3c._0_2_ = CONCAT11(pcVar1[1],cVar3);
      local_3c._0_3_ = CONCAT12(pcVar1[2],(undefined2)local_3c);
      local_3c = CONCAT13(extraout_var,(undefined3)local_3c);
      FUN_00467768(unaff_EBP + -0x38);
      uVar2 = *(uint *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if ((uVar2 != 0) && ((*(uint *)(unaff_EBP + -0x38) & uVar2) == uVar2)) {
        if ((*(int *)(unaff_EBP + 0xc) != 1) && (*(int *)(unaff_EBP + 0xc) != 3)) {
          uVar6 = *(uint *)(extraout_ECX + 0x38);
        }
        local_3c = *(int *)(unaff_EBP + 0x14);
        if (uVar2 == 0x10) {
          if (local_3c == 0) {
            local_3c = 4;
          }
        }
        else if ((uVar2 == 0x20) && (local_3c == 0)) {
          local_3c = 1;
        }
        iVar4 = FUN_00435221(uVar2);
        if (*(ushort *)(unaff_EBP + -0x24 + iVar4 * 2) != uVar6) {
          local_3c = uVar2;
          iVar4 = FUN_00467ece();
          if ((((iVar4 != 2) && (iVar4 != 0xc)) && (iVar4 != 0xd)) && (iVar4 != 0xe)) {
            if (*(int *)(unaff_EBP + 0xc) != 1) {
              local_3c = uVar6;
              local_3c = FUN_004c6571();
              cVar3 = FUN_00492b81();
              if (cVar3 == '\0') {
                *(undefined1 *)(extraout_ECX + 0x40) = 1;
                goto LAB_004939c0;
              }
            }
            uVar5 = 1;
            goto LAB_004939c2;
          }
          if (*(undefined4 **)(unaff_EBP + 0x18) != (undefined4 *)0x0) {
            **(undefined4 **)(unaff_EBP + 0x18) = 0x2e;
          }
        }
      }
    }
  }
LAB_004939c0:
  uVar5 = 0;
LAB_004939c2:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

