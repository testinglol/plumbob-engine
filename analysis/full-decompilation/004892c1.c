
undefined4 FUN_004892c1(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  int iVar5;
  char cVar6;
  byte *pbVar7;
  uint uVar8;
  undefined4 uVar9;
  int unaff_EBP;
  undefined4 local_20;
  
  FUN_00634c24();
  puVar4 = *(undefined1 **)(unaff_EBP + 8);
  uVar1 = *puVar4;
  uVar2 = puVar4[1];
  uVar3 = puVar4[2];
  *(undefined1 *)(unaff_EBP + -0x10) = uVar1;
  *(undefined1 *)(unaff_EBP + -0xf) = uVar2;
  *(undefined1 *)(unaff_EBP + -0xe) = uVar3;
  *(undefined1 *)(unaff_EBP + 8) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + 9) = uVar2;
  *(undefined1 *)(unaff_EBP + 10) = uVar3;
  iVar5 = DAT_006e54d8;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  local_20 = -*(int *)(iVar5 + 0x84) & 3;
  FUN_00434ffd();
  if (DAT_006e4a84 == 0) {
    local_20 = unaff_EBP + 8;
    pbVar7 = (byte *)FUN_00489c8e();
    uVar8 = ((byte)~*pbVar7 & 0x20) >> 5;
    *(uint *)(unaff_EBP + -0x14) = uVar8;
    if (uVar8 != 0) goto LAB_0048933d;
  }
  else {
LAB_0048933d:
    local_20 = unaff_EBP + 8;
    cVar6 = FUN_004790e8();
    if (cVar6 == '\0') {
      uVar9 = *(undefined4 *)
               (*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x14) + 0xc) +
                        *(char *)(unaff_EBP + 8) * 4) + *(char *)(unaff_EBP + 9) * 4);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
      cVar6 = (char)uVar9;
      if (((cVar6 == *(char *)(unaff_EBP + -0x12)) && (cVar6 == (char)((uint)uVar9 >> 8))) &&
         (cVar6 == *(char *)(unaff_EBP + -0x11))) {
        *(undefined4 **)(unaff_EBP + -0x14) = &local_20;
        local_20._3_1_ = (char)*(char *)(unaff_EBP + 8) >> 7;
        local_20._0_3_ =
             CONCAT12(uVar3,CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),
                                     *(undefined1 *)(unaff_EBP + -0x10)));
        uVar8 = FUN_004893e4();
        if ((uVar8 & 1) != 0) {
          local_20 = 0;
          FUN_0043f371(*DAT_006e486c,unaff_EBP + 8);
          while (*(int *)(unaff_EBP + -0x1c) != 0) {
            if ((*(byte *)(*(int *)(unaff_EBP + -0x1c) + 0x9e) & 1) == 0) goto LAB_004893d4;
            local_20 = 0x4893ce;
            FUN_0043f3b9();
          }
          uVar9 = 1;
          goto LAB_004893d6;
        }
      }
    }
  }
LAB_004893d4:
  uVar9 = 0;
LAB_004893d6:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar9;
}

