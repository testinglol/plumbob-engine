
void FUN_004d39b5(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  int extraout_ECX;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  int unaff_EBP;
  int iVar6;
  int iVar7;
  undefined4 local_50;
  
  FUN_00634c24();
  if (*(char *)(unaff_EBP + 0x28) != '\0') {
    local_50 = 0x4d39d2;
    FUN_004e609e();
    local_50 = 0x4d39d9;
    uVar1 = FUN_004e642d();
    *(undefined1 *)(unaff_EBP + 0x28) = uVar1;
  }
  iVar4 = *(int *)(unaff_EBP + 0xc);
  if ((iVar4 == 0) || (*(char *)(unaff_EBP + 0x24) == '\0')) {
    if (*(int *)(extraout_ECX + 0x11bc) != 0) {
      if (*(char *)(unaff_EBP + 8) == '\0') {
        local_50 = iVar4;
        FUN_005254b4();
      }
      else {
        local_50 = *(undefined4 *)(unaff_EBP + 0x2c);
        FUN_00525256(iVar4,*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                     *(undefined4 *)(unaff_EBP + 0x18),*(undefined4 *)(unaff_EBP + 0x1c),
                     *(undefined4 *)(unaff_EBP + 0x20),*(undefined4 *)(unaff_EBP + 0x28));
      }
    }
  }
  else {
    local_50 = 0x4d39f6;
    FUN_004e609e();
    local_50 = 0x4d39fd;
    cVar2 = FUN_004e6352();
    if (cVar2 == '\0') {
      *(undefined1 *)(unaff_EBP + 0x28) = 0;
      local_50 = 0xfffffffc;
      FUN_0057a7f7(s_UI_error_006c5e80);
    }
    else {
      local_50 = 0;
      FUN_00434d92();
    }
    local_50 = 1;
    local_50 = FUN_00433116(iVar4 + 0xf4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar2 = FUN_00433136();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (cVar2 != '\0') {
      *(undefined1 *)(unaff_EBP + 0x28) = 0;
    }
    if (*(char *)(unaff_EBP + 0x28) != '\0') {
      bVar5 = (byte)DAT_006f0088;
      *(undefined1 *)(unaff_EBP + 8) = *(undefined1 *)(iVar4 + 0xfc);
      uVar1 = *(undefined1 *)(iVar4 + 0xfe);
      *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)(iVar4 + 0xfd);
      *(undefined1 *)(unaff_EBP + 10) = uVar1;
      iVar3 = DAT_006e54d8;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      local_50 = *(undefined4 *)(iVar3 + 0x84);
      FUN_00434ffd();
      *(undefined4 **)(unaff_EBP + 0x24) = &local_50;
      local_50._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 9),*(undefined1 *)(unaff_EBP + 8));
      local_50._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 10),(undefined2)local_50);
      local_50 = CONCAT13(extraout_var,(undefined3)local_50);
      iVar3 = FUN_004796d9(unaff_EBP + 0x24);
      local_50 = CONCAT31((int3)((uint)iVar3 >> 8),*(undefined1 *)(iVar3 + 1));
      FUN_004b3f54(unaff_EBP + 0x20,unaff_EBP + 0xc,unaff_EBP + 8);
      iVar6 = (8 << (bVar5 & 0x1f)) / 2;
      *(int *)(unaff_EBP + 0x24) = iVar6 + *(int *)(unaff_EBP + 0xc);
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + 0xc) - iVar6;
      iVar7 = (0x10 << (bVar5 & 0x1f)) / 2;
      iVar3 = *(int *)(iVar4 + 0x118);
      *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + 0x20) - iVar7;
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + 0x24);
      *(int *)(unaff_EBP + -0x24) = iVar7 + *(int *)(unaff_EBP + 0x20);
      if (*(short *)(iVar3 + 0x14) != 0) {
        local_50 = 0;
        iVar4 = FUN_006359f2(iVar4,0,&cXObject::RTTI_Type_Descriptor,
                             &cXMTObject::RTTI_Type_Descriptor);
        if (*(int *)(iVar4 + 400) != 0) {
          iVar4 = *(int *)(iVar4 + 400);
        }
        while (iVar4 != 0) {
          *(undefined1 *)(unaff_EBP + 0x24) = *(undefined1 *)(iVar4 + 0xfc);
          uVar1 = *(undefined1 *)(iVar4 + 0xfe);
          *(undefined1 *)(unaff_EBP + 0x25) = *(undefined1 *)(iVar4 + 0xfd);
          *(undefined1 *)(unaff_EBP + 0x26) = uVar1;
          iVar3 = DAT_006e54d8;
          *(undefined1 *)(unaff_EBP + -4) = 2;
          local_50 = *(undefined4 *)(iVar3 + 0x84);
          FUN_00434ffd();
          *(undefined4 **)(unaff_EBP + 0x28) = &local_50;
          local_50._0_2_ =
               CONCAT11(*(undefined1 *)(unaff_EBP + 0x25),*(undefined1 *)(unaff_EBP + 0x24));
          local_50._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 0x26),(undefined2)local_50);
          local_50 = CONCAT13(extraout_var_00,(undefined3)local_50);
          iVar3 = FUN_004796d9(unaff_EBP + 0x1c);
          local_50 = CONCAT31((int3)((uint)iVar3 >> 8),*(undefined1 *)(iVar3 + 1));
          FUN_004b3f54(unaff_EBP + 0x20,unaff_EBP + 0xc,unaff_EBP + 0x24);
          *(int *)(unaff_EBP + 0x28) = iVar6 + *(int *)(unaff_EBP + 0xc);
          *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + 0xc) - iVar6;
          *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + 0x28);
          *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x2c);
          *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x28);
          *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x24);
          *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x20);
          local_50 = unaff_EBP + -0x3c;
          *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + 0x20) - iVar7;
          *(int *)(unaff_EBP + -0x44) = iVar7 + *(int *)(unaff_EBP + 0x20);
          FUN_005de8b8(unaff_EBP + -0x4c);
          iVar4 = *(int *)(iVar4 + 0x18c);
          *(undefined1 *)(unaff_EBP + -4) = 1;
        }
      }
      iVar4 = 1 << (3U - (char)DAT_006f0088 & 0x1f);
      *(int *)(unaff_EBP + -0x14) = (int)(200 / (longlong)iVar4);
      *(int *)(unaff_EBP + -0x10) = (int)(300 / (longlong)iVar4);
      if (*(int *)(unaff_EBP + -0x14) < DAT_006f0eb0) {
        *(int *)(unaff_EBP + -0x14) = DAT_006f0eb0;
      }
      if (*(int *)(unaff_EBP + -0x10) < DAT_006f0eb4) {
        *(int *)(unaff_EBP + -0x10) = DAT_006f0eb4;
      }
      iVar7 = (*(int *)(unaff_EBP + -0x28) + *(int *)(unaff_EBP + -0x20)) / 2;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar7;
      iVar6 = (*(int *)(unaff_EBP + -0x24) + *(int *)(unaff_EBP + -0x2c)) / 2;
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + iVar6;
      iVar3 = ((iVar7 - *(int *)(unaff_EBP + -0x28)) - *(int *)(unaff_EBP + -0x10)) +
              *(int *)(unaff_EBP + -0x20);
      iVar4 = (*(int *)(unaff_EBP + -0x14) - iVar6) / -2;
      local_50 = *(undefined4 *)(unaff_EBP + 0x2c);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar3;
      *(int *)(unaff_EBP + -0x18) = iVar7 + iVar3;
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + iVar4;
      *(int *)(unaff_EBP + -0x1c) = iVar6 + iVar4;
      FUN_004b17e5(unaff_EBP + -0x1c,0);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

