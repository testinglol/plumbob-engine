
void FUN_004632af(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 auStack_74 [5];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  TypeDescriptor *pTStack_54;
  TypeDescriptor *pTStack_50;
  int iStack_4c;
  
  FUN_00634c24();
  iVar3 = DAT_006e54dc;
  iVar4 = *(int *)(extraout_ECX + 400);
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  *(int *)(unaff_EBP + -0x10) = iVar4;
  if (iVar4 == 0) {
    *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  }
  iVar4 = *(int *)(unaff_EBP + -0x10);
  while (iVar4 != 0) {
    iStack_4c = 0;
    pTStack_50 = &cXPortal::RTTI_Type_Descriptor;
    pTStack_54 = &cXMTObject::RTTI_Type_Descriptor;
    uStack_58 = 0;
    uStack_5c = *(undefined4 *)(unaff_EBP + -0x10);
    uStack_60 = 0x4632f8;
    iVar4 = FUN_006359f2();
    if (*(short *)(*(int *)(iVar4 + 0x118) + 0x5c) != 0) {
      iStack_4c = 0x463315;
      iVar5 = FUN_00435968();
      if (iVar5 != 0) {
        cVar1 = *(char *)(iVar4 + 0xfc);
        cVar2 = *(char *)(iVar4 + 0xfd);
        *(char *)(unaff_EBP + -0x14) = cVar1;
        *(char *)(unaff_EBP + -0x13) = cVar2;
        *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(iVar4 + 0xfe);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (((('\0' < cVar1) && (iVar6 = *(int *)(iVar3 + 0x10) + -1, cVar1 < iVar6)) &&
            ('\0' < cVar2)) && (cVar2 < iVar6)) {
          iStack_4c = unaff_EBP + -0x14;
          pTStack_50 = (TypeDescriptor *)(unaff_EBP + -0x48);
          pTStack_54 = (TypeDescriptor *)0x46336c;
          FUN_00479737();
          iVar4 = *(int *)(iVar4 + 0x118);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          pTStack_50 = (TypeDescriptor *)(int)*(short *)(iVar4 + 0x5c);
          pTStack_54 = (TypeDescriptor *)0x463384;
          iStack_4c = iVar5;
          FUN_004633e3();
          *(undefined4 **)(unaff_EBP + -0x1c) = auStack_74;
          puVar7 = (undefined4 *)(unaff_EBP + -0x48);
          puVar8 = auStack_74;
          for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          FUN_00479954(unaff_EBP + -0x14);
          if (*(char *)(unaff_EBP + 8) != '\0') {
            iStack_4c = *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x110);
            pTStack_50 = (TypeDescriptor *)0x4633b3;
            FUN_00540a5b();
            pTStack_50 = (TypeDescriptor *)0x4633ba;
            FUN_00540ecf();
          }
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
    }
    iVar4 = *(int *)(*(int *)(unaff_EBP + -0x10) + 0x18c);
    *(int *)(unaff_EBP + -0x10) = iVar4;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

