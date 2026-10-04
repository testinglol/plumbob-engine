
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0049cf80(void)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  char cVar4;
  undefined1 uVar5;
  char cVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int extraout_ECX;
  int iVar10;
  int extraout_ECX_00;
  uint uVar11;
  undefined1 extraout_var;
  uint extraout_ECX_01;
  uint extraout_ECX_02;
  undefined1 extraout_var_00;
  uint uVar12;
  char cVar13;
  int unaff_EBP;
  undefined4 local_44;
  
  FUN_00634c24();
  iVar8 = *(int *)(unaff_EBP + 0xc);
  local_44 = *(undefined4 *)(unaff_EBP + 0x14);
  iVar10 = *(int *)(unaff_EBP + 8);
  FUN_004a4b03(iVar10,iVar8,*(undefined4 *)(unaff_EBP + 0x10));
  cVar4 = *(char *)(unaff_EBP + 0x10);
  cVar13 = (char)iVar8;
  *(char *)(unaff_EBP + -0x10) = cVar13;
  *(char *)(unaff_EBP + -0xf) = cVar4;
  *(undefined1 *)(unaff_EBP + -0xe) = 1;
  *(undefined4 *)(extraout_ECX + 0x37c) = 0;
  iVar9 = DAT_006e57c0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar9 != 0) {
    bVar1 = *(byte *)(*(int *)(*(int *)(iVar9 + 0xc) + cVar13 * 4) + (int)cVar4);
    if ((bVar1 & 1) == 0) {
      if ((bVar1 & 2) != 0) {
        *(undefined4 *)(extraout_ECX + 0x37c) = 2;
      }
    }
    else {
      *(undefined4 *)(extraout_ECX + 0x37c) = 1;
    }
  }
  *(undefined1 *)(unaff_EBP + 0xe) = 1;
  uVar11 = DAT_006e54d8;
  local_44 = *(undefined4 *)(iVar10 + 0x20);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar3 = *(undefined4 *)(uVar11 + 0x70);
  *(char *)(unaff_EBP + 0xd) = *(char *)(unaff_EBP + 0x10) - (char)*(undefined4 *)(uVar11 + 0x78);
  *(char *)(unaff_EBP + 0xc) = cVar13 - (char)uVar3;
  FUN_0049e134();
  local_44 = *(int *)(unaff_EBP + 0x10);
  *(int *)(extraout_ECX + 900) = iVar8 << 4;
  *(uint *)(extraout_ECX + 0x380) = local_44 << 4;
  uVar11 = DAT_006e54d8;
  _DAT_006ede6c = iVar10;
  if (((((int)cVar13 < *(int *)(DAT_006e54d8 + 0x70) + 1) ||
       (*(int *)(DAT_006e54d8 + 0x74) + -1 < (int)cVar13)) ||
      ((int)(char)local_44 < *(int *)(DAT_006e54d8 + 0x78) + 1)) ||
     (*(int *)(DAT_006e54d8 + 0x7c) + -1 < (int)(char)local_44)) goto LAB_0049d3ae;
  iVar10 = *(int *)(extraout_ECX + 0x37c);
  if (iVar10 == 0) {
    if (*(char *)(extraout_ECX + 0x8d) == '\0') {
LAB_0049d0e6:
      uVar5 = FUN_0049ceba(iVar8);
      *(undefined1 *)(extraout_ECX + 0x361) = uVar5;
      iVar10 = *(int *)(unaff_EBP + 0x10) + 1;
      local_44 = iVar10;
      uVar5 = FUN_0049ceba(iVar8);
      *(undefined1 *)(extraout_ECX + 0x360) = uVar5;
      local_44 = iVar10;
      uVar5 = FUN_0049ceba(iVar8 + 1);
      local_44 = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined1 *)(extraout_ECX + 0x363) = uVar5;
      cVar4 = FUN_0049ceba(iVar8 + 1);
      iVar10 = extraout_ECX_00;
      goto LAB_0049d12a;
    }
    iVar10 = 0;
    if (('\x01' < *(char *)(unaff_EBP + 0xc)) && ('\x01' < *(char *)(unaff_EBP + 0xd))) {
      iVar10 = (int)*(char *)(unaff_EBP + 0xc);
      iVar9 = *(int *)(DAT_006e54d8 + 0x10) + -2;
      if ((iVar10 < iVar9) && (iVar10 = (int)*(char *)(unaff_EBP + 0xd), iVar10 < iVar9))
      goto LAB_0049d0e6;
    }
    uVar5 = (undefined1)((uint)iVar10 >> 0x18);
    *(undefined1 *)(extraout_ECX + 0x361) = 0;
    *(undefined1 *)(extraout_ECX + 0x360) = 0;
    *(undefined1 *)(extraout_ECX + 0x363) = 0;
    *(undefined1 *)(extraout_ECX + 0x362) = 0;
  }
  else {
    cVar4 = (char)iVar10 + -1;
    *(char *)(extraout_ECX + 0x361) = cVar4;
    *(char *)(extraout_ECX + 0x360) = cVar4;
    *(char *)(extraout_ECX + 0x363) = cVar4;
LAB_0049d12a:
    uVar5 = (undefined1)((uint)iVar10 >> 0x18);
    *(char *)(extraout_ECX + 0x362) = cVar4;
  }
  *(undefined4 **)(unaff_EBP + -0x14) = &local_44;
  local_44._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x10),cVar13);
  local_44._0_3_ = CONCAT12(1,(undefined2)local_44);
  local_44 = CONCAT13(uVar5,(uint3)local_44);
  cVar6 = FUN_0048d490();
  cVar4 = *(char *)(unaff_EBP + 0xc);
  cVar2 = *(char *)(unaff_EBP + 0xd);
  *(int *)(extraout_ECX + 0x368) = (int)cVar6;
  uVar11 = (uint)*(ushort *)
                  (*(int *)(*(int *)(*(int *)(extraout_ECX + 0x68) + 0xc) + cVar4 * 4) + cVar2 * 2);
  *(uint *)(extraout_ECX + 0x364) = uVar11;
  if ((*(char *)(extraout_ECX + 0x81) == '\0') || (cVar6 < -0x61)) {
    *(undefined4 *)(extraout_ECX + 0x36c) = 0;
  }
  else {
    *(undefined4 **)(unaff_EBP + -0x14) = &local_44;
    local_44._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x10),cVar13);
    local_44._0_3_ = CONCAT12(1,(undefined2)local_44);
    local_44 = (uint)(uint3)local_44;
    iVar8 = FUN_00486420();
    if (iVar8 == 0) {
      *(undefined4 **)(unaff_EBP + -0x14) = &local_44;
      local_44._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x10),cVar13);
      local_44._0_3_ = CONCAT12(1,(undefined2)local_44);
      local_44 = CONCAT13(extraout_var,(uint3)local_44);
      sVar7 = FUN_00492b33();
      uVar12 = extraout_ECX_02;
      if (sVar7 == 0) {
        uVar12 = 0;
        uVar11 = 0;
        if ((int)(*(byte *)(*(int *)(unaff_EBP + 0x14) + 3) - 4) <=
            (int)(uint)*(byte *)(*(int *)(unaff_EBP + 0x14) + 1)) {
          iVar8 = *(int *)(extraout_ECX + 0x368);
          if (iVar8 < -0x31) {
            *(undefined4 *)(extraout_ECX + 0x36c) = 1;
          }
          else if (iVar8 < 0xf) {
            *(undefined4 *)(extraout_ECX + 0x36c) = 2;
          }
          else if (iVar8 < 0x2f) {
            *(undefined4 *)(extraout_ECX + 0x36c) = 3;
          }
          else {
            *(undefined4 *)(extraout_ECX + 0x36c) = 4;
          }
          goto LAB_0049d251;
        }
      }
    }
    else {
      *(undefined4 **)(unaff_EBP + 0x14) = &local_44;
      local_44._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x10),cVar13);
      local_44._0_3_ = CONCAT12(1,(undefined2)local_44);
      local_44 = CONCAT13(extraout_var,(uint3)local_44);
      FUN_00467768(unaff_EBP + -0x40);
      uVar12 = extraout_ECX_01;
      uVar11 = extraout_ECX_01;
      if ((*(byte *)(unaff_EBP + -0x40) & 0x30) != 0) goto LAB_0049d251;
    }
    *(undefined4 *)(extraout_ECX + 0x36c) = 0;
    uVar11 = uVar12;
  }
