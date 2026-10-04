
void FUN_004880d6(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  int extraout_ECX;
  char cVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  if ((*(char *)(extraout_ECX + 0x28) != '\0') && (*(int *)(extraout_ECX + 0x3c) != 0)) {
    uVar3 = FUN_00492b26();
    *(undefined1 *)(unaff_EBP + -0x14) = 0;
    *(undefined1 *)(unaff_EBP + -0x13) = 0;
    *(undefined1 *)(unaff_EBP + -0x12) = uVar3;
    iVar5 = *(int *)(extraout_ECX + 0x3c);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar4 = *(int *)(iVar5 + 400);
    if (iVar4 != 0) {
      iVar5 = iVar4;
    }
    iVar4 = FUN_006359f2(iVar5,0,&cXMTObject::RTTI_Type_Descriptor,
                         &cXCursorObject::RTTI_Type_Descriptor,0);
    iVar5 = extraout_ECX;
    while (iVar4 != 0) {
      iVar6 = *(int *)(iVar4 + 0x1ac);
      uVar2 = *(undefined4 *)(iVar6 + 0x110);
      cVar7 = (char)(*(int *)(iVar6 + 0xf8) >> 4);
      *(char *)(unaff_EBP + -0x10) = cVar7;
      cVar8 = (char)(*(int *)(iVar6 + 0xf4) >> 4);
      *(char *)(unaff_EBP + -0xf) = cVar8;
      *(char *)(unaff_EBP + -0xe) = (char)uVar2;
      cVar1 = *(char *)(iVar5 + 0x77);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if ((cVar1 != '\0') && (*(char *)(iVar5 + 0x79) != '\0')) {
        if (*(short *)(iVar5 + 0x4c) == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_00492b10(*(short *)(iVar5 + 0x4c));
          cVar8 = *(char *)(unaff_EBP + -0xf);
          cVar7 = *(char *)(unaff_EBP + -0x10);
        }
        if (iVar5 != 0) {
          cVar7 = *(char *)(iVar5 + 0xfc);
          *(char *)(unaff_EBP + -0x10) = cVar7;
          cVar8 = *(char *)(iVar5 + 0xfd);
          *(char *)(unaff_EBP + -0xf) = cVar8;
          *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(iVar5 + 0xfe);
        }
      }
      iVar5 = DAT_006e54dc;
      if ((((cVar7 < '\x01') || (iVar6 = *(int *)(DAT_006e54dc + 0x10) + -1, iVar6 <= cVar7)) ||
          (cVar8 < '\x01')) || (iVar6 <= cVar8)) {
        uVar2 = *(undefined4 *)(iVar4 + 0x110);
        cVar8 = (char)(*(int *)(iVar4 + 0x1b4) >> 4);
        cVar7 = (char)(*(int *)(iVar4 + 0x1b8) >> 4);
        *(char *)(unaff_EBP + -0x10) = cVar7;
        *(char *)(unaff_EBP + -0xf) = cVar8;
        *(char *)(unaff_EBP + -0xe) = (char)uVar2;
      }
      if ((('\0' < cVar7) && (iVar5 = *(int *)(iVar5 + 0x10) + -1, cVar7 < iVar5)) &&
         (('\0' < cVar8 && (cVar8 < iVar5)))) {
        FUN_00434ffd(*(undefined4 *)(DAT_006e54d8 + 0x84));
        if ((*(char *)(unaff_EBP + -0x14) < *(char *)(unaff_EBP + -0x10)) ||
           (*(char *)(unaff_EBP + -0x13) < *(char *)(unaff_EBP + -0xf))) {
          *(char *)(unaff_EBP + -0x14) = *(char *)(unaff_EBP + -0x10);
          *(char *)(unaff_EBP + -0x13) = *(char *)(unaff_EBP + -0xf);
          *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0xe);
        }
      }
      uVar2 = *(undefined4 *)(iVar4 + 0x18c);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      iVar4 = FUN_006359f2(uVar2,0,&cXMTObject::RTTI_Type_Descriptor,
                           &cXCursorObject::RTTI_Type_Descriptor,0);
      iVar5 = *(int *)(unaff_EBP + -0x18);
    }
    if ((((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)*(char *)(unaff_EBP + -0x14)) &&
         ((int)*(char *)(unaff_EBP + -0x14) <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
        (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + -0x13))) &&
       ((int)*(char *)(unaff_EBP + -0x13) <= *(int *)(DAT_006e54d8 + 0x7c) + -1)) {
      FUN_00492dd9(unaff_EBP + -0x14,*(undefined4 *)(unaff_EBP + 0xc));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

