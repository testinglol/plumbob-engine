
undefined4 FUN_00496e92(void)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int extraout_ECX;
  undefined1 extraout_var;
  int unaff_EBP;
  int iVar8;
  undefined4 local_20;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar8 = extraout_ECX;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    pcVar2 = *(char **)(unaff_EBP + 8);
    cVar3 = *pcVar2;
    if (((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)cVar3) &&
        ((int)cVar3 <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
       ((*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)pcVar2[1] &&
        ((int)pcVar2[1] <= *(int *)(DAT_006e54d8 + 0x7c) + -1)))) {
      *(undefined4 **)(unaff_EBP + 8) = &local_20;
      local_20._0_2_ = CONCAT11(pcVar2[1],cVar3);
      local_20._3_1_ = (char)((uint)pcVar2 >> 0x18);
      local_20._0_3_ = CONCAT12(pcVar2[2],(undefined2)local_20);
      iVar4 = FUN_00488924();
      if (iVar4 != 0) {
LAB_00496f15:
        uVar5 = 1;
        goto LAB_0049712f;
      }
    }
LAB_00497118:
    iVar4 = *(int *)(iVar8 + 0xe064);
    piVar7 = (int *)(iVar8 + 0xe064);
  }
  else {
    pcVar2 = *(char **)(unaff_EBP + 8);
    *(char *)(unaff_EBP + 8) = *pcVar2;
    *(char *)(unaff_EBP + 9) = pcVar2[1];
    *(char *)(unaff_EBP + 10) = pcVar2[2];
    *(undefined4 *)(unaff_EBP + -4) = 0;
    local_20 = unaff_EBP + 8;
    FUN_0053c0e0(*(undefined4 *)(unaff_EBP + 0xc));
    iVar6 = DAT_006e54d8;
    cVar3 = *pcVar2;
    iVar4 = *(int *)(DAT_006e54d8 + 0x70) + 1;
    if (cVar3 < iVar4) goto LAB_00497118;
    iVar8 = *(int *)(DAT_006e54d8 + 0x74) + -1;
    *(int *)(unaff_EBP + 0xc) = iVar8;
    if (iVar8 < cVar3) {
LAB_00497115:
      iVar8 = *(int *)(unaff_EBP + -0x10);
      goto LAB_00497118;
    }
    iVar8 = *(int *)(iVar6 + 0x78) + 1;
    if ((((pcVar2[1] < iVar8) || (iVar6 = *(int *)(iVar6 + 0x7c) + -1, iVar6 < pcVar2[1])) ||
        (*(char *)(unaff_EBP + 8) < iVar4)) ||
       (*(int *)(unaff_EBP + 0xc) < (int)*(char *)(unaff_EBP + 8))) goto LAB_00497115;
    cVar1 = *(char *)(unaff_EBP + 9);
    if ((cVar1 < iVar8) || (iVar6 < cVar1)) goto LAB_00497115;
    *(undefined4 **)(unaff_EBP + 0xc) = &local_20;
    local_20._0_2_ = CONCAT11(pcVar2[1],cVar3);
    local_20._3_1_ = (char)cVar1 >> 7;
    local_20._0_3_ = CONCAT12(pcVar2[2],(undefined2)local_20);
    iVar8 = FUN_00488924();
    if (iVar8 != 0) {
      *(undefined4 **)(unaff_EBP + 0xc) = &local_20;
      local_20._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 9),*(undefined1 *)(unaff_EBP + 8));
      local_20._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 10),(undefined2)local_20);
      local_20 = CONCAT13(extraout_var,(undefined3)local_20);
      iVar8 = FUN_00488924();
      if (iVar8 != 0) {
        iVar8 = 0;
        do {
          *(undefined1 *)(unaff_EBP + -4) = 1;
          if (iVar8 == 0) {
            *(char *)(unaff_EBP + 0xc) = *pcVar2;
            *(char *)(unaff_EBP + 0xd) = pcVar2[1];
            cVar3 = pcVar2[2];
          }
          else {
            *(undefined1 *)(unaff_EBP + 0xc) = *(undefined1 *)(unaff_EBP + 8);
            *(undefined1 *)(unaff_EBP + 0xd) = *(undefined1 *)(unaff_EBP + 9);
            cVar3 = *(char *)(unaff_EBP + 10);
          }
          *(char *)(unaff_EBP + 0xe) = cVar3;
          local_20 = -*(int *)(DAT_006e54d8 + 0x84) & 3;
          FUN_00434ffd();
          local_20 = 0;
          FUN_0043f371(*DAT_006e486c,unaff_EBP + 0xc);
          while (iVar4 = *(int *)(unaff_EBP + -0x18), iVar4 != 0) {
            if (*(short *)(iVar4 + 0x8e) == 0) {
              if ((*(short *)(*(int *)(iVar4 + 0x118) + 0x12) == 2) ||
                 (0 < *(short *)(iVar4 + 0xc6))) {
LAB_004970f5:
                piVar7 = (int *)(*(int *)(unaff_EBP + -0x10) + 0xe064);
                if (*piVar7 == 0) {
                  *piVar7 = 0xb;
                }
                goto LAB_0049712d;
              }
              local_20 = 0;
              iVar4 = FUN_006359f2(iVar4,0,&cXObject::RTTI_Type_Descriptor,
                                   &cXMTObject::RTTI_Type_Descriptor);
              if (iVar4 != 0) {
                if (*(int *)(iVar4 + 400) != 0) {
                  iVar4 = *(int *)(iVar4 + 400);
                }
                for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x18c)) {
                  if (0 < *(short *)(iVar4 + 0xc6)) goto LAB_004970f5;
                }
              }
            }
            local_20 = 0x4970c5;
            FUN_0043f3b9();
          }
          if (((*pcVar2 == *(char *)(unaff_EBP + 8)) && (pcVar2[1] == *(char *)(unaff_EBP + 9))) &&
             (pcVar2[2] == *(char *)(unaff_EBP + 10))) break;
          *(undefined1 *)(unaff_EBP + -4) = 0;
          iVar8 = iVar8 + 1;
        } while (iVar8 < 2);
        goto LAB_00496f15;
      }
    }
    piVar7 = (int *)(*(int *)(unaff_EBP + -0x10) + 0xe064);
    iVar4 = *piVar7;
  }
  if (iVar4 == 0) {
    *piVar7 = 1;
  }
LAB_0049712d:
  uVar5 = 0;
LAB_0049712f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