LAB_0049d251:
  if (((*(char *)(extraout_ECX + 0x80) == '\0') || (*(char *)(extraout_ECX + 0x82) == '\0')) ||
     (*(int *)(s_Lights_006c6278 + *(int *)(*(int *)(unaff_EBP + 8) + 0x20) * 4 + 4) == 0)) {
    *(undefined4 *)(extraout_ECX + 0x370) = 0;
  }
  else {
    *(undefined4 **)(unaff_EBP + 0x14) = &local_44;
    local_44._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x10),cVar13);
    local_44._3_1_ = (undefined1)(uVar11 >> 0x18);
    local_44._0_3_ = CONCAT12(1,(undefined2)local_44);
    iVar8 = FUN_00486420();
    if (iVar8 == 0) {
      *(undefined4 **)(unaff_EBP + 0x14) = &local_44;
      local_44._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x10),cVar13);
      local_44._0_3_ = CONCAT12(1,(undefined2)local_44);
      local_44 = CONCAT13(extraout_var_00,(uint3)local_44);
      cVar4 = FUN_0047c2df();
      if (cVar4 != '\0') goto LAB_0049d2cc;
      iVar8 = *(int *)(extraout_ECX + 0x368);
      if (iVar8 < *(int *)(extraout_ECX + 0xa0)) {
        iVar10 = *(int *)(extraout_ECX + 0x9c);
        if (iVar10 < iVar8) {
          *(undefined1 *)(extraout_ECX + 0x378) = 0;
          iVar9 = *(int *)(extraout_ECX + 0xa0) - iVar10;
          if (iVar9 < 1) {
            *(undefined4 *)(extraout_ECX + 0x370) = 0;
          }
          else {
            *(int *)(extraout_ECX + 0x370) =
                 ((*(int *)(extraout_ECX + 0xd4) - *(int *)(extraout_ECX + 0xd0)) * (iVar8 - iVar10)
                 ) / iVar9 + *(int *)(extraout_ECX + 0xd0);
          }
        }
        else {
          *(undefined1 *)(extraout_ECX + 0x378) = 1;
          *(undefined4 *)(extraout_ECX + 0x370) = *(undefined4 *)(extraout_ECX + 0xd0);
        }
      }
      else {
        *(undefined1 *)(extraout_ECX + 0x378) = 0;
        *(undefined4 *)(extraout_ECX + 0x370) = *(undefined4 *)(extraout_ECX + 0xd4);
      }
      if (*(int *)(*(int *)(unaff_EBP + 8) + 0x20) == 1) {
        *(int *)(extraout_ECX + 0x370) = *(int *)(extraout_ECX + 0x370) / 4;
      }
    }
    else {
      *(undefined4 **)(unaff_EBP + 8) = &local_44;
      local_44._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 0x10),cVar13);
      local_44._0_3_ = CONCAT12(1,(undefined2)local_44);
      local_44 = CONCAT13(extraout_var_00,(uint3)local_44);
      FUN_00467768(unaff_EBP + -0x40);
      if ((*(byte *)(unaff_EBP + -0x40) & 0x30) == 0) {
LAB_0049d2cc:
        *(undefined4 *)(extraout_ECX + 0x370) = 0;
      }
    }
  }
  uVar11 = 0;
  if (*(int *)(extraout_ECX + 0x370) != 0) {
    uVar12 = *(int *)(extraout_ECX + 0xdc) - *(int *)(extraout_ECX + 0x370);
    uVar11 = *(uint *)(extraout_ECX + 0x364) / uVar12;
    *(uint *)(extraout_ECX + 0x374) = *(uint *)(extraout_ECX + 0x364) % uVar12;
  }
LAB_0049d3ae:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar11;
}

