
uint FUN_00490f92(void)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  int extraout_ECX;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 uVar7;
  uint uVar6;
  int unaff_EBP;
  undefined4 local_28;
  
  FUN_00634c24();
  uVar3 = DAT_006e54d8;
  pcVar1 = *(char **)(unaff_EBP + 8);
  iVar4 = *(int *)(DAT_006e54d8 + 0x70);
  cVar2 = *pcVar1;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  if ((((iVar4 + 1 <= (int)cVar2) && ((int)cVar2 <= *(int *)(uVar3 + 0x74) + -1)) &&
      (*(int *)(uVar3 + 0x78) + 1 <= (int)pcVar1[1])) &&
     (uVar3 = *(int *)(uVar3 + 0x7c) - 1, (int)pcVar1[1] <= (int)uVar3)) {
    local_28 = 1;
    uVar3 = FUN_00491801(pcVar1);
    uVar6 = DAT_006e54d8;
    if ((char)uVar3 != '\0') {
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined1 **)(unaff_EBP + 8) = &DAT_006e57b4;
      uVar7 = extraout_var;
      do {
        cVar2 = *pcVar1;
        cVar5 = pcVar1[1];
        iVar4 = *(int *)(uVar6 + 0x70);
        *(char *)(unaff_EBP + -0xe) = pcVar1[2];
        cVar2 = cVar2 + **(char **)(unaff_EBP + 8);
        cVar5 = cVar5 + (*(char **)(unaff_EBP + 8))[1];
        *(char *)(unaff_EBP + -0x10) = cVar2;
        *(char *)(unaff_EBP + -0xf) = cVar5;
        if (((iVar4 + 1 <= (int)cVar2) && ((int)cVar2 <= *(int *)(uVar6 + 0x74) + -1)) &&
           ((*(int *)(uVar6 + 0x78) + 1 <= (int)cVar5 && ((int)cVar5 <= *(int *)(uVar6 + 0x7c) + -1)
            ))) {
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
          *(undefined4 **)(unaff_EBP + -0x20) = &local_28;
          local_28._3_1_ = (undefined1)((uint3)uVar7 >> 0x10);
          local_28._0_2_ = CONCAT11(cVar5,cVar2);
          local_28 = CONCAT22(CONCAT11(local_28._3_1_,*(undefined1 *)(unaff_EBP + -0xe)),
                              (undefined2)local_28);
          iVar4 = FUN_004796d9(unaff_EBP + -0x24);
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + (uint)*(byte *)(iVar4 + 1);
          uVar6 = DAT_006e54d8;
          uVar7 = extraout_var_00;
        }
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 3;
      } while (*(int *)(unaff_EBP + 8) < 0x6e57c0);
      cVar2 = *pcVar1;
      *(undefined4 **)(unaff_EBP + 8) = &local_28;
      local_28._0_2_ = CONCAT11(pcVar1[1],cVar2);
      local_28._3_1_ = (undefined1)((uint3)uVar7 >> 0x10);
      local_28._0_3_ = CONCAT12(pcVar1[2],(undefined2)local_28);
      iVar4 = FUN_004796d9(unaff_EBP + 8);
      uVar6 = (uint)*(byte *)(iVar4 + 1);
      uVar3 = (int)(*(int *)(unaff_EBP + -0x14) / *(int *)(unaff_EBP + -0x18) + uVar6) / 2 +
              *(int *)(unaff_EBP + 0xc);
      if (0x40 < (int)uVar3) {
        uVar3 = 0x40;
      }
      if ((int)uVar3 < 0) {
        uVar3 = 0;
      }
      if (uVar6 == uVar3) {
        uVar3 = CONCAT31((int3)(uVar3 >> 8),1);
      }
      else {
        local_28 = uVar3 - uVar6;
        uVar3 = FUN_00491113(pcVar1);
      }
      goto LAB_00491102;
    }
  }
  *(undefined4 *)(extraout_ECX + 0x38) = 1;
  *(char *)(extraout_ECX + 0x34) = *pcVar1;
  *(char *)(extraout_ECX + 0x35) = pcVar1[1];
  *(char *)(extraout_ECX + 0x36) = pcVar1[2];
  uVar3 = uVar3 & 0xffffff00;
LAB_00491102:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

