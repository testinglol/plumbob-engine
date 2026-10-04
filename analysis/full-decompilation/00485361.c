
bool FUN_00485361(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int extraout_ECX;
  int iVar7;
  int unaff_EBP;
  undefined4 local_48;
  
  FUN_00634c24();
  cVar5 = **(char **)(unaff_EBP + 8);
  cVar1 = **(char **)(unaff_EBP + 0xc);
  iVar6 = CONCAT31((int3)((uint)extraout_ECX >> 8),cVar1);
  if (cVar5 < cVar1) {
    *(int *)(unaff_EBP + -0x20) = (int)cVar5;
    cVar5 = cVar1;
  }
  else {
    iVar6 = (int)cVar1;
    *(int *)(unaff_EBP + -0x20) = iVar6;
  }
  cVar1 = (*(char **)(unaff_EBP + 0xc))[1];
  iVar6 = CONCAT31((int3)((uint)iVar6 >> 8),cVar1);
  *(int *)(unaff_EBP + -0x1c) = (int)cVar5;
  cVar5 = (*(char **)(unaff_EBP + 8))[1];
  if (cVar5 < cVar1) {
    *(int *)(unaff_EBP + -0x2c) = (int)cVar5;
    cVar5 = cVar1;
  }
  else {
    iVar6 = (int)cVar1;
    *(int *)(unaff_EBP + -0x2c) = iVar6;
  }
  uVar2 = *(undefined1 *)(extraout_ECX + 0x4c);
  *(int *)(unaff_EBP + -0x18) = (int)cVar5;
  *(undefined4 **)(unaff_EBP + 8) = &local_48;
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
  uVar3 = *(undefined1 *)(extraout_ECX + 0x4d);
  *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
  local_48._0_2_ = CONCAT11(uVar3,uVar2);
  local_48._3_1_ = (undefined1)((uint)iVar6 >> 0x18);
  local_48._0_3_ = CONCAT12(*(undefined1 *)(extraout_ECX + 0x4e),(undefined2)local_48);
  iVar6 = FUN_004796d9(unaff_EBP + 8);
  uVar2 = *(undefined1 *)(iVar6 + 1);
  iVar6 = *(int *)(unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + 0xb) = 0;
  *(undefined1 *)(unaff_EBP + -0x34) = uVar2;
  *(int *)(unaff_EBP + -0x28) = iVar6;
  if (iVar6 <= *(int *)(unaff_EBP + -0x1c)) {
    do {
      if (*(char *)(unaff_EBP + 0xb) != '\0') goto LAB_004856fe;
      iVar7 = *(int *)(unaff_EBP + -0x2c);
      *(int *)(unaff_EBP + -0x10) = iVar7;
      while ((iVar7 <= *(int *)(unaff_EBP + -0x18) && (*(char *)(unaff_EBP + 0xb) == '\0'))) {
        cVar5 = (char)iVar6;
        *(char *)(unaff_EBP + -0x14) = cVar5;
        *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(unaff_EBP + -0x10);
        *(undefined1 *)(unaff_EBP + -0x12) = 1;
        iVar7 = DAT_006e54d8;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if ((*(int *)(iVar7 + 0x70) + 1 <= (int)cVar5) &&
           ((((int)cVar5 <= *(int *)(iVar7 + 0x74) + -1 &&
             (*(int *)(iVar7 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + -0x10))) &&
            (iVar7 = *(int *)(iVar7 + 0x7c) + -1, *(char *)(unaff_EBP + -0x10) <= iVar7)))) {
          *(undefined4 **)(unaff_EBP + 0xc) = &local_48;
          local_48._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + -0x13),cVar5);
          local_48._3_1_ = (undefined1)((uint)iVar7 >> 0x18);
          local_48._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0x12),(undefined2)local_48);
          iVar7 = FUN_004796d9(unaff_EBP + -0x38);
          cVar5 = *(char *)(iVar7 + 1);
          *(char *)(unaff_EBP + 0xf) = cVar5;
          if (cVar5 != *(char *)(unaff_EBP + -0x34)) {
            local_48 = 0;
            cVar5 = FUN_00491801(unaff_EBP + -0x14);
            if (cVar5 == '\0') {
              *(undefined1 *)(unaff_EBP + 0xb) = 1;
            }
            else {
              if (iVar6 == *(int *)(unaff_EBP + -0x20)) {
                local_48 = *(undefined4 *)(unaff_EBP + -0x10);
                cVar5 = FUN_004852d6(iVar6 + -1);
                if (cVar5 == '\0') {
                  *(undefined1 *)(unaff_EBP + 0xb) = 1;
                }
              }
              if (*(int *)(unaff_EBP + -0x10) == *(int *)(unaff_EBP + -0x2c)) {
                iVar7 = *(int *)(unaff_EBP + -0x10) + -1;
                local_48 = iVar7;
                cVar5 = FUN_004852d6(iVar6);
                if (cVar5 == '\0') {
                  *(undefined1 *)(unaff_EBP + 0xb) = 1;
                }
                if ((iVar6 == *(int *)(unaff_EBP + -0x20)) &&
                   (local_48 = iVar7, cVar5 = FUN_004852d6(iVar6 + -1), cVar5 == '\0')) {
                  *(undefined1 *)(unaff_EBP + 0xb) = 1;
                }
              }
              if ((iVar6 == *(int *)(unaff_EBP + -0x1c)) ||
                 (*(int *)(unaff_EBP + -0x10) == *(int *)(unaff_EBP + -0x18))) {
                local_48 = *(undefined4 *)(unaff_EBP + -0x10);
                cVar5 = FUN_004852d6(iVar6);
                if (cVar5 == '\0') {
                  *(undefined1 *)(unaff_EBP + 0xb) = 1;
                }
              }
              if (*(char *)(unaff_EBP + 0xb) == '\0') {
                if ((iVar6 < *(int *)(unaff_EBP + -0x1c)) &&
                   (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x18))) {
                  *(undefined1 *)(unaff_EBP + -0x30) = *(undefined1 *)(unaff_EBP + -0x14);
                  *(undefined1 *)(unaff_EBP + -0x2f) = *(undefined1 *)(unaff_EBP + -0x13);
                  *(undefined1 *)(unaff_EBP + -0x2e) = *(undefined1 *)(unaff_EBP + -0x12);
                  iVar7 = DAT_006e54d8;
                  *(undefined1 *)(unaff_EBP + -4) = 1;
                  local_48 = -*(int *)(iVar7 + 0x84) & 3;
                  FUN_00434ffd();
                  local_48 = 0;
                  FUN_0043f371(*DAT_006e486c,unaff_EBP + -0x30);
                  while ((iVar7 = *(int *)(unaff_EBP + -0x40), iVar7 != 0 &&
                         (*(char *)(unaff_EBP + 0xb) == '\0'))) {
                    if ((*(short *)(*(int *)(iVar7 + 0x118) + 0x14) != 0) &&
                       ((*(ushort *)(iVar7 + 0x9e) & 0x100) == 0)) {
                      *(int *)(extraout_ECX + 0x30) = *(int *)(extraout_ECX + 0x30) + 5;
                      local_48 = 0;
                      iVar7 = FUN_006359f2(iVar7,0,&cXObject::RTTI_Type_Descriptor,
                                           &cXMTObject::RTTI_Type_Descriptor);
                      if (iVar7 != 0) {
                        if (*(int *)(iVar7 + 400) != 0) {
                          iVar7 = *(int *)(iVar7 + 400);
                        }
                        while (iVar7 != 0) {
                          *(undefined1 *)(unaff_EBP + -0x24) = *(undefined1 *)(iVar7 + 0xfc);
                          *(undefined1 *)(unaff_EBP + -0x23) = *(undefined1 *)(iVar7 + 0xfd);
                          *(undefined1 *)(unaff_EBP + -0x22) = *(undefined1 *)(iVar7 + 0xfe);
                          iVar4 = DAT_006e54d8;
                          *(undefined1 *)(unaff_EBP + -4) = 2;
                          local_48 = *(undefined4 *)(iVar4 + 0x84);
                          FUN_00434ffd();
                          cVar5 = *(char *)(unaff_EBP + -0x24);
                          cVar1 = *(char *)(unaff_EBP + -0x23);
                          if ((int)cVar5 < *(int *)(unaff_EBP + -0x20)) {
LAB_00485666:
                            uVar2 = *(undefined1 *)(unaff_EBP + -0x22);
                            *(undefined4 *)(extraout_ECX + 0x38) = 5;
                            *(char *)(extraout_ECX + 0x34) = cVar5;
                            *(char *)(extraout_ECX + 0x35) = cVar1;
                            *(undefined1 *)(extraout_ECX + 0x36) = uVar2;
                            *(undefined1 *)(unaff_EBP + 0xb) = 1;
                            *(undefined1 *)(unaff_EBP + -4) = 1;
                            break;
                          }
                          if (((*(int *)(unaff_EBP + -0x1c) <= (int)cVar5) ||
                              ((int)cVar1 < *(int *)(unaff_EBP + -0x2c))) ||
                             (*(int *)(unaff_EBP + -0x18) <= (int)cVar1)) {
                            iVar6 = *(int *)(unaff_EBP + -0x28);
                            goto LAB_00485666;
                          }
                          iVar7 = *(int *)(iVar7 + 0x18c);
                          iVar6 = *(int *)(unaff_EBP + -0x28);
                          *(undefined1 *)(unaff_EBP + -4) = 1;
                        }
                      }
                    }
                    local_48 = 0x485689;
                    FUN_0043f3b9();
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 0;
                  if (*(char *)(unaff_EBP + 0xb) != '\0') goto LAB_004856c1;
                }
                local_48 = (uint)*(byte *)(unaff_EBP + 0xf) - (uint)*(byte *)(unaff_EBP + -0x34);
                iVar7 = FUN_00636bef();
                *(int *)(extraout_ECX + 0x30) = *(int *)(extraout_ECX + 0x30) + iVar7 * DAT_006e57d0
                ;
                local_48 = *(undefined4 *)(unaff_EBP + -0x34);
                FUN_004909ca(unaff_EBP + -0x14);
              }
            }
          }
        }
LAB_004856c1:
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        iVar7 = *(int *)(unaff_EBP + -0x10);
      }
      iVar6 = iVar6 + 1;
      *(int *)(unaff_EBP + -0x28) = iVar6;
    } while (iVar6 <= *(int *)(unaff_EBP + -0x1c));
    if (*(char *)(unaff_EBP + 0xb) != '\0') goto LAB_004856fe;
  }
  local_48 = *(undefined4 *)(unaff_EBP + -0x18);
  cVar5 = FUN_00491375(*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x2c),
                       *(undefined4 *)(unaff_EBP + -0x1c));
  if (cVar5 == '\0') {
    *(undefined1 *)(unaff_EBP + 0xb) = 1;
  }
LAB_004856fe:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(char *)(unaff_EBP + 0xb) == '\0';
}

